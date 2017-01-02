from ctypes import *
import os.path

dll_name = "TestDLL.dll"
dllabspath = os.path.dirname(os.path.abspath(__file__)) + os.path.sep + dll_name
myDll = CDLL(dllabspath)

# Call Add() function in TestDLL.dll and print the result
print(myDll.Add(3, 67))
