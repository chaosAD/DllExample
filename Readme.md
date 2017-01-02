Example of Building DLL and Building An Application That Relies on It
====================================================================

Commands
--------
All available commands can be listed by typing:
```
rake -T
```
Commands for this demonstration are:
```
rake build:dll
rake build:main
rake build:copy
```

Building DLL
------------
To build DLL file, type:
```
rake build:dll
```
which compiles `TestDll.c` into DLL library. All output files are stored in `build/realease/dll/` folder, including the DLL.

Building Application
--------------------
To build the application that relies on the DLL, type:
```
rake build:main
```
which compiles `src/main/main.c` to `build/release/dll/main.exe`. Invoking this command automatically invokes the building of the DLL if necessary.

To execute `main.exe`, type:
```
./build/release/dll/main.exe
```

Calling the function(s) in the DLL in Python
--------------------------------------------
There is a python example script in the `python` folder, which shows how to dynamically load the DLL (that resides in the same directory as the script) and call the `Add()` function. Before running the script, you must build the DLL and copy it into the `python` folder. All this can be done by the following command:
```
rake build:copy
```
To run the python script, type:
```
python python/testme.py
```
The script adds 3 and 67 and then print the result. You will see `70` printed in the console.

Note
----
To run `main.exe` successfully, the `TestDll.dll` should be visible to the program. The simplest way is to place it in the same folder as `main.exe` or do any of the following:
- Move/copy `TestDll.dll` into `Windows/System32` folder
- Include the path to `TestDll.dll` in the system PATH

Limitation
==========
If the script is used together with `Unity Ceedling`, it is best to not use namespaces and task names that have been predefined by the framework. It may conflict with its proper operations, eg. `release`.
