type t = {
  date: string,
  value: float,
  description: string,
  from: Person.t,
  to_: Person.t,
};

let data : list(t) = [
  //test data
  //{date: "2017-11-11", value: 300,  description: "for edf", from: Irene,  to_: Andrey},

  //real data
  /* {date: "2017-11-11", value: 61.78,  description: "for edf", from: Irene,  to_: Andrey}, */
  /* {date: "2017-11-11", value: 49.47,  description: "for edf", from: Nicola, to_: Irene }, */
  /* {date: "2017-11-11", value: 58.11,  description: "for edf", from: Nicola, to_: Andrey}, */
  /* {date: "2018-09-13", value: 220.72, description: "for edf", from: Irene,  to_: Andrey}, */
  /* {date: "2018-09-13", value: 341.50, description: "for edf", from: Nicola, to_: Andrey} */
];

let str = (x) => {
  "Transaction: " ++ Person.name(x.from) ++ " -> " ++
    Person.name(x.to_) ++ " " ++ 
    Util.f2s(x.value) ++ " " ++ 
    " FOR: " ++ x.description;
};

let print = (x) => {
  Js.log(str(x));
};

let print_list = (l) => {
  List.map( (tr :t) => print(tr), l);
};

let dump = () => print_list(data);
