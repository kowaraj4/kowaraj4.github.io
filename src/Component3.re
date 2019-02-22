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

  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div>
      <button onClick={_event => self.send(Click)}>
        {ReasonReact.string(message)}
      </button>
      
      <button onClick={_event => self.send(Toggle)}>
        {ReasonReact.string("Toggle greeting")}
      </button>
      
      <p>
          {self.state.show ? ReasonReact.string("constant greeting") : ReasonReact.null;}
      </p>

      <p>
          {str("RESULT: " ++ Calc.getSomething());}
      </p>


    </div>;
  },
};
