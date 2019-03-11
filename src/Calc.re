let is_in = (b : Bill.t, i : Occupant.t) => {
  let a = compare(i.since, b.since) === -1 || compare(i.since, b.since) === 0;
  let b = compare(i.till,  b.till) === 1 || compare(i.till, b.till) === 0;
  a && b;
};
  
let get_people = (b) => {
  switch( List.find( (i) => is_in(b, i) , Occupant.data) ) {
  | x => List.filter( p=>p!=Person.Nobody, x.people)
  | exception Not_found => [Person.Nobody]
  };
};

let get_people_all = () => {
  [Person.Nobody, Person.Irene, Person.Andrey, Person.Nicola]
};

let process_bill = (trlist_acc, b :Bill.t) => {
  let i = b.paidby;
  let pp = get_people(b);
  let a = b.value /. float_of_int(List.length(pp));
  let trlist =
    List.map(p => {
    let tr : Transaction.t = {from: i,
                              to_: p,
                              value: a,
                              date: "to be paid",
                              description: string_of_float(b.value) ++ " paid @"++b.date ++ " ("++Expense.str(b.type_)++") "};
    tr },
             List.filter(p=>p!=b.paidby, pp));
  List.append(trlist_acc, trlist);
};

let process_tr = (acc, t : Transaction.t) => {
  let x = List.nth(List.nth(acc, Person.id(t.from)), Person.id(t.to_));
  x := x^ +. t.value;
  acc;
};

let cell = (t, i, j) => {
  List.nth(List.nth(t, j), i);
};

let cancel_out = (dt, dt_ret) => {
  let r = Util.range(1, 3);
  List.map(i=> List.map(j=> {
    let xij = List.nth(List.nth(dt,j),i);
    let xji = List.nth(List.nth(dt,i),j);
    List.nth(List.nth(dt_ret,j),i) := xij^ -. xji^;

  } , r), r) |> ignore;
  dt_ret;
};

let debts = (pp, trlist) => {
  let dtable_init = List.map(_p1 => {List.map(_p2 => ref(0.0), pp)}, pp);
  let dtable = List.fold_left( process_tr, dtable_init, trlist);
  let dtable_init2 = List.map(_p1 => {List.map(_p2 => ref(0.0), pp)}, pp);
  let dtable_pass2 = cancel_out(dtable, dtable_init2);
  let dtable_init3 = List.map(_p1 => {List.map(_p2 => ref(0.0), pp)}, pp);
  let dtable_pass3 = List.fold_left( process_tr, dtable_init3, Transaction.data);
  let ds : Debt.t = {
    dtable: dtable,
    dtable_cout: dtable_pass2,
    dtable_final: dtable_pass3,
    people: pp,
    repr:  String.concat("\n", List.map( drow => {  " " ++ String.concat("   ", List.map(d => Util.f2s(d^), drow)) }, dtable_init)),
    repr2: String.concat("\n", List.map( drow => {  " " ++ String.concat("   ", List.map(d => Util.f2s(d^), drow)) }, dtable_pass2)),
  };
  ds;
};

let main = () => {
  Bill.print();
  Occupant.print();

  let tlist = List.fold_left( process_bill, [] , Bill.data);
  Transaction.print_l(tlist);
  Transaction.print();

  let ds : Debt.t = debts(get_people_all(), tlist);
  Js.log(ds.repr);
  Js.log(ds.repr2);
  ds;
};



  
