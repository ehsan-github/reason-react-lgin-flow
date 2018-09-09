[%bs.raw {| require('./Sidebar.css') |}];
let component = ReasonReact.statelessComponent("Sidebar");

let make =
    (~collapsed, ~openDrawer, ~currentComp, ~toggleOpenDrawer, _children) => {
  let realCollapsed = collapsed && !openDrawer;

  let onMouseEnter = _e =>
    if (openDrawer == false) {
      toggleOpenDrawer();
    };
  let onMouseLeave = _e =>
    if (openDrawer == true) {
      toggleOpenDrawer();
    };
  let onOpenChange = _e => Js.log("on open change");
  let mode = realCollapsed == true ? "vertical" : "inline";
  {
    ...component,
    render: _ =>
      <div className="side-bar-wrapper">
        <Antd.Layout.Sider
          collapsible=true
          collapsed=realCollapsed
          width=240
          className="isomorphicSidebar transition"
          onMouseEnter
          onMouseLeave>
          <Logo collapsed={collapsed} openDrawer={openDrawer}/>

            <Antd.Menu
              theme="dark"
              className="isoDashboardMenu"
              mode
              openKeys={realCollapsed ? [] : []}
              selectedKeys=[]
              onOpenChange>
              <Antd.Menu.Item>
                <Router.Link route=Dashboard([])>
                  <span className="isoMenuHolder">
                    <i className="ion-flash" />
                    <span className="nav-text"> {Utils.str("blank")} </span>
                  </span>
                </Router.Link>
              </Antd.Menu.Item>
            </Antd.Menu>
          </Antd.Layout.Sider>
      </div>,
  };
};