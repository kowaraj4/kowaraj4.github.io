type t = {
  ts: (string, string),
  people: list(Person.t) //NB: ordered by roomNumbers
};

let data : list(t) = [

  //test data, set #1
  /* { ts: ("2016-10-23", "2019-10-31"), people: [Irene, Andrey, Nicola]}, */

  //real data
  {ts: ("2016-10-23", "2016-10-31"), people: [Nobody, Irene, Nobody ]},
  {ts: ("2016-11-01", "2017-07-31"), people: [Nobody, Irene, Andrey ]},
  {ts: ("2017-08-01", Util.now_ts),  people: [Nicola, Irene, Andrey ]},
];

let str = (x) => {
  "Interval: [" ++ fst(x.ts) ++ " - " ++ snd(x.ts) ++ "]" ++ " >> people: " ++ Person.names(x.people)
};

let print = (x) => {
  Js.log( str(x) );
};


let dump = () => {  Js.log("Occupants Timeline: ");  List.map(x=>print(x), data) |> ignore;  Js.log(" ");};


let get_people_all = () => {
  [Person.Nobody, Person.Irene, Person.Andrey, Person.Nicola]
};
