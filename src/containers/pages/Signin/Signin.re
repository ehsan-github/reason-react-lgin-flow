[%bs.raw {|require('./Signin.css')|}];

type state = {
  email: string,
  password: string,
  rememberMe: bool,
};

type valueName = 
| Email 
| Password;

type action =
  | Change(valueName, string)
  | ChangeRemeber;

let component = ReasonReact.reducerComponent("Signin");

let make = _children => {
  let submit = state => Js.log(state);
  {
    ...component,
    initialState: () => {email: "", password: "", rememberMe: false},
    reducer: (action, state) =>
      switch (action) {
      | Change(name, text) =>
        switch (name) {
        | Email => ReasonReact.Update({...state, email: text})
        | Password => ReasonReact.Update({...state, password: text})
        }
      | ChangeRemeber =>
        ReasonReact.Update({...state, rememberMe: !state.rememberMe})
      },
    render: ({state, send}) =>
      <div className="isoSignInPage">
        <div className="isoLoginContentWrapper">
          <div className="isoLoginContent">
            <div className="isoLogoWrapper">
              <a href="/"> {ReasonReact.string("IMMIWORK")} </a>
            </div>
            <div className="isoSignInForm">
              <form
                onSubmit={
                  event => {
                    ReactEvent.Synthetic.preventDefault(event);
                    submit(state);
                  }
                }>
                <div className="isoInputWrapper">
                  <Antd.Input
                    size="large"
                    placeholder="Email"
                    value={state.email}
                    onChange={
                      event =>
                        send(
                          Change(
                            Email,
                            ReactEvent.Form.target(event)##value
                          )
                        )
                    }
                  />
                </div>
                <div className="isoInputWrapper">
                  <Antd.Input
                    size="large"
                    type_="password"
                    placeholder="Password"
                    value={state.password}
                    onChange={
                      event =>
                        send(
                          Change(
                            Password,
                            ReactEvent.Form.target(event)##value
                          )
                        )
                    }
                  />
                </div>
                <div className="isoInputWrapper isoLeftRightComponent">
                  <Antd.Checkbox
                    checked={state.rememberMe}
                    onChange={_e => send(ChangeRemeber)}>
                    {ReasonReact.string("Remember me")}
                  </Antd.Checkbox>
                  <div>
                    <a className="isoForgotPass">
                      {ReasonReact.string("Forgot password")}
                    </a>
                  </div>
                </div>
                <div className="isoInputWrapper isoOtherLogin">
                  <Antd.Button
                    type_="primary"
                    htmlType="submit"
                    className="isoLoginButton">
                    {ReasonReact.string("Sign in")}
                  </Antd.Button>
                  <div className="social">
                    <span> {ReasonReact.string("or")} </span>
                  </div>
                  <a
                    href="https://accounts.google.com/o/oauth2/auth?client_id=959585273066-in3mrv049rm7gp1eec79j8ogtsoirmhv.apps.googleusercontent.com&redirect_uri=http://dev.immiwork.com/google/authorize&scope=openid+profile+email&response_type=code">
                    <Antd.Button
                      type_="primary btnGooglePlus"
                      className="isoLoginButton btnGooglePlus">
                      {ReasonReact.string("Sign in with Google")}
                    </Antd.Button>
                  </a>
                </div>
              </form>
              <div className="isoCenterComponent isoHelperWrapper">
                <Router.Link route=Signup>
                  {ReasonReact.string("Dont have an account? Create one.")}
                </Router.Link>
              </div>
            </div>
          </div>
        </div>
      </div>,
  };
};