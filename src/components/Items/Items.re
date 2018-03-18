type item = {
  id: string,
  text: string,
  completed: bool,
  created: string,
};

module ListItem = {
  let component = ReasonReact.statelessComponent("ListItem");
  let make = (~item: item, ~onDelete, ~onComplete, _children) => {
    ...component,
    render: _self =>
      <div className="item" onClick=onComplete>
        <div
          className="text"
          style=(
            ReactDOMRe.Style.make(
              ~textDecoration=item.completed ? "line-through" : "",
              (),
            )
          )>
          (Util.str(item.text))
        </div>
        <div onClick=onDelete className="delete"> <Icon /> </div>
        <span className="date"> (Util.str(item.created)) </span>
      </div>,
  };
};

module ItemList = {
  let component = ReasonReact.statelessComponent("ItemList");
  let make = (~list, ~onDelete, ~onComplete, _) => {
    ...component,
    render: _self =>
      <div className="list">
        (
          Util.arr(
            Array.of_list(
              List.map(
                (item: item) =>
                  <ListItem
                    onDelete=(onDelete(item))
                    onComplete=(onComplete(item))
                    item
                    key=item.id
                  />,
                list,
              ),
            ),
          )
        )
      </div>,
  };
};