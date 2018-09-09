let component = ReasonReact.statelessComponent("Logo")

let make = (~collapsed, ~openDrawer, _children) => {
    let realCollapsed = collapsed && !openDrawer;
    {
    ...component,
    render: (_) =>     
    <div className="isoLogoWrapper">
      {realCollapsed ? (
        <div>
          <h3>
            <Router.Link route=Dashboard([])>
              <i className="ion-home" />
            </Router.Link>
          </h3>
        </div>
      ) : (
        <h3>
          <Router.Link route=Dashboard([])>{Utils.str("IMMIWORK")}</Router.Link>
        </h3>
      )}
    </div>

}}