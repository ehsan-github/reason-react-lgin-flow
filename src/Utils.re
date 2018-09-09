let str = ReasonReact.string;
let scomp = ReasonReact.statelessComponent;
let rcomp = ReasonReact.reducerComponent;

[@bs.val]
external localSetItem: (string, string) => unit = "localStorage.setItem";

[@bs.val]
external localGetItem: (string) => string = "localStorage.getItem";