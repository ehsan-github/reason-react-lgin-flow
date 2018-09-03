module WithRouter = {
  type state = {route: Config.route };
  type action =
    | ChangeRoute(Config.route);
  let reducer = (action, _state) =>
    switch action {
    | ChangeRoute(route) => ReasonReact.Update({route: route})
    };
 
  let component = ReasonReact.reducerComponent("WithRouter");
  let make = (children) => {
    ...component,
    reducer,
    initialState: () => {
      route: ReasonReact.Router.dangerouslyGetInitialUrl() |> Config.mapUrlToRoute
    },
    didMount: (self) => {
      let watcherID =
        ReasonReact.Router.watchUrl(
          (url) => {
            Js.log(url.path);
            self.send(ChangeRoute(url |> Config.mapUrlToRoute))
          }
        );
      self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID))
    },
    render: ({state}) => children(~currentRoute=state.route)
  };
};

module Link = {
  let component = ReasonReact.statelessComponent("Link");
  let make = (~route, ~className="", children) => {
    ...component,
    render: (self) => {
      let href = Config.routeToString(route);
      <a className href onClick={self.handle(
              (event, _self) => {
                ReactEventRe.Mouse.preventDefault(event);
                ReasonReact.Router.push(href)
              }
            )}>
        ...children
        </a>
    }
  };
};