type t = {
  date: string,
  value: float,
  description: string,
  from: Person.t,
  to_: Person.t,
};

let data : list(t) = [
  {date: "2017-11-11", value: 61.78,  description: "for edf", from: Irene,  to_: Andrey},
  {date: "2017-11-11", value: 49.47,  description: "for edf", from: Nicola, to_: Irene },
  {date: "2017-11-11", value: 58.11,  description: "for edf", from: Nicola, to_: Andrey},
  {date: "2018-09-13", value: 220.72, description: "for edf", from: Irene,  to_: Andrey},
  {date: "2018-09-13", value: 341.50, description: "for edf", from: Nicola, to_: Andrey}
];
  
let print_l = (l) => {
  Js.log("\n Transactions:\n")
  Js.log(""++ String.concat("\n", List.map( (tr :t) =>
                                             Person.name(tr.from) ++ " -> " ++
                                             Person.name(tr.to_) ++ " " ++ 
                                             Util.f2s(tr.value) ++ " " ++ 
                                             " FOR: " ++ tr.description, data)));
};

let print = () => print_l(data);
