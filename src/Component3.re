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
  let v = List.nth(List.nth(calcs.dtable1, p1+1), p2+1);
  str(Util.f2s(v^))
};

let get_cout = (p1, p2) => {
  let v = List.nth(List.nth(calcs.dtable2, p1+1), p2+1);
  str(Util.f2s(v^))
};

/* let get_final = (p1, p2) => { */
/*   let v = List.nth(List.nth(calcs.dtable_final, p1+1), p2+1); */
/*   str(Util.f2s(v^)) */
/* }; */

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
      
      <p> {str("Original table of debts");} </p>

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

            <p> {str("Cancelled out table");} </p>
            
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
                <td> {get_cout(0,0)} </td>
                <td> {get_cout(1,0)} </td>
                <td> {get_cout(2,0)} </td>
              </tr>
              <tr>
                <th> {str("to Andrey")} </th>
                <td> {get_cout(0,1)} </td>
                <td> {get_cout(1,1)} </td>
                <td> {get_cout(2,1)} </td>
              </tr>
              <tr>
                <th> {str("to Nicola")} </th>
                <td> {get_cout(0,2)} </td>
                <td> {get_cout(1,2)} </td>
                <td> {get_cout(2,2)} </td>
              </tr>
              </tbody>
            </table>

            <p> {str("Transaction have been taken into account");} </p>
            
            /* <table> */
            /*   <thead> */
            /*     <tr> */
            /*     <th> {str("who \\ whom")} </th> */
            /*     <th> {str("Irene")} </th> */
            /*     <th> {str("Andrey")} </th> */
            /*     <th> {str("Nicola")} </th> */
            /*   </tr> */
            /* </thead> */
            /* <tbody> */
            /*   <tr> */
            /*     <th> {str("to Irene")} </th> */
            /*     <td> {get_final(0,0)} </td> */
            /*     <td> {get_final(1,0)} </td> */
            /*     <td> {get_final(2,0)} </td> */
            /*   </tr> */
            /*   <tr> */
            /*     <th> {str("to Andrey")} </th> */
            /*     <td> {get_final(0,1)} </td> */
            /*     <td> {get_final(1,1)} </td> */
            /*     <td> {get_final(2,1)} </td> */
            /*   </tr> */
            /*   <tr> */
            /*     <th> {str("to Nicola")} </th> */
            /*     <td> {get_final(0,2)} </td> */
            /*     <td> {get_final(1,2)} </td> */
            /*     <td> {get_final(2,2)} </td> */
            /*   </tr> */
            /*   </tbody> */
            /* </table> */




    </div>;
  },
};
