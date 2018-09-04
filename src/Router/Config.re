  type route =
    | Signup
    | Signin
    | ForgotPass
    | Profile
    | NotFound;

let routeToString =
  fun
  | Signin => "/signin"
  | Signup => "/signup"
  | ForgotPass => "/forgotpassword"
  | Profile => "/profile"
  | NotFound => "/notfound";

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
    switch url.path {
    | ["signin"]
    | [] => Signin
    | ["signup"] => Signup
    | ["forgotpassword"] => ForgotPass
    | ["profile"] => Profile
    | _ => NotFound
    };