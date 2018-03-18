[%bs.raw {|require("./App.css")|}];

open Items;

/*
   Import two simple externals from moment
   An absgtract type is used for momentNow
 */
type t;

[@bs.module] external momentNow : unit => t = "moment";

[@bs.send.pipe: t] external format : string => string = "";

/*
   Imperative/mutable counter for ids.
 */
let prevId = ref("0");

let newItem = text : item => {
  prevId := int_of_string(prevId^) + 1 |> string_of_int;
  let created = momentNow() |> format("h:mm");
  {id: prevId^, text, completed: false, created};
};

type state = {items: list(item)};

type action =
  | AddItem(string)
  | DeleteItem(string)
  | CompleteItem(string);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {items: []},
  reducer: (action, {items}) =>
    switch (action) {
    | AddItem(text) =>
      ReasonReact.Update({items: [newItem(text), ...items]})
    | DeleteItem(id) =>
      let remaining = List.filter(item => item.id !== id, items);
      ReasonReact.Update({items: remaining});
    | CompleteItem(id) =>
      let newItems =
        List.map(
          item =>
            item.id === id ? {...item, completed: ! item.completed} : item,
          items,
        );
      ReasonReact.Update({items: newItems});
    },
  render: ({state: {items}, send}) =>
    <div>
      <div className="header" />
      <div className="input-container">
        <Input.Input onSubmit=(text => send(AddItem(text))) />
      </div>
      <div className="container">
        <ItemList
          list=items
          onDelete=((item, _) => send(DeleteItem(item.id)))
          onComplete=((item, _) => send(CompleteItem(item.id)))
        />
      </div>
    </div>,
};