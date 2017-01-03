from ctypes import *
import os.path

class Data(Structure):
    _fields_ = [('myInt8a', c_char),
                ('myInt32', c_int),
                ('myInt8b', c_char),
                ('myInt16', c_short),
                ('myFloat', c_float),
                ('myUint16', c_ushort),
                ('myDouble', c_double)]

dll_name = "TestDLL.dll"
dllabspath = os.path.dirname(os.path.abspath(__file__)) + os.path.sep + dll_name
myDll = CDLL(dllabspath)

# Call Add() function in TestDLL.dll and print the result
print('Added value = %d\n' % myDll.Add(3, 67))


data = Data.in_dll(myDll, 'myData')
myDll.initData()
print('myInt8a: ' + repr(data.myInt8a))
print('myInt32: 0x%x' % data.myInt32)
print('myInt8b: ' + repr(data.myInt8b))
print('myInt16: %d' % data.myInt16)
print('myFloat: ' + repr(data.myFloat))
print('myInt16: 0x%x' % data.myUint16)
print('myDouble: ' + repr(data.myDouble))
