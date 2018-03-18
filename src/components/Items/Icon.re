type icon;

[@bs.module]
external reactClass : ReasonReact.reactClass =
  "@fortawesome/react-fontawesome";

[@bs.module "@fortawesome/fontawesome-free-solid"]
external trash : icon = "faTrash";

let component = ReasonReact.statelessComponent("Icon");

let make = _children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props={"icon": trash}, Js.null);