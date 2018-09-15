[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo : string = "./logo.svg";

type loggedIn =
| True
| False
| Unknown

type state = {
  isLoggedIn: loggedIn
};

type action =
  | Login
  | Logout;

let reducer =  (action, _state) =>
    switch (action) {
    | Login => ReasonReact.Update({isLoggedIn: True})
    | Logout => ReasonReact.Update({isLoggedIn: False});
    }

let initialState = () => {isLoggedIn: Unknown};

let component = Utils.rcomp("App");


module LoginQ = [%graphql
  {|
  query loginUserQ($email: String!, $password: String!) {
      loginUserQuery(email: $email, password: $password) {
          access_token
      }
  }
|}
];

module LoginQuery = ReasonApollo.CreateQuery(LoginQ)

let make = (_children) => {
  ...component,
  initialState,
  reducer,
  render: ({state, send}) =>
    <ReasonApollo.Provider client=GqlClient.instance>
      <Router.WithRouter>
        ...(
             (~currentRoute) =>
               switch (state.isLoggedIn, currentRoute) {
               | (_, Signin) => <Signin loginAct={_e => send(Login)}/>
               | (_, Signup) => <Signup />
               | (_, ForgotPass) => <ForgotPass />
               | (_, ResetPass(code)) => <ResetPass code />
               | (_, EmailVerified(code)) => <EmailVerified code/>
               | (_, GoogleLogin(query)) => <GoogleLogin query />
               | (_, NotFound) => <div> (ReasonReact.string("Not Found")) </div>
               | (False, _) => {
                 ReasonReact.Router.push("/signin");
                 <Signin loginAct={_e => send(Login)}/>
               }
               | (True, Dashboard(tailRoutes)) => <ImmiApp logout={_e => send(Logout)} tailRoutes/>
               | (Unknown, Dashboard(tailRoutes)) => {
                 let loginQuery = LoginQ.make(
                   ~email=Utils.localGetItem("email"),
                   ~password=Utils.localGetItem("password"), ());
                 <LoginQuery variables=loginQuery##variables>
                 ...{
           ({result}) =>
             switch (result) {
             | Loading => <div> {ReasonReact.string("Loading")} </div>
             | Error(error) =>{
                 ReasonReact.Router.push("/signin");
             <Signin loginAct={_e => send(Login)} /> ;
                   /* <ImmiApp logout={_e => send(Logout)} tailRoutes/> */
             } 
             | Data(response) => {
               send(Login)
                 Utils.localSetItem("access_token", response##loginUserQuery##access_token);
                   <ImmiApp logout={_e => send(Logout)} tailRoutes/>
               }
             }
                 }
                 </LoginQuery>
               }
               }
           )
      </Router.WithRouter>
    </ReasonApollo.Provider>
};