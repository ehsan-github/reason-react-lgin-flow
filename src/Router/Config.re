  type route =
    | Signup
    | Signin
    | NotFound;

let routeToString =
  fun
  | Signin => "/signin"
  | Signup => "/signup"
  | NotFound => "/notfound";

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
    switch url.path {
    | ["signin"]
    | [] => Signin
    | ["signup"] => Signup
    | _ => NotFound
    };

let urlToRoute: ReasonReact.Router.url => route =
  url =>
    switch url.path {
    | ["signin"] => Signin
    | ["signup"] => Signup
    };