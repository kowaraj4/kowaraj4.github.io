type t = {
  dtable : list(list(ref(float))),
  dtable_cout : list(list(ref(float))),
  dtable_final : list(list(ref(float))),
  people : list(Person.t),
  /* repr   : string, */
  /* repr2   : string, */
};

let make = (pp) => {
  List.map(_p1 => {List.map(_p2 => ref(0.0), pp)}, pp);
};

let str = (ds) => {
  "\t\t\t\t" ++ String.concat("\t",  List.map( p => Person.name(p), ds.people)) ++ "\n" ++ 
  String.concat("\n", List.map( x => {  "to " ++ Person.name(snd(x)) ++ "\t:\t" ++ String.concat(" \t\t", List.map(d => Util.f2s(d^), fst(x))) }, List.combine(ds.dtable,ds.people)));
//    ++ "\n-\n" ++
//    String.concat("\n", List.map( drow => {  " " ++ String.concat("   ", List.map(d => Util.f2s(d^), drow)) }, ds.dtable_final));
};

let print = (dt) => {
  Js.log( str(dt));
};
