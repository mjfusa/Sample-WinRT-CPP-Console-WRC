## Sample - Windows Console Application C++/WinRT with Windows Runtime Component (UWP)

##### This sample documents the issues and fixes when adding a Windows Runtime Component (C++/WinRT) to a (C++/WinRT) console app.

Prerequisites:

1. Create a Windows Console Application (C++/WinRT)

2. Create a Windows Runtime Component (C++/WinRT)

3. Add a reference to the Windows Runtime Component
 

Error:
```
A reference to 'RuntimeComponent4' cannot be added because the two projects target different platforms. 
```

Fix:

Browse to the location of the winmd and add it. For example:

```
..\RuntimeComponent4\Debug\Merged\RuntimeComponent4.winmd
```
4.  Add the code to include the class in the Windows Runtime Component. For example:

```
#include "winrt\RuntimeComponent4.h"
using namespace RuntimeComponent4;
. . . 

int main()
{
    init_apartment();
    Uri uri(L"http://aka.ms/cppwinrt");
    auto sm = Class();
    sm.MyProperty(7);
    auto res = sm.MyProperty();
    printf("Hello, %ls. Answer is:%d!\n", uri.AbsoluteUri().c_str(), res);
}
```
Error:

![Exception](error2.png)

Fix:

a. Copy the output folder of the Windows Runtime Component to the same output folder for the console app. For example:

```
Copy  ConsoleApp5\Debug\RuntimeComponent1\*.* to ConsoleApp5\Debug
```

You should have the Runtime Component DLL and other files now in the same folder as the console app.

b. Add the NuGet package **Microsoft.VCRTForwarders.140** to the console app. 

You need the VCRTForwarders package since you are using a Windows Runtime Component which has a dependency on the *Windows Store* versions of the VC libraries which are not in a location which can be found by non-Store apps. VCRTForwarders forwards the VC library calls to the Store version of the runtime dlls. More information here: [Enhancing Non-packaged Desktop Apps using Windows Runtime Components](https://blogs.windows.com/windowsdeveloper/2019/04/30/enhancing-non-packaged-desktop-apps-using-windows-runtime-components/)

You will now be able to run the console app and call the Windows Runtime Component.


