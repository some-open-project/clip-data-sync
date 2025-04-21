# clip-data-sync
---

Purpose :

 다양한 플랫폼 간에 클립보드 데이터를 동기화하는 것이 목표입니다.
 
 현재 코드는 JSON 형식으로 클립데이터를 내보내고 가져오는 기능까지 DLL로 호출하도록 되어 있으며
장기적으로 다른 환경에서 클립보드 데이터를 공유하고 활용할 수 있도록 지원하는 것이 목표입니다.

 - [X] getClientClipData();
 - [X] setClipData(json& jsonClipData);
 - [ ] ClipDataSyncCore();
 - [ ] executeClipCopy();
 - [ ] executeClipPaste();
 - [ ] executePasteHtmlData();
 - [ ] executePasteNormalText();
 - [ ] exportHtmlData();
 - [ ] exportNormalText();
 - [ ] getClientClipData();
