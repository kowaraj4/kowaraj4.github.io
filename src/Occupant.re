type t = {
  since: string,
  till:  string,
  people: list(Person.t) //NB: ordered by roomNumbers
};

let data : list(t) = [
  {since: "2016-10-23", till: "2016-10-31", people: [Nobody, Irene, Nobody ]},
  {since: "2016-11-01", till: "2017-07-31", people: [Nobody, Irene, Andrey ]},
  {since: "2017-08-01", till: Util.now_ts,       people: [Nicola, Irene, Andrey ]},
];

let print = () => {
  List.map( (x : t) => Js.log("Interval: [" ++ x.since ++ " - " ++ x.till ++ "]"), data) |> ignore;
  };
