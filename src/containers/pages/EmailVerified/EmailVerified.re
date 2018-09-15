/* [%bs.raw {|require('../ForgotPassword/ForgotPass.css')|}]; */

module VerifEmail = [%graphql
  {|
query verifEmail($code: String!){
  verifyEmail(code: $code) {
    access_token
  }
}
|}
];

module CheckVerifEmail = ReasonApollo.CreateQuery(VerifEmail);

let component = Utils.scomp("EmailVerif");

let make = (~code, _children) => {
  ...component,
  render: _ => {
    let verifQuery = VerifEmail.make(~code, ());
    <CheckVerifEmail variables=verifQuery##variables>
      ...{
           ({result}) =>
             <div className="isoForgotPassPage">
               <div className="isoFormContentWrapper">
                 <div className="isoFormContent">
                   <div className="isoLogoWrapper">
                     <Router.Link route=Signin>
                       {ReasonReact.string("IMMIWORK")}
                     </Router.Link>
                   </div>
                   <Antd.Spin spinning={result == Loading} delay=500>
                     <Antd.Alert
                       message=""
                       description={
                         switch(result){
                           | Data(_x)   => "Your email verified successfullystate."
                           | Error(err) => err##message
                           | _          => ""
                         }
                       }
                       type_={
                         switch(result){
                           | Data(_x)   => "success"
                           | Error(_e) => "error"
                           | _          => "info"
                         }
                       }
                     />
                   </Antd.Spin>
                   <div style={ReactDOMRe.Style.make(~margin="30px", ())} />
                   <div className="buttondiv">
                     <Antd.Button type_="primary">
                       <Router.Link route=Signin>
                         {ReasonReact.string("Sign in")}
                       </Router.Link>
                     </Antd.Button>
                   </div>
                 </div>
               </div>
             </div>
         }
    </CheckVerifEmail>;
  },
};