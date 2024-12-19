import { Box, Container, List, ListItem, ListItemButton, ListItemText, Paper, TextField, Typography } from "@mui/material";
import Grid from "@mui/material/Grid2";
import { cloneElement, useState, ReactElement } from "react";

function generate(element: ReactElement<unknown>) {
  return [0, 1, 2].map((value) =>
    cloneElement(element, {
      key: value,
    }),
  );
}

export const Dashboard = () => {
  const [selectedItem, setSelectedItem] = useState<string | null>(null);

  const items = ['item1', 'item2', 'item3', 'item4', 'item5', 'item6'];

  // 클릭한 항목 내용 예시
  const getItemDetails = (item: string) => {
    return `${item} details: This is some detailed information about ${item}.`;
  };

  return (
    <Container
      sx={{
        alignItems: "center",
        justifyContent: "center",
        height: "100vh",
      }}
    >
      <Box>
        <TextField id="standard-basic" label="Search" variant="standard" fullWidth />
      </Box>
      <Grid container spacing={2} sx={{ height: '100vh' }}>
        {/* 왼쪽 리스트 영역 */}
        <Grid size={4}>
          <Box
            sx={{
              height: "100%",
              overflowY: "auto",
              borderRight: "2px solid #ddd",
              padding: "1rem",
            }}
          >
            <Typography variant="h6" sx={{ textAlign: "center" }}>Item List</Typography>
            <List>
              {items.map((item) => (
                <ListItem>
                  <ListItemButton
                    key={item}
                    selected={selectedItem === item}
                    onClick={() => setSelectedItem(item)}
                  >
                    <ListItemText primary={item} />
                  </ListItemButton>
                </ListItem>
              ))}
            </List>
          </Box>
        </Grid>

        {/* 오른쪽 상세 내용 영역 */}
        <Grid size={8}>
          <Box
            sx={{
              height: "100%",
              overflowY: "auto",
              padding: "1rem",
              backgroundColor: "#f9f9f9",
            }}
          >
            {selectedItem ? (
              <>
                <Typography variant="h5">{selectedItem}</Typography>
                <Typography variant="body1" sx={{ marginTop: "1rem" }}>
                  {getItemDetails(selectedItem)}
                </Typography>
              </>
            ) : (
              <Typography variant="h6">Please select an item</Typography>
            )}
          </Box>
        </Grid>
      </Grid>
    </Container>
  );
};
