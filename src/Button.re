[%bs.raw {|require('./Button.css')|}];

type category =
  | PRIMARY
  | SECONDARY;

let classNameOfCategory = category =>
  "Button "
  ++ (
    switch (category) {
    | PRIMARY => "primary"
    | SECONDARY => "secondary"
    }
  );

[@react.component]
let make =
    (
      ~onClick=_ => (),
      ~title,
      ~children: ReasonReact.reactElement,
      ~disabled=false,
      ~category=SECONDARY,
    ) => {
  <button onClick className={category |> classNameOfCategory} title disabled>
    children
  </button>;
};
