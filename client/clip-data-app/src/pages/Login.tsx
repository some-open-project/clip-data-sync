import { useNavigate } from "react-router-dom";
import { PATHS } from "../constants/paths";
import { Box, Button, Container, IconButton, Paper, TextField, Typography } from "@mui/material";
import { useState } from "react";
import FacebookIcon from "@mui/icons-material/Facebook";
import GoogleIcon from "@mui/icons-material/Google";
import LinkedInIcon from "@mui/icons-material/LinkedIn";

// TODO: Add signup, signin form
// const TITLE = 'Clip Data Sync';
export const Login = () => {
  const navigate = useNavigate();
  const [isSignUp, setIsSignUp] = useState(false);
  const toggleForm = () => setIsSignUp((prev) => !prev);
  const handleLogin = () => {
    console.log('Login successful');
    navigate(PATHS.DASHBOARD);
  };
  return (
    <Container
      sx={{
        display: "flex",
        alignItems: "center",
        justifyContent: "center",
        height: "100vh",
      }}
    >
      <Paper
        elevation={3}
        sx={{
          width: "800px",
          overflow: "hidden",
          display: "flex",
          flexDirection: isSignUp ? "row-reverse" : "row",
          transition: "all 0.5s ease",
        }}
      >
        {/* Sign Up Form */}
        <Box
          sx={{
            width: "50%",
            padding: "2rem",
            display: isSignUp ? "flex" : "none",
            flexDirection: "column",
            alignItems: "center",
          }}
        >
          <Typography variant="h4" gutterBottom>
            Create Account
          </Typography>
          <Box sx={{ display: "flex", justifyContent: "center", gap: "0.5rem" }}>
            <IconButton>
              <FacebookIcon color="primary" />
            </IconButton>
            <IconButton>
              <GoogleIcon color="error" />
            </IconButton>
            <IconButton>
              <LinkedInIcon color="info" />
            </IconButton>
          </Box>
          <Typography variant="body2" sx={{ margin: "1rem 0" }}>
            or use your email for registration
          </Typography>
          <TextField fullWidth margin="normal" label="Name" />
          <TextField fullWidth margin="normal" label="Email" type="email" />
          <TextField fullWidth margin="normal" label="Password" type="password" />
          <Button variant="contained" color="primary" fullWidth>
            Sign Up
          </Button>
        </Box>

        {/* Sign In Form */}
        <Box
          sx={{
            width: "50%",
            padding: "2rem",
            display: isSignUp ? "none" : "flex",
            flexDirection: "column",
            alignItems: "center",
          }}
        >
          <Typography variant="h4" gutterBottom>
            Sign in
          </Typography>
          <Box sx={{ display: "flex", justifyContent: "center", gap: "0.5rem" }}>
            <IconButton>
              <FacebookIcon color="primary" />
            </IconButton>
            <IconButton>
              <GoogleIcon color="error" />
            </IconButton>
            <IconButton>
              <LinkedInIcon color="info" />
            </IconButton>
          </Box>
          <Typography variant="body2" sx={{ margin: "1rem 0" }}>
            or use your account
          </Typography>
          <TextField fullWidth margin="normal" label="Email" type="email" />
          <TextField fullWidth margin="normal" label="Password" type="password" />
          <Button variant="text" sx={{ alignSelf: "flex-start", mb: 2 }}>
            Forgot your password?
          </Button>
          <Button variant="contained" color="primary" fullWidth onClick={handleLogin}>
            Sign In
          </Button>
        </Box>

        {/* Overlay Section */}
        <Box
          sx={{
            width: "50%",
            backgroundColor: "primary.main",
            color: "white",
            textAlign: "center",
            padding: "2rem",
            display: "flex",
            flexDirection: "column",
            justifyContent: "center",
          }}
        >
          {isSignUp ? (
            <>
              <Typography variant="h4" gutterBottom>
                Welcome Back!
              </Typography>
              <Typography variant="body1" gutterBottom>
                To keep connected with us please login with your personal info
              </Typography>
              <Button
                variant="outlined"
                color="inherit"
                onClick={toggleForm}
                fullWidth
              >
                Sign In
              </Button>
            </>
          ) : (
            <>
              <Typography variant="h4" gutterBottom>
                Hello, Friend!
              </Typography>
              <Typography variant="body1" gutterBottom>
                Enter your personal details and start your journey with us
              </Typography>
              <Button
                variant="outlined"
                color="inherit"
                onClick={toggleForm}
                fullWidth
              >
                Sign Up
              </Button>
            </>
          )}
        </Box>
      </Paper>
    </Container>
  );
};
