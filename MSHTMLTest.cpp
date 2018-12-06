#include <windows.h>
#include <string>

#include "HTMLWindow.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE /*unused__*/, LPSTR /*lpszCmdLine*/, int /*nCmdShow*/) {

  char curDir[256];
  GetCurrentDirectoryA(255, curDir);

  std::string html = 
           "<html><head>"
           "<title>MSHTMLTest</title>"   // seems a little useless in this context
           "</head><body>"
           "<h1>This is a test</h1>"
           "I offer the following links:"
           "<ul>"
           "<li><a href='https://www.google.com'>Google</a>"
           "<li><a href='https://www.renenyffenegger.ch'>renenyffenegger.ch</a>"
           "<li><a href='https://github.com/ReneNyffenegger/cpp-MSHTML'>github repository</a>"
       //
       //  Unfortunately, file:// links don't seem to work:
       //
       //  "<li><a href='file://"; html += curDir;  html += "/test/index.html'>test/index.html</a>"
           ;
  html += "</ul>"
          "</body></html>",
        // Parameter title 
          "MSHTMLTest";
//MessageBox(0, html.c_str(), 0, 0);

  HTMLWindow* html_window = new HTMLWindow (
         html,         // HTML text (or url)
        "MSHTML Test", // Title
         hInstance,
         false  // indicates: this not an url, but html 
  );

  MSG msg;
  while (GetMessage(&msg, 0, 0, 0)) {
    TranslateMessage(&msg);
    if (msg.message >= WM_KEYFIRST && 
        msg.message <= WM_KEYLAST) {
      ::SendMessage(html_window->hwnd_, msg.message, msg.wParam, msg.lParam);
    }
    DispatchMessage(&msg);
  }

  return 0;
}
