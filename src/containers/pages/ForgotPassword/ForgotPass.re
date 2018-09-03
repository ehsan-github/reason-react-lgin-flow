[%bs.raw {|require('./ForgotPass.css')|}];
type state = {email: string};

type action =
  | ChangeEmail(string);

let reducer = (action, _state) =>
  switch action {
  | ChangeEmail(email) => ReasonReact.Update({email: email})
  };

let component = ReasonReact.reducerComponent("ForgotPass");

let make = (_children) => {
  let submit = (state) => Js.log(state);
  {
    ...component,
    initialState: () => {email: ""},
    reducer,
    render: ({state, send}) =>
      <div className="isoForgotPassPage">
        <div className="isoFormContentWrapper">
          <div className="isoFormContent">
            <div className="isoLogoWrapper">
              <Router.Link route=Signup>
                /* <IntlMessages id="page.forgetPassTitle" /> */
                 (ReasonReact.string("IMMIWORK")) </Router.Link>
            </div>
            <div className="isoFormHeadText">
              <h3> (ReasonReact.string("Forgot Password?")) </h3>
              /* <IntlMessages id="page.forgetPassSubTitle" /> */
              <p>
                (
                  ReasonReact.string(
                    "Enter your email and we send you a reset link."
                  )
                )
              </p>
            </div>
            /* <IntlMessages id="page.forgetPassDescription" /> */
            <div className="isoInputWrapper">
              <form
                onSubmit=(
                  (event) => {
                    ReactEvent.Synthetic.preventDefault(event);
                    submit(state)
                  }
                )>
                <div className="isoForgotPassForm">
                  <div className="isoInputWrapper">
                    <Antd.Input
                      size="large"
                      placeholder="Email"
                      value=state.email
                      onChange=(
                        (event) =>
                          send(ChangeEmail(ReactEvent.Form.target(event)##value))
                      )
                    />
                  </div>
                  <div className="isoInputWrapper">
                    <Antd.Button type_="primary" htmlType="submit">
                      /* <IntlMessages id="page.sendRequest" /> */
                       (ReasonReact.string("Send request")) </Antd.Button>
                  </div>
                </div>
              </form>
            </div>
          </div>
        </div>
      </div>
  }
};