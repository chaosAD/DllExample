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
rake release:Dll
rake release:main
```

Building DLL
------------
To build DLL file, type:
```
rake build:dll
```
which compiles `TestDll.c` into its DLL file. All output files are stored in `build/realease/dll` folder. 

Building Application
--------------------
To build the application that relies on the DLL, type:
```
rake release:main
```
which will compiles `src/main/main.c` to `build/realease/dll/main.exe`. Invoking this command automatically invokes the building of the DLL if necessary.

To execute `main.exe`, type:
```
./build/realease/dll/main.exe
```

Note
----
To run `main.exe` successfully, the `TestDll.dll` should be visible to Bash. The simplest way is to place it in the same folder as `main.exe`. 