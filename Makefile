all: MSHTMLTest.exe DisplayHTML.exe EventReceiverTest.exe

GCC_OPTS=-DDO_TRACE

DisplayHTML.exe: DisplayHTML.o HTMLWindow.o DocHostUiHandler.o OleClientSite.o OleInPlaceSite.o win32_Unicode.o VariantHelper.o UrlHelper.o Tracer.o stdHelpers.o
	g++ -mwindows -o $@ $^ -luuid -loleaut32 -lole32 

MSHTMLTest.exe: MSHTMLTest.o HTMLWindow.o DocHostUiHandler.o OleClientSite.o OleInPlaceSite.o win32_Unicode.o VariantHelper.o UrlHelper.o Tracer.o stdHelpers.o
	g++ -mwindows -o $@ $^ -luuid -loleaut32 -lole32 

EventReceiverTest.exe: EventReceiverTest.o HTMLWindow2.o DocHostUiHandler.o OleClientSite.o OleInPlaceSite.o win32_Unicode.o VariantHelper.o UrlHelper.o Tracer.o stdHelpers.o
	g++ -mwindows -o $@ $^ -luuid -loleaut32 -lole32 

EventReceiverTest.o: EventReceiverTest.cpp HTMLWindow.h OleClientSite.h todoMoveSrc/Tracer.h OleInPlaceSite.h OleInPlaceFrame.h DocHostUiHandler.h 
	g++ $(GCC_OPTS) -c $<

DisplayHTML.o: DisplayHTML.cpp HTMLWindow.h OleClientSite.h todoMoveSrc/Tracer.h OleInPlaceSite.h OleInPlaceFrame.h DocHostUiHandler.h 
	g++ $(GCC_OPTS) -c $<

MSHTMLTest.o: MSHTMLTest.cpp HTMLWindow.h OleClientSite.h todoMoveSrc/Tracer.h OleInPlaceSite.h OleInPlaceFrame.h DocHostUiHandler.h
	g++ $(GCC_OPTS) -c $<

HTMLWindow.o: HTMLWindow.cpp HTMLWindow.h OleClientSite.h todoMoveSrc/Tracer.h OleInPlaceSite.h OleInPlaceFrame.h DocHostUiHandler.h Storage.h todoMoveSrc/VariantHelper.h todoMoveSrc/win32_Unicode.h todoMoveSrc/UrlHelper.h
	g++ $(GCC_OPTS) -c $<

HTMLWindow2.o: HTMLWindow2.cpp HTMLWindow2.h OleClientSite.h todoMoveSrc/Tracer.h OleInPlaceSite.h OleInPlaceFrame.h DocHostUiHandler.h Storage.h todoMoveSrc/VariantHelper.h todoMoveSrc/win32_Unicode.h todoMoveSrc/UrlHelper.h
	g++ $(GCC_OPTS) -c $<

DocHostUiHandler.o: DocHostUiHandler.cpp DocHostUiHandler.h HTMLWindow.h OleClientSite.h todoMoveSrc/Tracer.h OleInPlaceSite.h OleInPlaceFrame.h todoMoveSrc/UrlHelper.h
	g++ $(GCC_OPTS) -c $<

OleInPlaceSite.o: OleInPlaceSite.cpp OleInPlaceSite.h
	g++ $(GCC_OPTS) -c $<

OleClientSite.o: OleClientSite.cpp OleClientSite.h todoMoveSrc/Tracer.h
	g++ $(GCC_OPTS) -c $<

win32_Unicode.o: todoMoveSrc\win32_Unicode.cpp todoMoveSrc\win32_Unicode.h
	g++ $(GCC_OPTS) -c $<

VariantHelper.o: todoMoveSrc\VariantHelper.cpp todoMoveSrc\VariantHelper.h
	g++ $(GCC_OPTS) -c $<

UrlHelper.o: todoMoveSrc\UrlHelper.cpp todoMoveSrc\UrlHelper.h
	g++ $(GCC_OPTS) -c $<

Tracer.o: todoMoveSrc\Tracer.cpp todoMoveSrc\Tracer.h
	g++ $(GCC_OPTS) -c $<

stdHelpers.o: todoMoveSrc\stdHelpers.cpp todoMoveSrc\stdHelpers.h
	g++ $(GCC_OPTS) -c $<

clean:
	@del *.o
