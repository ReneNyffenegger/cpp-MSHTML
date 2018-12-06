/*
   Storage.h

   Copyright (C) 2003-2004 René Nyffenegger

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

class Storage : public IStorage {
  HRESULT STDMETHODCALLTYPE QueryInterface( REFIID /*riid*/, LPVOID FAR* /*ppvObj*/) { MUST_BE_IMPLEMENTED("QueryInterface") }

  ULONG STDMETHODCALLTYPE AddRef() { return(1); }

  ULONG STDMETHODCALLTYPE Release() { return(1); }

  HRESULT STDMETHODCALLTYPE CreateStream(
      const WCHAR *  /*pwcsName*/,
      DWORD          /*grfMode*/,
      DWORD          /*reserved1*/,
      DWORD          /*reserved2*/,
      IStream **     /*ppstm*/
      ) { MUST_BE_IMPLEMENTED("CreateStream") }

  HRESULT STDMETHODCALLTYPE OpenStream(
      const WCHAR* /*pwcsName*/,
      void*        /*reserved1*/,
      DWORD        /*grfMode*/,
      DWORD        /*reserved2*/,
      IStream**    /*ppstm*/
      ) { MUST_BE_IMPLEMENTED("OpenStream") }

  HRESULT STDMETHODCALLTYPE CreateStorage(
      const WCHAR* /*pwcsName*/,
      DWORD        /*grfMode*/,
      DWORD        /*reserved1*/,
      DWORD        /*reserved2*/,
      IStorage**   /*ppstg*/) {
    MUST_BE_IMPLEMENTED("CreateStorage") }

  HRESULT STDMETHODCALLTYPE OpenStorage(
      const WCHAR*   /*pwcsName*/,
      IStorage*      /*pstgPriority*/,
      DWORD          /*grfMode*/,
      SNB            /*snbExclude*/,
      DWORD          /*reserved*/,
      IStorage**     /*ppstg*/
      ) { MUST_BE_IMPLEMENTED("OpenStorage") }

  HRESULT STDMETHODCALLTYPE CopyTo(
      DWORD       /*ciidExclude*/,
      IID const*  /*rgiidExclude*/,
      SNB         /*snbExclude*/,
      IStorage*   /*pstgDest*/)
  { MUST_BE_IMPLEMENTED("CopyTo") }

  HRESULT STDMETHODCALLTYPE MoveElementTo(
      const OLECHAR* /*pwcsName*/,
      IStorage*      /*pstgDest*/,
      const OLECHAR* /*pwcsNewName*/,
      DWORD          /*grfFlags*/
      ) { MUST_BE_IMPLEMENTED("MoveElementTo") }

  HRESULT STDMETHODCALLTYPE Commit(DWORD /*grfCommitFlags*/) { MUST_BE_IMPLEMENTED("Commit") }

  HRESULT STDMETHODCALLTYPE Revert() { MUST_BE_IMPLEMENTED("Revert") }

  HRESULT STDMETHODCALLTYPE EnumElements(
      DWORD          /*reserved1*/,
      void*          /*reserved2*/,
      DWORD          /*reserved3*/,
      IEnumSTATSTG** /*ppenum*/) { MUST_BE_IMPLEMENTED("EnumElements") }

  HRESULT STDMETHODCALLTYPE DestroyElement(const OLECHAR* /*pwcsName*/) { MUST_BE_IMPLEMENTED("DestroyElement") }

  HRESULT STDMETHODCALLTYPE RenameElement(const WCHAR* /*pwcsOldName*/, const WCHAR* /*pwcsNewName*/) { MUST_BE_IMPLEMENTED("RenameElement") }

  HRESULT STDMETHODCALLTYPE SetElementTimes(
      const WCHAR*    /*pwcsName*/,
      FILETIME const* /*pctime*/,
      FILETIME const* /*patime*/,
      FILETIME const* /*pmtime*/)
  { MUST_BE_IMPLEMENTED("SetElementTimes") }

  HRESULT STDMETHODCALLTYPE SetClass(REFCLSID /*clsid*/) {
    TraceFunc("Storage::SetGlass");
    return S_OK;}

  HRESULT STDMETHODCALLTYPE SetStateBits(DWORD /*grfStateBits*/, DWORD /*grfMask*/)
  { MUST_BE_IMPLEMENTED("SetStateBits") }

  HRESULT STDMETHODCALLTYPE Stat(STATSTG* /*pstatstg*/, DWORD /*grfStatFlag*/) { MUST_BE_IMPLEMENTED("Stat") }
};
