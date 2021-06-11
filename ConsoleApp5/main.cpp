#include "pch.h"
#include "winrt\RuntimeComponent1.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace RuntimeComponent1;

int main()
{
    init_apartment();
    Uri uri(L"http://aka.ms/cppwinrt");
    auto sm = Class();
    sm.MyProperty(7);
    auto res = sm.MyProperty();


    printf("Hello, %ls. Answer is:%d!\n", uri.AbsoluteUri().c_str(), res);
}
