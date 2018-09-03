  type route =
    | Signup
    | Signin
    | ForgotPass
    | NotFound;

let routeToString =
  fun
  | Signin => "/signin"
  | Signup => "/signup"
  | ForgotPass => "/forgotpassword"
  | NotFound => "/notfound";

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
    switch url.path {
    | ["signin"]
    | [] => Signin
    | ["signup"] => Signup
    | ["forgotpassword"] => ForgotPass
    | _ => NotFound
    };

let urlToRoute: ReasonReact.Router.url => route =
  url =>
    switch url.path {
    | ["signin"] => Signin
    | ["signup"] => Signup
    | ["forgotpassword"] => ForgotPass
    };