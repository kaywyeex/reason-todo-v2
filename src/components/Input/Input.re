let valFromEvt = evt => (
                          evt
                          |> ReactEventRe.Form.target
                          |> ReactDOMRe.domElementToObj
                        )##value;

module Input = {
  type state = string;
  let component = ReasonReact.reducerComponent("Input");
  let make = (~onSubmit, _) => {
    ...component,
    initialState: () => "",
    reducer: (newText, _text) => ReasonReact.Update(newText),
    render: ({state: text, send}) =>
      <input
        _type="text"
        placeholder="What to do...?"
        value=text
        onChange=(e => send(valFromEvt(e)))
        onKeyDown=(
          evt =>
            if (ReactEventRe.Keyboard.key(evt) === "Enter") {
              onSubmit(text);
              send("");
            }
        )
      />,
  };
};