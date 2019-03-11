type t = {
  ts: (string, string),
  date: string,
  value: float,
  type_: Expense.t,
  paidby: Person.t,
};

let data : list(t) = [

  //test data
  {date: "2017-10-10", value: 300., type_: EdF,      paidby: Andrey, ts: ("2017-11-01", "2017-12-01")},

  //real data
  /* {date: "2017-05-28", value: 247.65, type_: EdF,      paidby: Andrey, since: "2016-11-01", till: "2017-04-30"}, */
  /* {date: "2017-07-30", value: 64.6,   type_: Internet, paidby: Irene,  since: "2017-06-01", till: "2017-07-31"}, */
  /* {date: "2017-07-30", value: 172.24, type_: EdF,      paidby: Andrey, since: "2017-05-01", till: "2017-07-31"}, */
  /* {date: "2017-09-30", value: 150.00, type_: Internet, paidby: Irene,  since: "2017-08-01", till: "2017-10-31"}, */
  /* {date: "2017-09-26", value: 174.33, type_: EdF,      paidby: Andrey, since: "2017-08-01", till: "2017-08-31"}, */
  /* {date: "2017-11-26", value: 330.55, type_: EdF,      paidby: Andrey, since: "2017-09-01", till: "2017-10-31"}, */
  /* {date: "2018-02-06", value: 109.21, type_: EdF,      paidby: Andrey, since: "2017-11-01", till: "2018-01-31"}, */
  /* {date: "2018-03-27", value: 391.25, type_: EdF,      paidby: Andrey, since: "2018-02-01", till: "2018-02-28"}, */
  /* {date: "2018-05-27", value: 193.47, type_: EdF,      paidby: Andrey, since: "2018-03-01", till: "2018-04-30"}, */
  /* {date: "2018-09-01", value: 362.78, type_: Internet, paidby: Irene,  since: "2017-11-01", till: "2018-09-30"}, */
];

let str = (x) => {
  "Bill: " ++ Util.f2s(x.value) ++ " @" ++ x.date ++ " (" ++ Expense.str(x.type_) ++ ")" ++ " - " ++ Person.name(x.paidby) 
};

let print = (x) => {
  Js.log( str(x) );
};

let dump = () => {
  List.map(x=>print(x), data) |> ignore;
};
