type t = 
  | Internet
  | EdF;

let str = (e : t) => {
  switch (e){
  | Internet => "internet"
  | EdF => "edf"
  }
};
