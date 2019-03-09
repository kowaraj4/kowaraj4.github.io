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
  
let get_people = (b) => {
  switch( List.find( (i) => is_in(b, i) , occupantsTimeline) ) {
  | x => List.filter( p=>p!=Person.Nobody, x.people)
  | exception Not_found => [Person.Nobody]
  };
};

let get_people_all = () => {
  [Person.Andrey, Person.Irene, Person.Nicola]
};

/* let find_debt_record = (dlist, p, pp) => { */
/*   switch( List.find( (d : Debt.t) => d.who === p , dlist) ) { */
/*   | x => x */
/*   | exception Not_found => {whom: p, who:  */
/*   }; */
/* }; */


let process_bill = (list_of_debts, b :Bill.t) => {
  let i = b.paidby;
  let pp = get_people(b);
  let a = b.value /. float_of_int(List.length(pp));
  let dlist = List.map(p => {
    let tr : Transaction.t = {from: p, to_: i, value: a, date: "", description: string_of_float(b.value) ++ " paid @"++b.date ++ " ("++Expense.str(b.type_)++") "};
    tr },
                       List.filter(p=>p!=b.paidby, pp));
  List.append(list_of_debts, dlist)
};

let print_transactions = tlist => {
  Js.log("\n Transactions:\n")
  Js.log(""++ String.concat("\n", List.map( (tr :Transaction.t) =>
                                             Person.name(tr.from) ++ " -> " ++
                                             Person.name(tr.to_) ++ " " ++ 
                                             string_of_float(tr.value) ++ " " ++ 
                                             " FOR: " ++ tr.description, tlist)));
};

let transactions : list(Transaction.t) = [
  {date: "2017-11-11", value: 61.78,  description: "for edf", from: Irene,  to_: Andrey},
  {date: "2017-11-11", value: 49.47,  description: "for edf", from: Nicola, to_: Irene },
  {date: "2017-11-11", value: 58.11,  description: "for edf", from: Nicola, to_: Andrey},
  {date: "2018-09-13", value: 220.72, description: "for edf", from: Irene,  to_: Andrey},
  {date: "2018-09-13", value: 341.50, description: "for edf", from: Nicola, to_: Andrey}
];

let debts = (pp, trs) => {
[
  [ 1.1 , 1.2 , 1.3],
  [ 2.1 , 2.2 , 2.4],
  [ 3.1 , 3.2 , 3.3]
]
};

let print_debts = dtable =>  {
  List.map(drow => {  List.map(d => Js.log(string_of_float(d)), drow) }, dtable)
};

let main = () => {
  let tlist = List.fold_left( process_bill, [] , bills);
  print_transactions(tlist);
  let ds = debts(get_people_all(), tlist);
  print_debts(ds);
  ""
};



  
