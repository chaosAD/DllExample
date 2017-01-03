#include "TestDll.h"

/*
   Demonstrates creating a DLL with an exported function in a flexible and
   elegant way.
*/

/* Assign value to exported variables. */
// int foo = 7;
// int bar = 41;

Data myData;

ADDAPI int ADDCALL Add(int a, int b)
// int ADDAPI Add(int a, int b)
{
  return (a + b);
}

/**
 * Store some values in myData
 */
void initData() {
  myData.myInt8a = 12;
  myData.myInt32 = 0xbadface;
  myData.myInt8b = 245;
  myData.myInt16 = -23456;
  myData.myFloat = 1.234567e-23;
  myData.myUint16 = 0xdead;
  myData.myDouble = 9.87654321098e102;
}