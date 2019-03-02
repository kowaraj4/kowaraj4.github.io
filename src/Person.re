type t =
  | Nobody
  | Irene
  | Andrey
  | Nicola;

let name = (p : t) => {
  switch (p){
  | Nobody => "nobody"
  | Andrey => "Andrey"
  | Irene => "Irene"
  | Nicola => "Nicola"
  }
};

let names = (ps : list(t)) => { 
   String.concat("", List.map(p=>name(p), ps));
};
              



  
