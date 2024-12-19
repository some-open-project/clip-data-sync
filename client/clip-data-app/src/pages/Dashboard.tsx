import { Box, Container, List, ListItem, ListItemButton, ListItemText, TextField, Typography } from "@mui/material";
import Grid from "@mui/material/Grid2";
import { useState } from "react";

const items = ['item1', 'item2', 'item3', 'item4', 'item5', 'item6', 'item7', 'item8', 'item9', 'item10'];

export const Dashboard = () => {
  const [selectedItem, setSelectedItem] = useState<string | null>(null);
  const [search, setSearch] = useState<string>('');

  // 클릭한 항목 내용 예시
  const getItemDetails = (item: string) => {
    return `${item} details: This is some detailed information about ${item}.`;
  };

  const handleChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    setSearch(e.target.value);
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
        <TextField id="standard-basic" value={search} onChange={handleChange} label="Search" placeholder="Search" variant="standard" fullWidth />
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
              {items.filter(i => i.includes(search)).map((item) => (
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
