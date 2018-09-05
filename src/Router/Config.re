type route =
  | Signup
  | Signin
  | ForgotPass
  | ResetPass(string)
  | EmailVerified
  | Profile
  | Dashboard
  | NotFound;

let routeToString =
  fun
  | Signin => "/signin"
  | Signup => "/signup"
  | ForgotPass => "/forgotpassword"
  | ResetPass(code) => "/resetpassword" ++ code
  | EmailVerified => "/emailverif"
  | Profile => "/profile"
  | Dashboard => "/dashboard"
  | NotFound => "/notfound";

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | ["signin"]
  | [] => Signin
  | ["signup"] => Signup
  | ["dashboard"] => Dashboard
  | ["forgotpassword"] => ForgotPass
  | ["resetpassword", code] => ResetPass(code)
  | ["profile"] => Profile
  | _ => NotFound
  };