type t = {
  since: string,
  till:  string,
  people: list(Person.t) //NB: ordered by roomNumbers
};
