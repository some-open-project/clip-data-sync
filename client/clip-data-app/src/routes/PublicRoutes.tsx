import { Route, BrowserRouter as Router, Routes } from 'react-router-dom';
import { Dashboard } from '../pages/Dashboard';
import { Home } from '../pages/Home';
import { Login } from '../pages/Login';
import { Register } from '../pages/Register';
import { PATHS } from '../constants/paths';

export const PublicRoutes = () => {
  return (
    <Router>
      <Routes>
        <Route path={PATHS.HOME} element={<Home />} />
        <Route path={PATHS.LOGIN} element={<Login />} />
        <Route path={PATHS.REGISTER} element={<Register />} />
        <Route path={PATHS.DASHBOARD} element={<Dashboard />} />
        {/* TODO: User Profile */}
        {/* <Route path="/profile/:username" element={<Profile />} /> */}
      </Routes>
    </Router>
  );
};
