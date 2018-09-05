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

let make = _children => {
    ...component,
    reducer,
    initialState: () => {visible: false},
    render: ({state}) => 
    <Antd.Popover
      >
        <div className="isoImgWrapper">
          <img alt="user" src={userpic} />
          <span className="userActivity online" />
        </div>
      </Antd.Popover>

};