[%bs.raw {|require('./Login.css')|}];

type loginError =
  | EMAIL_NOT_FOUND
  | INVALID_PASSWORD
  | OTHER;

let stringToLoginError = str =>
  switch (str) {
  | "EMAIL_NOT_FOUND" => Some(EMAIL_NOT_FOUND)
  | "INVALID_PASSWORD" => Some(INVALID_PASSWORD)
  | _ => Some(OTHER)
  };

[@react.component]
let make = () => {
  let (email, setEmail) = React.useState(() => "");
  let (password, setPassword) = React.useState(() => "");
  let (error, setError) = React.useState(() => None);

  let handleEmailChange = e => e->ReactEvent.Form.target##value |> setEmail;
  let handlePasswordChange = e =>
    e->ReactEvent.Form.target##value |> setPassword;

  let handleFormSubmit = e => {
    e->ReactEvent.Form.preventDefault;
    // TODO
  };

  <div className="Login">
    <h2> {"Login" |> ReasonReact.string} </h2>
    <form onSubmit=handleFormSubmit>
      <div className="inputField">
        <input
          type_="email"
          placeholder="Email"
          value=email
          onChange=handleEmailChange
          required=true
        />
        {switch (error) {
         | Some(EMAIL_NOT_FOUND) =>
           <div className="error">
             {{js| ⚠  Email not found |js} |> ReasonReact.string}
           </div>
         | _ => ReasonReact.null
         }}
      </div>
      <div className="inputField">
        <input
          type_="password"
          placeholder="Password"
          value=password
          onChange=handlePasswordChange
          required=true
        />
        {switch (error) {
         | Some(INVALID_PASSWORD) =>
           <div className="error">
             {{js| ⚠ Invalid password |js} |> ReasonReact.string}
           </div>
         | _ => ReasonReact.null
         }}
      </div>
      <Button title="Login" category=Button.PRIMARY>
        {"Login" |> ReasonReact.string}
      </Button>
    </form>
  </div>;
};
