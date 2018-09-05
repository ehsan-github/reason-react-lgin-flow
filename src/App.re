[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <ReasonApollo.Provider client=GqlClient.instance>
      <Router.WithRouter>
        ...(
             (~currentRoute) =>
               switch currentRoute {
               | Signin => <Signin />
               | Signup => <Signup />
               | ForgotPass => <ForgotPass />
               | ResetPass(code) => <ResetPass code />
               | EmailVerified => <EmailVerified />
               | GoogleLogin(query) => <GoogleLogin query />
               | Profile => <Profile />
               | Dashboard => <ImmiApp />
               | NotFound => <div> (ReasonReact.string("Not Found")) </div>
               }
           )
      </Router.WithRouter>
    </ReasonApollo.Provider>
};