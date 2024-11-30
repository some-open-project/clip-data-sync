import { useNavigate } from "react-router-dom";
import { PATHS } from "../constants/paths";

export const Login = () => {
  const navigate = useNavigate();
  return (
    <div>
      <h1>Login</h1>
      <button onClick={() => navigate(PATHS.DASHBOARD)}>To Dashboard Page</button>
    </div>
  );
};
