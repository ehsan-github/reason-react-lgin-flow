type route =
  | Signup
  | Signin
  | ForgotPass
  | ResetPass(string)
  | EmailVerified(string)
  | GoogleLogin(string)
  | Profile
  | Dashboard(list(string))
  | NotFound;

let routeToString =
  fun
  | Signin => "/signin"
  | Signup => "/signup"
  | ForgotPass => "/forgotpassword"
  | ResetPass(code) => "/resetpassword" ++ code
  | Profile => "/profile"
  | Dashboard(remainRoutes) => "/dashboard/"++Js.Array.joinWith("/", Array.of_list(remainRoutes))
  | NotFound => "/notfound"
  | _ => "/notfound";

let mapUrlToRoute = (url: ReasonReact.Router.url) => {
  switch (url.path) {
  | ["signin"] => Signin
  | ["signup"] => Signup
  | ["emailverif", code] => EmailVerified(code)
  | [] | ["dashboard"] => Dashboard([])
  | ["dashboard", ...etc] => Dashboard(etc)
  | ["google", "authorize"] => GoogleLogin(url.search)
  | ["forgotpassword"] => ForgotPass
  | ["resetpassword", code] => ResetPass(code)
  | ["profile"] => Profile
  | _ => NotFound
  };
};