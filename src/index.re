[%bs.raw {|require('./index.css')|}];
[%bs.raw {|require('./App.css')|}];
[%bs.raw {|require('antd/dist/antd.css')|}];
[%bs.raw {|require('./assets/css/ionicons.min.css')|}];
[%bs.raw {|require('./assets/css/roboto.css')|}];


[@bs.module "./registerServiceWorker"]
external register_service_worker : unit => unit = "default";

ReactDOMRe.renderToElementWithId(
  <Signup />,
  "root",
);

register_service_worker();
