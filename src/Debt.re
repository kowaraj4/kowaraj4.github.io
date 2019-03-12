type t = {
  dtable1 : list(list(ref(float))),
  dtable2 : list(list(ref(float))),
  /* dtable3 : list(list(ref(float))), */
  /* dtable4 : list(list(float)), */
  people : list(Person.t),
  /* repr   : string, */
  /* repr2   : string, */
};


let make = (n) => {
  let r = Util.range(1,n);
  List.map(_x => {List.map(_y => 0.0, r)}, r);
};

let make_ref = (n) => {
  let r = Util.range(1,n);
  List.map(_x => {List.map(_y => ref(0.0), r)}, r);
};

let makeij = (n) => {
  let r = Util.range(1,n);
  List.map(i => {List.map(j => float_of_int(i*10 + j), r)}, r);
};

let makeij_ref = (n) => {
  let r = Util.range(1,n);
  List.map(i => {List.map(j => ref(float_of_int(i*10 + j)), r)}, r);
};

/*
   clone     : return a ref as a copy of a ref
   refy      : return a ref-copy of a non-ref
   unref     : return a non-ref as a copy of a ref
 */

let clone = (dsrc) => {
  List.map(dlist => { List.map(y => {let x = ref(y^); x;}, dlist) }, dsrc);
};

let unref = (dsrc) => {
  List.map(dlist => { List.map(d => d^, dlist)} , dsrc);
};

let refy = (dsrc) => {
  List.map(dlist => { List.map(y => {let x = ref(y); x;}, dlist) }, dsrc);
};


let str_x = (ds, ds_field) => {
  "\tto: \t" ++ String.concat("\t",  List.map( p => Person.name(p), ds.people)) ++ "\n" ++ 
    String.concat("\n", List.map( x => {  "" ++ Person.name(snd(x)) ++ "\t:\t" ++ String.concat(" \t\t", List.map(d => Util.f2s(d^), fst(x))) }, List.combine(ds_field,ds.people)))
};

let str = (ds) => {  str_x(ds, ds.dtable1)  ++ "\n\n" ++
                     str_x(ds, ds.dtable2)  //++ "\n\n" ++ 
                     /* str_x(ds, ds.dtable3)  ++ "\n\n" ++ */
                     /* str_x(ds, refy(ds.dtable4)) */
};

let print = (dt) => {
  Js.log( str(dt));
};
