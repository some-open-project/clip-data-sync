import { useNavigate } from 'react-router-dom';
import { PATHS } from '../constants/paths';

export const Home = () => {
  const navigate = useNavigate();
  return (
    <div>
      <h1>Home</h1>
      <button onClick={() => navigate(PATHS.LOGIN)}>To Login Page</button>
    </div>
  );
};
