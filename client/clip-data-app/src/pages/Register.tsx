import { useNavigate } from "react-router-dom";
import { PATHS } from "../constants/paths";

export const Register = () => {
  const navigate = useNavigate();

  return (
    <div>
      <h1>Register</h1>
      <button onClick={() => navigate(PATHS.LOGIN)}>To Login Page</button>
    </div>
  );
};
