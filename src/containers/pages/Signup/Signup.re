[%bs.raw {|require('./Signup.css')|}];

type validateStatus =
  | Error
  | Success;

type input = {
  value: string,
  hasFeedback: bool,
  hasError: bool,
  validateStatus,
  errorMessage: string,
};

type state = {
  loading: bool,
  type_: input,
  first_name: input,
  last_name: input,
  email: input,
  password: input,
  password_repeat: input,
};

type action =
  | Change(string, string)
  | ChangeRemeber;

let component = ReasonReact.reducerComponent("Signup");

let make = _children => {
  /* let submit = state => Js.log(state); */
  ...component,
  initialState: () => {
    loading: false,
    type_: {
      value: "applicant",
      hasFeedback: false,
      hasError: false,
      validateStatus: Error,
      errorMessage: "",
    },
    first_name: {
      value: "",
      hasFeedback: false,
      hasError: true,
      validateStatus: Error,
      errorMessage: "",
    },
    last_name: {
      value: "",
      hasFeedback: false,
      hasError: true,
      validateStatus: Error,
      errorMessage: "",
    },
    email: {
      value: "",
      hasFeedback: true,
      hasError: true,
      validateStatus: Success,
      errorMessage: "",
    },
    password: {
      value: "",
      hasFeedback: false,
      hasError: true,
      validateStatus: Error,
      errorMessage: "",
    },
    password_repeat: {
      value: "",
      hasFeedback: false,
      hasError: true,
      validateStatus: Error,
      errorMessage: "",
    },
  },
  reducer: (action, state) =>
    switch (action) {
    | Change(name, text) =>
      switch (name) {
      | "type_" =>
        ReasonReact.Update({
          ...state,
          type_: {
            ...state.type_,
            value: text,
          },
        })
      | "first_name" =>
        ReasonReact.Update({
          ...state,
          first_name: {
            ...state.first_name,
            value: text,
          },
        })
      | "last_name" =>
        ReasonReact.Update({
          ...state,
          last_name: {
            ...state.last_name,
            value: text,
          },
        })
      | "email" =>
        ReasonReact.Update({
          ...state,
          email: {
            ...state.email,
            value: text,
          },
        })
      | "password" =>
        ReasonReact.Update({
          ...state,
          password: {
            ...state.password,
            value: text,
          },
        })
      | "password_repeat" =>
        ReasonReact.Update({
          ...state,
          password_repeat: {
            ...state.password_repeat,
            value: text,
          },
        })
      }
    | ChangeRemeber => ReasonReact.Update(state)
    },
  render: ({state, send}) =>
    <div className="isoSignUpPage">
      <div className="isoSignUpContentWrapper">
        <div className="isoSignUpContent">
          <div className="isoLogoWrapper">
            /* <Link to="/dashboard"> */
             <a href="/"> {ReasonReact.string("IMMIWORK")} </a> </div>
          /* </Link> */
          <div className="isoSignUpForm">
            <form
              onSubmit={
                event =>
                  ReactEvent.Synthetic.preventDefault(
                    event,
                    /* submit(state); */
                  )
              }>
              /* <Antd.InputGroup style={{ marginBottom: '15px' }} compact> */

                <Antd.Radio.Group
                  size="large"
                  style={ReactDOMRe.Style.make(~marginBottom="15px", ())}
                  value={state.type_.value}
                  onChange={
                    event =>
                      send(
                        Change(
                          "type_",
                          ReactEvent.Form.target(event)##value,
                        ),
                      )
                  }>
                  <Antd.Radio.Button value="applicant">
                    {ReasonReact.string("Applicant")}
                  </Antd.Radio.Button>
                  <Antd.Radio.Button value="lawyer">
                    {ReasonReact.string("Lawyer")}
                  </Antd.Radio.Button>
                  <Antd.Radio.Button value="translator">
                    {ReasonReact.string("Translator")}
                  </Antd.Radio.Button>
                </Antd.Radio.Group>
                /* </Antd.InputGroup> */
                <div className="isoSignUpForm">
                  <div>
                    <Antd.Row>
                      <Antd.Col
                        span=12
                        style={ReactDOMRe.Style.make(~paddingRight="5px", ())}>
                        <Antd.Form.Item
                          hasFeedback={state.first_name.hasFeedback}
                          validateStatus={
                            state.first_name.validateStatus == Success ?
                              "success" : "error"
                          }
                          help={
                            state.first_name.validateStatus === Error ?
                              state.first_name.errorMessage : ""
                          }>
                          <Antd.Input
                            value={state.first_name.value}
                            size="large"
                            placeholder="First name"
                            onChange={
                              event =>
                                send(
                                  Change(
                                    "first_name",
                                    ReactEvent.Form.target(event)##value,
                                  ),
                                )
                            }
                          />
                        </Antd.Form.Item>
                      </Antd.Col>
                      <Antd.Col span="12">
                        <Antd.Form.Item
                          hasFeedback={state.last_name.hasFeedback}
                          validateStatus={
                            state.last_name.validateStatus == Success ?
                              "success" : "error"
                          }
                          help={
                            state.last_name.validateStatus === Error ?
                              state.last_name.errorMessage : ""
                          }>
                          <Antd.Input
                            value={state.last_name.value}
                            size="large"
                            placeholder="Last name"
                            onChange={
                              event =>
                                send(
                                  Change(
                                    "last_name",
                                    ReactEvent.Form.target(event)##value,
                                  ),
                                )
                            }
                          />
                        </Antd.Form.Item>
                      </Antd.Col>
                    </Antd.Row>
                  </div>
                  <Antd.Form.Item
                    hasFeedback={state.email.hasFeedback}
                    validateStatus={
                      state.email.validateStatus == Success ?
                        "success" : "error"
                    }
                    help={
                      state.email.validateStatus === Error ?
                        state.email.errorMessage : ""
                    }>
                    <Antd.Input
                      value={state.email.value}
                      size="large"
                      placeholder="Email"
                      onChange={
                        event =>
                          send(
                            Change(
                              "email",
                              ReactEvent.Form.target(event)##value,
                            ),
                          )
                      }
                    />
                  </Antd.Form.Item>
                  <div>
                    <Antd.Col
                      span=12
                      style={ReactDOMRe.Style.make(~paddingRight="5px", ())}>
                      <Antd.Form.Item
                        hasFeedback={state.password.hasFeedback}
                        validateStatus={
                          state.password.validateStatus == Success ?
                            "success" : "error"
                        }
                        help={
                          state.password.validateStatus === Error ?
                            "Should be at least 8 characters" : ""
                        }>
                        <Antd.Input
                          value={state.password.value}
                          size="large"
                          type_="password"
                          placeholder="Password"
                          onChange={
                            event =>
                              send(
                                Change(
                                  "password",
                                  ReactEvent.Form.target(event)##value,
                                ),
                              )
                          }
                        />
                      </Antd.Form.Item>
                    </Antd.Col>
                    <Antd.Col span=12>
                      <Antd.Form.Item
                        hasFeedback={state.password_repeat.hasFeedback}
                        validateStatus={
                          state.password_repeat.validateStatus == Success ?
                            "success" : "error"
                        }
                        help={
                          state.password_repeat.validateStatus === Error ?
                            "Doesn't match password" : ""
                        }>
                        <Antd.Input
                          value={state.password_repeat.value}
                          size="large"
                          type_="password"
                          placeholder="Confirm Password"
                          onChange={
                            event =>
                              send(
                                Change(
                                  "password_repeat",
                                  ReactEvent.Form.target(event)##value,
                                ),
                              )
                          }
                        />
                      </Antd.Form.Item>
                    </Antd.Col>
                  </div>
                  <div
                    style={
                      ReactDOMRe.Style.make(
                        ~marginBottom="19px",
                        ~textAlign="center",
                        ~fontSize="12px",
                        (),
                      )
                    }>
                    {ReasonReact.string("By using Immiwork you agree to the")}
                    /* <Link to="/terms" target="_blink"> */
                    <a href=""> {ReasonReact.string("Terms of Service ")} </a>
                  </div>
                  /* </Link>. */
                  <div className="isoOtherLogin">
                    <div className="isoInputWrapper">
                      <Antd.Button
                        type_="primary"
                        htmlType="submit"
                        loading={state.loading}>
                        /* <IntlMessages id="page.signUpButton" /> */
                         {ReasonReact.string("Sign Up")} </Antd.Button>
                    </div>
                    <div className="social">
                      <span> {ReasonReact.string("or")} </span>
                    </div>
                    <a
                      href="https://accounts.google.com/o/oauth2/auth?client_id=959585273066-in3mrv049rm7gp1eec79j8ogtsoirmhv.apps.googleusercontent.com&redirect_uri=http://dev.immiwork.com/google/authorize&scope=openid+profile+email&response_type=code">
                      <Antd.Button type_="primary btnGooglePlus">
                        /* <IntlMessages id="page.signUpGooglePlus" /> */

                          {ReasonReact.string("Sign up with Google")}
                        </Antd.Button>
                    </a>
                  </div>
                  <div
                    className="isoInputWrapper isoCenterComponent isoHelperWrapper">
                    /* <Link to="/signin"> */
                    /* <IntlMessages id="page.signUpAlreadyAccount" /> */
                     {ReasonReact.string("Have Acount? Sign in.")} </div>
                </div>
              </form>
          </div>
        </div>
      </div>
    </div>,
  /* </Link> */
};