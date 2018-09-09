[%bs.raw {| require('./TopbarUser.css') |}]

[@bs.module "../../image/user1.png"] external userpic : string = "default";

type state = {visible: bool};
type action =
  | ToggleVisibleChange
  | Hide;
let reducer = (action, state) =>
  switch (action) {
  | ToggleVisibleChange => ReasonReact.Update({visible: !state.visible})
  | Hide => ReasonReact.Update({visible: false})
  };
let component = ReasonReact.reducerComponent("TopBarUser");

let make = (~logout, _children) => {
    ...component,
    reducer,
    initialState: () => {visible: false},
    render: ({state}) => 
    <Antd.Popover
    placement="bottomLeft"
    trigger="click"
    arrowPointAtCenter={true}
    content={
      <div className="isoUserDropdown transition">
        <Router.Link route=Dashboard(["profile"]) className="isoDropdownLink">
        {Utils.str("Profile")}
        </Router.Link>
        <a
          className="isoDropdownLink"
          onClick={_e => {
            logout();
            /* this.props.closeAll(); */
          }}
        >
        {Utils.str("Logout")}
        </a>
      </div>
    }
      >
        <div className="isoImgWrapper">
          <img alt="user" src={userpic} />
          <span className="userActivity online" />
        </div>
      </Antd.Popover>

};

/* let Module Content = {
  let component = scomp("Content");
  let make = (_children) => {
    ...component,
    render: (_self) => 
      <TopbarDropdownWrapper className="isoUserDropdown">
        <Link to="/dashboard/profile" className="isoDropdownLink">
          <IntlMessages id="themeSwitcher.profile" />
        </Link>
        <a
          className="isoDropdownLink"
          onClick={() => {
            this.props.logout();
            this.props.closeAll();
          }}
        >
          <IntlMessages id="topbar.logout" />
        </a>
      </TopbarDropdownWrapper>
  }
} */