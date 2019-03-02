let getSomething = () => {
  string_of_int(44)
  };

type expenseType = 
  | Internet
  | EdF;

type billType = {
  since: string,
  till: string,
  date: string,
  value: float,
  type_: expenseType,
  paidby: Person.t,
};

type occupantsType = {
  since: string,
  till:  string,
  people: list(Person.t) //NB: ordered by roomNumbers
};

let now_ts = "2019-02-25";
let occupantsTimeline = [
  {since: "2016-10-23", till: "2016-10-31", people: [Nobody, Irene, Nobody ]},
  {since: "2016-11-01", till: "2017-07-31", people: [Nobody, Irene, Andrey ]},
  {since: "2017-08-01", till: now_ts,       people: [Nicola, Irene, Andrey ]},
];
List.map(x => Js.log("Interval: [" ++ x.since ++ " - " ++ x.till ++ "]"), occupantsTimeline);

let b_in1 = {date: "2017-05-27", value: 247.65, type_: EdF,      paidby: Andrey, since: "2016-10-24", till: "2016-10-30"};
let b_in2 = {date: "2017-05-28", value: 247.65, type_: EdF,      paidby: Andrey, since: "2016-11-02", till: "2017-07-31"};
let b_in3 = {date: "2017-05-29", value: 247.65, type_: EdF,      paidby: Andrey, since: "2017-08-01", till: "2019-02-01"};

let bills = [
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
List.map(x => Js.log("Bill @" ++ x.date ++ " === " ++ string_of_float(x.value)), bills);

let is_in = (b : billType, i : occupantsType) => {
  /* Js.log("since = " ++ i.since ++ ", << " ++ b.since); */
  /* Js.log("till  = " ++ i.till  ++ ", << " ++ b.till); */
  let a = compare(i.since, b.since) === -1 || compare(i.since, b.since) === 0;
  let b = compare(i.till,  b.till) === 1 || compare(i.till, b.till) === 0;
  /* Js.log("a = " ++ string_of_bool(a)); */
  /* Js.log("b = " ++ string_of_bool(b)); */
  a && b;
};
  
let found_interval = x => b =>  {
  Js.log("Interval found: [" ++ x.since ++ " - " ++ x.till ++ "] for bill: " ++ b.date);
  Js.log("people = " ++ Person.names(x.people));
};

let get_interval = (b) => {
  switch( List.find( (i) => is_in(b, i) , occupantsTimeline) ) {
  | x => found_interval(x, b)
  | exception Not_found => print_endline("No such item")
  };
};

let main = () => {
  List.map(b => get_interval(b), bills) |>ignore;
  "ok";
};
  
type transactionType = {
  date: string,
  value: float,
  description: string,
  from: Person.t,
  to_: Person.t,
};

let transactions = [
  {date: "2017-11-11", value: 61.78,  description: "for edf", from: Irene,  to_: Andrey},
  {date: "2017-11-11", value: 49.47,  description: "for edf", from: Nicola, to_: Irene },
  {date: "2017-11-11", value: 58.11,  description: "for edf", from: Nicola, to_: Andrey},
  {date: "2018-09-13", value: 220.72, description: "for edf", from: Irene,  to_: Andrey},
  {date: "2018-09-13", value: 341.50, description: "for edf", from: Nicola, to_: Andrey}
];


  
