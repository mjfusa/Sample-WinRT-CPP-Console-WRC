#include "pch.h"
#include "winrt\RuntimeComponent4.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace RuntimeComponent4;

int main()
{
    init_apartment();
    Uri uri(L"http://aka.ms/cppwinrt");
    auto sm = Class();
    sm.MyProperty(7);
    auto res = sm.MyProperty();

        
    printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());
}
