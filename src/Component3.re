let str = ReasonReact.string;

type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */

let calcs = Calc.main();
let get = (p1, p2) => {
  let v = List.nth(List.nth(calcs.dtable, p1+1), p2+1);
  str(Calc.f2s(v^))
};

  let make = (_children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {count: 0, show: true},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: ! state.show})
    },

  render: _self => {
    /* let message = */
    /*   "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)"; */
    <div>
      /* <button onClick={_event => self.send(Click)}> */
      /*   {ReasonReact.string(message)} */
      /* </button> */
      
      /* <button onClick={_event => self.send(Toggle)}> */
      /*   {ReasonReact.string("Toggle greeting")} */
      /* </button> */
      

          <table>
            <thead>
              <tr>
                <th> {str("who \\ whom")} </th>
                <th> {str("Irene")} </th>
                <th> {str("Andrey")} </th>
                <th> {str("Nicola")} </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <th> {str("to Irene")} </th>
                <td> {get(0,0)} </td>
                <td> {get(1,0)} </td>
                <td> {get(2,0)} </td>
              </tr>
              <tr>
                <th> {str("to Andrey")} </th>
                <td> {get(0,1)} </td>
                <td> {get(1,1)} </td>
                <td> {get(2,1)} </td>
              </tr>
              <tr>
                <th> {str("to Nicola")} </th>
                <td> {get(0,2)} </td>
                <td> {get(1,2)} </td>
                <td> {get(2,2)} </td>
              </tr>
              </tbody>
            </table>




    </div>;
  },
};
