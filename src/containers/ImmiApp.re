[%bs.raw {|require('./ImmiApp.css')|}];

type state = {
  collapsed: bool,
  openDrawer: bool,
};
type action =
  | ToggleCollapsed
  | ToggleOpenDrawer;

let reducer = (action, state) =>
  switch (action) {
  | ToggleCollapsed =>
    ReasonReact.Update({...state, collapsed: !state.collapsed})
  | ToggleOpenDrawer =>
    ReasonReact.Update({...state, openDrawer: !state.openDrawer})
  };
let component = ReasonReact.reducerComponent("ImmiApp");

let appHeight = [%bs.raw {| window.innerHeight |}];

let make = (~tailRoutes, ~logout, _children) => {
  ...component,
  initialState: () => {collapsed: true, openDrawer: false},
  reducer,
  render: ({state, send}) =>
    <div className="appHolder">
        <Antd.Layout style={ReactDOMRe.Style.make(~height=appHeight, ())}>
          <Topbar
            toggleCollapsed={(e_) => send(ToggleCollapsed)}
            collapsed={state.collapsed}
            openDrawer={state.openDrawer}
            logout
          />
          <Antd.Layout className="side-layout">
            <Sidebar
              collapsed={state.collapsed}
              openDrawer={state.openDrawer}
              currentComp=0
              toggleOpenDrawer={() => send(ToggleOpenDrawer)}
            />
            <Antd.Layout className="isoContentMainLayout">
              <Antd.Layout.Content
                className="isomorphicContent content-top"
              >
                  <div>{Utils.str("HOME")}</div>
              {
                switch(tailRoutes){
                  | [] => <div>{Utils.str("HOME")}</div>
                  | ["profile"] => <Profile />
                }
              }
              </Antd.Layout.Content>
              <Antd.Layout.Footer className="app-footer">
                {Utils.str("IMMIWORK 2018 Created by ImmiWork, Inc")}
              </Antd.Layout.Footer>
            </Antd.Layout>
          </Antd.Layout>
        </Antd.Layout>
      </div>,
};