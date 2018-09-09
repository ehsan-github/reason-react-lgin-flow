[%bs.raw {| require('./Topbar.css') |}]
let component = ReasonReact.statelessComponent("Topbar");

let make = (~logout, ~collapsed, ~openDrawer, ~toggleCollapsed, _children) => {
  let realCollapsed = collapsed && !openDrawer;
  let headerClass: string =
    realCollapsed ? "isomorphicTopbar collapsed" : "isomorphicTopbar";
  let buttonClass: string=
    realCollapsed ? "triggerBtn menuCollapsed" : "triggerBtn menuOpen";
  {
    ...component,
    render: _ =>
      <div className="transition">
        <Antd.Layout.Header className=headerClass>
          <div className="isoLeft">
            <button className=buttonClass onClick=toggleCollapsed />
          </div>
          <ul className="isoRight">
            <li
              className="isoUser"
            />
              <TopbarUser logout />
          </ul>
        </Antd.Layout.Header>
      </div>,
  };
};