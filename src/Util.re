let now_ts = "2019-02-25";

let f2s = x => {
  let k = 10.;
  let xint = int_of_float(x *. k);
  string_of_float(float_of_int(xint) /. k);
};

let range = (i, j) => { 
  let rec aux = (n, acc) => {
    if (n < i) {
      acc;
    } else {
      aux( n-1, List.append([n], acc) );
    }
  };
  aux(j, []);
};

