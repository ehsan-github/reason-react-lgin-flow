/* [%bs.raw {|require('../ForgotPassword/ForgotPass.css')|}]; */
type state = {loading: bool, message: string, verified: bool};

type action =
  | SetSuccess
  | SetFailure;

let reducer = (action, _state) =>
  switch action {
  | SetSuccess => ReasonReact.Update({
    loading: false, 
    verified: true, 
    message: "Your email verified successfully"})
  | SetFailure => ReasonReact.Update({
    loading: false, 
    verified: false, 
    message: "There was an erro in email verification"});
  };

let component = ReasonReact.reducerComponent("EmailVerif");

let make = (_children) => {
  {
    ...component,
    initialState: () => {
    loading: true,
    verified: false,
    message: "checking verification please wait ..."
    },
    reducer,
    render: ({state}) =>
    <div className="isoForgotPassPage">
        <div className="isoFormContentWrapper">
          <div className="isoFormContent">
            <div className="isoLogoWrapper">
              <Router.Link route=Signin>
                /* <IntlMessages id="page.forgetPassTitle" /> */
                 (ReasonReact.string("IMMIWORK"))
              </Router.Link>
            </div>
            <Antd.Spin spinning={state.loading} delay=500>
              <Antd.Alert
                description={state.message}
                type_={state.verified ? "success" : "error"}
                />
            </Antd.Spin>

              <div style={ReactDOMRe.Style.make(~margin="30px", ())}/>
              <div className="buttondiv">
                <Antd.Button type_="primary" >
                  <Router.Link route=Signin>
                    /* <IntlMessages id="page.goToSigninPage" /> */
                    (ReasonReact.string("Sign in"))
                  </Router.Link>
                </Antd.Button>
              </div>
            </div>
          </div>
        </div>
        }
};