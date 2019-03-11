let get_people = (b : Bill.t) => {
  switch( List.find( (i : Occupant.t) => Util.is_in(b.ts, i.ts) , Occupant.data) ) {
  | x => List.filter( p=>p!=Person.Nobody, x.people)
  | exception Not_found => [Person.Nobody]
  };
};

let process_bill = (trlist_acc, b :Bill.t) => {
  Bill.print(b);
  let i = b.paidby;
  let pp = get_people(b);
  let a = b.value /. float_of_int(List.length(pp));
  let pps = List.filter(p=>p!=b.paidby, pp);
  let trlist =  List.map(p => {  let tr : Transaction.t =
                                 {from: i,
                                  to_: p,
                                  value: a,
                                  date: "to be paid",
                                  description: string_of_float(b.value) ++ " paid @"++b.date ++ " ("++Expense.str(b.type_)++") "};
                                 tr },
                         pps);

  Transaction.print_list(trlist);
  List.append(trlist_acc, trlist);
};

let process_tr = (acc, t : Transaction.t) => {
  let x = List.nth(List.nth(acc, Person.id(t.from)), Person.id(t.to_));
  x := x^ +. t.value;
  acc;
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
  let dtable_init = Debt.make(pp);
  let dtable_init2 = Debt.make(pp);
  let dtable_init3 = Debt.make(pp);

  let dtable = List.fold_left( process_tr, dtable_init, trlist);
  
  let dtable_pass2 = cancel_out(dtable, dtable_init2);
  let dtable_pass3 = List.fold_left( process_tr, dtable_init3, Transaction.data);
  let ds : Debt.t = {
    dtable: dtable,
    dtable_cout: dtable_pass2,
    dtable_final: dtable_pass3,
    people: pp,
    /* repr:  Debt.str(dtable_init), */
    /* repr2: Debt.str(dtable_pass2), */
    //repr:  String.concat("\n", List.map( drow => {  " " ++ String.concat("   ", List.map(d => Util.f2s(d^), drow)) }, dtable_init)),
    //repr2: String.concat("\n", List.map( drow => {  " " ++ String.concat("   ", List.map(d => Util.f2s(d^), drow)) }, dtable_pass2)),
  };
  ds;
};

let main = () => {
  //Bill.dump();
  //Occupant.print();

  let tlist = List.fold_left( process_bill, [] , Bill.data);

  Transaction.print_list(tlist);

  let ds : Debt.t = debts(Occupant.get_people_all(), tlist);
  
  Debt.print(ds);
  ds;
};



  
