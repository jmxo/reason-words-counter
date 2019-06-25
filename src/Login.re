[%bs.raw {|require('./Login.css')|}];

[@react.component]
let make = () => {
  let (email, setEmail) = React.useState(() => "");
  let (password, setPassword) = React.useState(() => "");

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
      </div>
      <div className="inputField">
        <input
          type_="password"
          placeholder="Password"
          value=password
          onChange=handlePasswordChange
          required=true
        />
      </div>
      <Button title="Login" category=Button.PRIMARY>
        {"Login" |> ReasonReact.string}
      </Button>
    </form>
  </div>;
};
