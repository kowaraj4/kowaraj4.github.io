let now_ts = "2019-02-25";

let occupantsTimeline : list(Occupant.t) = [
  {since: "2016-10-23", till: "2016-10-31", people: [Nobody, Irene, Nobody ]},
  {since: "2016-11-01", till: "2017-07-31", people: [Nobody, Irene, Andrey ]},
  {since: "2017-08-01", till: now_ts,       people: [Nicola, Irene, Andrey ]},
];
List.map( (x : Occupant.t) => Js.log("Interval: [" ++ x.since ++ " - " ++ x.till ++ "]"), occupantsTimeline);

let bills : list(Bill.t) = [
  {date: "2017-05-28", value: 247.65, type_: EdF,      paidby: Andrey, since: "2016-11-01", till: "2017-04-30"},
  {date: "2017-07-30", value: 64.6,   type_: Internet, paidby: Irene,  since: "2017-06-01", till: "2017-07-31"},
  {date: "2017-07-30", value: 172.24, type_: EdF,      paidby: Andrey, since: "2017-05-01", till: "2017-07-31"},
  {date: "2017-09-30", value: 150.00, type_: Internet, paidby: Irene,  since: "2017-08-01", till: "2017-10-31"},
  {date: "2017-09-26", value: 174.33, type_: EdF,      paidby: Andrey, since: "2017-08-01", till: "2017-08-31"},
  {date: "2017-11-26", value: 330.55, type_: EdF,      paidby: Andrey, since: "2017-09-01", till: "2017-10-31"},
  {date: "2018-02-06", value: 109.21, type_: EdF,      paidby: Andrey, since: "2017-11-01", till: "2018-01-31"},
  {date: "2018-03-27", value: 391.25, type_: EdF,      paidby: Andrey, since: "2018-02-01", till: "2018-02-28"},
  {date: "2018-05-27", value: 193.47, type_: EdF,      paidby: Andrey, since: "2018-03-01", till: "2018-04-30"},
  {date: "2018-09-01", value: 362.78, type_: Internet, paidby: Irene,  since: "2017-11-01", till: "2018-09-30"},
];
List.map((x : Bill.t) => Js.log("Bill @" ++ x.date ++ " === " ++ string_of_float(x.value)), bills);

let is_in = (b : Bill.t, i : Occupant.t) => {
  let a = compare(i.since, b.since) === -1 || compare(i.since, b.since) === 0;
  let b = compare(i.till,  b.till) === 1 || compare(i.till, b.till) === 0;
  a && b;
};
  
let get_people = b => {
  switch( List.find( (i) => is_in(b, i) , occupantsTimeline) ) {
  | x => x.people
  | exception Not_found => [Person.Nobody]
  };
};

let process_bill = (sum, b) => {
//  Js.log("b.since = "++ b.since);
//  Js.log("sum = "++ String.concat("_____", List.map(i=>i.whom ++ string_of_float(i.amount) ++ "\n", sum)));
  let d : Debt.t = {who: Person.names(get_people(b)), whom: Person.name(b.paidby), amount: b.value};
  [d, ...sum];
};

let print_debts = ds => {
  Js.log("debts: \n"++ String.concat("\n", List.map((i:Debt.t)=>i.who ++ " " ++ i.whom ++ " " ++ string_of_float(i.amount), ds)));
};

let main = () => {
  let debts = List.fold_left( process_bill, [] , bills);
  print_debts(debts);
};

let transactions : list(Transaction.t) = [
  {date: "2017-11-11", value: 61.78,  description: "for edf", from: Irene,  to_: Andrey},
  {date: "2017-11-11", value: 49.47,  description: "for edf", from: Nicola, to_: Irene },
  {date: "2017-11-11", value: 58.11,  description: "for edf", from: Nicola, to_: Andrey},
  {date: "2018-09-13", value: 220.72, description: "for edf", from: Irene,  to_: Andrey},
  {date: "2018-09-13", value: 341.50, description: "for edf", from: Nicola, to_: Andrey}
];


  
