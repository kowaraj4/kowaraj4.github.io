let getSomething = () => {
  string_of_int(44)
  };

type personType =
  | Nobody
  | Irene
  | Andrey
  | Nicola;

type expenseType = 
  | Internet
  | EdF;

type occupantsType = {
  since: string,
  till:  string,
  people: list(personType) //NB: ordered by roomNumbers
};

let occupantsTimeline = [
  {since: "2016-10-23", till: "2016-10-31", people: [Nobody, Irene, Nobody ]},
  {since: "2016-11-01", till: "2017-07-31", people: [Nobody, Irene, Andrey ]},
  {since: "2017-08-01", till: "now",        people: [Nicola, Irene, Andrey ]},
];

type bill = {
  since: string,
  till: string,
  date: string,
  value: float,
  type_: expenseType,
  paidby: personType,
};


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

let time0 = "2016-10-23";
let time1 = "2017-07-31";

/* let is_in = (_dates, _interval) => { */
/*   true; */
/* }; */

/* let is_in = (b, i) => { */
/*   let a = compare(i.since, b.since) === 1; */
/*   let b = compare(i.till,  b.till) === -1; */
/*   a && b; */
/* }; */

  
let i = {since: "2016-10-23", till: "2016-10-31", people: [Nobody, Irene, Nobody ]};

let b = {date: "2017-05-28", value: 247.65, type_: EdF,      paidby: Andrey, since: "2016-11-01", till: "2017-04-30"};

/* let is_in = (b, i) => {  */
/*   print_endline(i.since); */
/* };  */

/* compare(i.since, b.since); */
//is_in(b, i);

//is_in(List.nth(bills,0), List.nth(occupantsTimeline,0)); 

/* let get_interval = (b) => { */
/*   switch( List.find( (i) => is_in(b, i) , occupantsTimeline) ) { */
/*     | x => print_endline(x.since) */
/*     | exception Not_found => print_endline("No such item") */
/*     }; */
/* }; */

/* get_interval(List.nth(bills,0)); */



  
type transactionType = {
  date: string,
  value: float,
  description: string,
  from: personType,
  to_: personType,
};

let transactions = [
  {date: "2017-11-11", value: 61.78,  description: "for edf", from: Irene,  to_: Andrey},
  {date: "2017-11-11", value: 49.47,  description: "for edf", from: Nicola, to_: Irene },
  {date: "2017-11-11", value: 58.11,  description: "for edf", from: Nicola, to_: Andrey},
  {date: "2018-09-13", value: 220.72, description: "for edf", from: Irene,  to_: Andrey},
  {date: "2018-09-13", value: 341.50, description: "for edf", from: Nicola, to_: Andrey}
];


  
