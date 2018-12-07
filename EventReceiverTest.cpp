//
//  Found at https://web.archive.org/web/20041012063806/http://www.adp-gmbh.ch:80/win/misc/mshtml/HTMLWindow.html#EventReceiver
//
/* 
   EventReceiverTest.cpp

   Copyright (C) 2004 René Nyffenegger

   This source code is provided 'as-is', without any express or implied
   warranty. In no event will the author be held liable for any damages
   arising from the use of this software.

   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:

   1. The origin of this source code must not be misrepresented; you must not
      claim that you wrote the original source code. If you use this source code
      in a product, an acknowledgment in the product documentation would be
      appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
      misrepresented as being the original source code.

   3. This notice may not be removed or altered from any source distribution.

   René Nyffenegger rene.nyffenegger@adp-gmbh.ch
*/

#include <windows.h>
#include "HTMLWindow2.h"
#include "todoMoveSrc/Tracer.h"

#include <sstream>

class EventReceiverInherited : public EventReceiver {

  private: 
  std::string make_title(std::string const& title) {
    return std::string("<html><body><h1>") + title + "</h1></body></html>";
  }

  void calculation(std::string& out_html, const Parameters& params) {

    std::string op1_value = params.Value("op1");
    std::string op2_value = params.Value("op2");
    std::string op_value  = params.Value("op" );

    std::string result="";

    if (op1_value.length() && op2_value.length() && op_value.length() ) {
      int op1;
      int op2;
      int res;

      std::stringstream s;
      s << op1_value;
      s >> op1;

      s.clear();
      s << op2_value;
      s >> op2;

      if (op_value == "plus" ) res = op1 + op2;
      if (op_value == "minus") res = op1 - op2;
      if (op_value == "mult" ) res = op1 * op2;
      if (op_value == "div"  ) res = op1 / op2;

      s.clear();
      s << res;
      s >> result;
    }

    /* Here's the important part of the html:*/ 
    out_html += "<form action='link://calc/'>"
                "<input type='text' name='op1' size='5' value='" + op1_value + "'>"
                "<select name='op'>"
                "  <option value='plus' " + (op_value == "plus"  ? " selected" : "") + ">+"
                "  <option value='minus'" + (op_value == "minus" ? " selected" : "") + ">-"
                "  <option value='mult' " + (op_value == "mult"  ? " selected" : "") + ">*"
                "  <option value='div'  " + (op_value == "div"   ? " selected" : "") + ">/"
                "</input>"
                "<input type='text' name='op2' size='5' value='" + op2_value + "'>"
                "<input type='submit' value='='>"
                "<b>" + result + "</b>"
                "</form>";
  }

  /* AppLink: overriding EventReceiver::AppLink */
  protected:
  virtual void AppLink(std::string const& path, std::string& out_html, const Parameters& params) {
    if (path == "calc/") {
      out_html = make_title("Calculator");
      calculation(out_html, params);
    }
    else if (path == "some_simple_text/") {
      out_html = make_title("Some text");
      out_html += "Here is just <b>some text</b>";
    }
    else if (path == "start_link") {
      out_html = make_title("Event Receiver Test");
    }
    else {
      ::MessageBox(0, path.c_str(), "Unknown Link", 0);
    }

    out_html += "<hr><a href='link://calc/'>Calculator</a>"
                "<br><a href='link://some_simple_text/'>Some simple text</a>"
                "<p><a href='http://www.adp-gmbh.ch/win/misc/mshtml/event_receiver/index.html'>Project's page</a>";
  }
};

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE unused__, LPSTR lpszCmdLine, int nCmdShow) {

  StartTrace("tr");

  EventReceiverInherited event_receiver;
  HTMLWindow* html_window = new HTMLWindow (
   &event_receiver,
   "EventReceiver Test",
   hInstance);

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
