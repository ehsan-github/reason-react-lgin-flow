[%bs.raw {|require('./ForgotPass.css')|}];
type state = {email: string};

type action =
  | ChangeEmail(string);

let reducer = (action, _state) =>
  switch (action) {
  | ChangeEmail(email) => ReasonReact.Update({email: email})
  };

let component = ReasonReact.reducerComponent("ForgotPass");

module ForgotPassword = [%graphql
  {|
  mutation requestResetPassword($email: String!) {
      requestResetPassword(email: $email)
  }
|}
];

module ForgotPassMutation = ReasonApollo.CreateMutation(ForgotPassword);

let make = _children => {
  let submit = state => Js.log(state);
  {
    ...component,
    initialState: () => {email: ""},
    reducer,
    render: ({state, send}) =>
      <ForgotPassMutation>
        ...{
             (mutation, {result}) => {
               let resetPassAction =
                 ForgotPassword.make(~email=state.email, ());

               <div className="isoForgotPassPage">
                 <div className="isoFormContentWrapper">
                   <div className="isoFormContent">
                     <div className="isoLogoWrapper">
                       <Router.Link route=Signup>
                         /* <IntlMessages id="page.forgetPassTitle" /> */
                          {ReasonReact.string("IMMIWORK")} </Router.Link>
                     </div>
                     <div className="isoFormHeadText">
                       <h3> {ReasonReact.string("Forgot Password?")} </h3>
                       <p>
                         {
                           ReasonReact.string(
                             "Enter your email and we send you a reset link.",
                           )
                         }
                       </p>
                     </div>
                     <div className="isoInputWrapper">
                       <form
                         onSubmit={
                           event => {
                             ReactEvent.Synthetic.preventDefault(event);
                             mutation(
                               ~variables=resetPassAction##variables,
                               (),
                             )
                             |> ignore;
                           }
                         }>
                         <div className="isoForgotPassForm">
                           {
                             switch (result) {
                             | Error(error) =>
                               <Antd.Alert
                                 message="Error"
                                 description={error##message} 
                                 type_="error"
                               />
                             | Data(_response) =>
                               ReasonReact.Router.push("/signin");
                               <Antd.Alert
                                 message="Success"
                                 description="Password reset link was sent to your email."
                                 type_="success"
                               />;
                             | _ => <div></div>
                             }
                           }
                           <div className="isoInputWrapper">
                             <Antd.Input
                               placeholder="Email"
                               value={state.email}
                               onChange={
                                 event =>
                                   send(
                                     ChangeEmail(
                                       ReactEvent.Form.target(event)##value,
                                     ),
                                   )
                               }
                             />
                           </div>
                           <div className="isoInputWrapper">
                             <Antd.Button
                               loading={result == Loading}
                               type_="primary"
                               htmlType="submit">
                               {ReasonReact.string("Send request")}
                             </Antd.Button>
                           </div>
                         </div>
                       </form>
                     </div>
                   </div>
                 </div>
               </div>;
             }
           }
      </ForgotPassMutation>,
  };
};