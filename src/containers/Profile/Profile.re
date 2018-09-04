let component = ReasonReact.statelessComponent("Profile");

module GetUser = [%graphql
  {|
  query user($accesstoken: String!) {
      user(accessToken: $accesstoken) {
          first_name
      }
  }
|}
];

let accessToken: string = "eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiIsImp0aSI6IjhlNmQxNDU2ZWFiZjAxMWU5Mjk5MzNlYzg2ODJmMjVmODQyNmRhOGMxZTkyOGIxZWNmZDkxNDY0YTU3MWJkZmI2ZmEyNDdiYjM3OGEzOTlkIn0.eyJhdWQiOiIxIiwianRpIjoiOGU2ZDE0NTZlYWJmMDExZTkyOTkzM2VjODY4MmYyNWY4NDI2ZGE4YzFlOTI4YjFlY2ZkOTE0NjRhNTcxYmRmYjZmYTI0N2JiMzc4YTM5OWQiLCJpYXQiOjE1MzU5OTU2MzYsIm5iZiI6MTUzNTk5NTYzNiwiZXhwIjoxNTM2ODU5NjM2LCJzdWIiOiIzNCIsInNjb3BlcyI6W119.G8G4AKj2SOu4KsjewQdsbyfqXlyqNNSgzoYWrf9lNeQRhjTIMDkwYw3MHRqkRuTDdPdP6D3deaWqSzoYXFAS-3kng6JN17R0UYCa_UERwN0pZx-ZqXOkHWWibcRI3j-WEfAHVV59hJGbyXI6gbGalam-glvlyF3pPt8pPT-rdKL_HN4idjq9I3op-53lEymfGJkPGd4AsepGIsg8vN4ct0CvID3PLSksl7GhwYP1Ox-J3LVlWLqw8VKTMaNZE2bYdHkthWla40M02idJwjGFmxL1lF_CHyNKZsiBps5BS565Et-igClqPk37n6OHCUgKTCr61qJwsZchNkcT08CC7s93bNkURoLbjBYWtakzwkEL7YNwhM2qspHeZGbvoFBVcbzxZDmDz-sLKMgFxHRTDBA96SUV4uEjc7a3ThINnMQ-FeQ4isATsr3Q7A9s5jtwtkcSteZButM9jwWaxNA8gezwADz768zZrlXNN0mHbJSdCZ67NY_VtLQOv_WikJjBIoJ1w-Van4EHx5mRip6D4OsQNaNT1lpqzmZzI28B_-LBvxPqUz2z46H6YscyRUC93-V-hleQ5nRcg5PinpzYMVdFr100MwIIqKjrDM3Uvaxq2n3u63yhrwTcvzZjVzKDqIddO-LIxmxI3SCAx53m09bu8YdmJiSyBn6Ok0csd9M";

module GetUserQuery = ReasonApollo.CreateQuery(GetUser);

let make = _children => {
  ...component,
  render: _ => {
    let userQuery = GetUser.make(~accesstoken=accessToken, ());
    <GetUserQuery variables=userQuery##variables>
      ...{
           ({result}) =>
             switch (result) {
             | Loading => <div> {ReasonReact.string("Loading")} </div>
             | Error(error) =>
               <div> {ReasonReact.string(error##message)} </div>
             | Data(response) =>
               switch (response##user##first_name) {
               | Some(name) => <div> {ReasonReact.string(name)} </div>
               | None => <div> {ReasonReact.string("No Name")} </div>
               }
             }
         }
    </GetUserQuery>;
  },
};