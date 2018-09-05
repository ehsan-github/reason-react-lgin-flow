[%bs.raw {|require('./ResetPass.css')|}];
type state = {
  password: string,
  password_repeat: string,
};

type action =
  | ChangePassword(string)
  | ChangePasswordRepeat(string);

let reducer = (action, state) =>
  switch (action) {
  | ChangePassword(password) => ReasonReact.Update({...state, password})
  | ChangePasswordRepeat(password_repeat) =>
    ReasonReact.Update({...state, password_repeat})
  };

let component = ReasonReact.reducerComponent("ResetPass");

let make = _children => {
  let submit = state => Js.log(state);
  {
    ...component,
    initialState: () => {password: "", password_repeat: ""},
    reducer,
    render: ({state, send}) =>
      <div className="isoResetPassPage">
        <div className="isoFormContentWrapper">
          <div className="isoFormContent">
            <div className="isoLogoWrapper">
              <Router.Link route=Signup>
                /* <IntlMessages id="page.resetPassTitle" /> */
                 {ReasonReact.string("IMMIWORK")} </Router.Link>
            </div>
            <div className="isoFormHeadText">
              <h3>
                 {ReasonReact.string("Reset password")} </h3>
                /* <IntlMessages id="page.resetPassSubTitle" /> */
              <p>

                  {ReasonReact.string("Enter new password and confirm it.")}
                </p>
                /* <IntlMessages id="page.resetPassDescription" /> */
            </div>
            <form onSubmit=submit>
              <div className="isoResetPassForm">
                /* <Antd.Form.Item
                   hasFeedback={password.hasFeedback}
                   validateStatus={password.validateStatus}
                   help={password.validateStatus === "error" && <IntlMessages id="forms.formsWithValidation.AtLeastEight" />}
                   > */

                  <div className="isoInputWrapper">
                  <Antd.Input
                    value={state.password}
                    onChange={
                      event =>
                        send(
                          ChangePassword(
                            ReactEvent.Form.target(event)##value,
                          ),
                        )
                    }
                    type_="password"
                    placeholder="New Password"
                  />
                  /* </Antd.Form.Item> */
                  /* <Antd.Form.Item
                     hasFeedback={password_repeat.hasFeedback}
                     validateStatus={password_repeat.validateStatus}
                     help={password_repeat.validateStatus === "error" && <IntlMessages id="forms.formsWithValidation.NotMatch" />}
                     > */
                  </div>
                  <div className="isoInputWrapper">
                  <Antd.Input
                    value={state.password_repeat}
                    onChange={
                      event =>
                        send(
                          ChangePasswordRepeat(
                            ReactEvent.Form.target(event)##value,
                          ),
                        )
                    }
                    type_="password"
                    placeholder="Confirm Password"
                  />
                  </div>
                  /* </Antd.Form.Item> */
                  <div className="isoInputWrapper">
                    <Antd.Button type_="primary" htmlType="submit">
                      /* <IntlMessages id="page.resetPassSave" /> */
                       {ReasonReact.string("Reset password")} </Antd.Button>
                  </div>
                </div>
            </form>
          </div>
        </div>
      </div>,
  };
};