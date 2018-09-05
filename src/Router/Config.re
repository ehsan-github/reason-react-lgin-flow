type route =
  | Signup
  | Signin
  | ForgotPass
  | ResetPass(string)
  | EmailVerified
  | GoogleLogin(string)
  | Profile
  | Dashboard
  | InDashboard(list(string))
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
  | InDashboard(remainRoutes) => "/dashboard"++Js.Array.joinWith("/ ", Array.of_list(remainRoutes))
  | NotFound => "/notfound"
  | _ => "/notfound";

let mapUrlToRoute = (url: ReasonReact.Router.url) => {
  switch (url.path) {
  | ["signin"]
  | [] => Signin
  | ["signup"] => Signup
  | ["dashboard"] => Dashboard
  | ["dashboard", ...etc] => InDashboard(etc)
  | ["google", "authorize"] => GoogleLogin(url.search)
  | ["forgotpassword"] => ForgotPass
  | ["resetpassword", code] => ResetPass(code)
  | ["profile"] => Profile
  | _ => NotFound
  };
};