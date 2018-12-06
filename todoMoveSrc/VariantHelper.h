//
// 2018-12-06: Found at https://github.com/ReneNyffenegger/development_misc/blob/master/windows/helpers/VariantHelper.h
//

// See
// http://msdn.microsoft.com/library/default.asp?url=/library/en-us/automat/htm/chap6_7zdz.asp
#include <ObjBase.h>

#include <string>

std::string VariantTypeAsString(const VARIANT& v);
std::string        TypeAsString(VARTYPE);

class variant {
  public:
    variant(VARIANT);
   ~variant();

    std::string ValueAsString();

    void ChangeType(VARTYPE);

  private:
    VARIANT v_;
};

