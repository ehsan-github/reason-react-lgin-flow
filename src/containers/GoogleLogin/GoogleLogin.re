let component = Utils.scomp("Glogin")
let make = (_children, ~query) => {
    ...component,
    render: (_self) => <div>{Utils.str(query)}</div>
}