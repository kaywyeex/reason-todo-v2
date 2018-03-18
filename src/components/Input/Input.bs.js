// Generated by BUCKLESCRIPT VERSION 2.2.2, PLEASE EDIT WITH CARE

import * as Block from "../../../node_modules/bs-platform/lib/es6/block.js";
import * as Curry from "../../../node_modules/bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as ReasonReact from "../../../node_modules/reason-react/src/ReasonReact.js";

function valFromEvt(evt) {
  return evt.target.value;
}

var component = ReasonReact.reducerComponent("Input");

function make(onSubmit, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function (param) {
      var send = param[/* send */4];
      var text = param[/* state */2];
      return React.createElement("input", {
                  placeholder: "What to do...?",
                  type: "text",
                  value: text,
                  onKeyDown: (function (evt) {
                      if (evt.key === "Enter") {
                        Curry._1(onSubmit, text);
                        return Curry._1(send, "");
                      } else {
                        return 0;
                      }
                    }),
                  onChange: (function (e) {
                      return Curry._1(send, e.target.value);
                    })
                });
    });
  newrecord[/* initialState */10] = (function () {
      return "";
    });
  newrecord[/* reducer */12] = (function (newText, _) {
      return /* Update */Block.__(0, [newText]);
    });
  return newrecord;
}

var Input = /* module */[
  /* component */component,
  /* make */make
];

export {
  valFromEvt ,
  Input ,
  
}
/* component Not a pure module */
