const { app, BrowserWindow } = await import("electron");
const path = await import("path");
const isDev = await import("electron-is-dev");

let mainWindow;

function createWindow() {
    mainWindow = new BrowserWindow({
        width: 900,
        height: 680,
        webPreferences: {
            nodeIntegration: true,
            enableRemoteModule: true,
            devTools: isDev,
        },
    });

    // ***중요***
    mainWindow.loadURL(
        isDev
            ? "http://localhost:3000"   // 개발 환경: React 개발 서버
            : `file://${path.resolve(__dirname, "../build/index.html")}`    // 프로덕션 환경: 빌드 파일
        );

    if (isDev) mainWindow.webContents.openDevTools({ mode: "detach" });

    mainWindow.setResizable(true);
    mainWindow.on("closed", () => {
        mainWindow = null;
        app.quit();
    });
    mainWindow.focus();
}

app.on("ready", createWindow);

app.on("activate", () => {
    if (mainWindow === null) createWindow();
});

app.on("window-all-closed", () => {
    if (process.platform !== "darwin") app.quit();
});
