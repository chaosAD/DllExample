#ifndef TestDll_H
#define TestDll_H

typedef struct Data Data;
struct Data {
  char myInt8a;
  int myInt32;
  char myInt8b;
  short int myInt16;
  float myFloat;
  unsigned short int myUint16;
  double myDouble;
};

/*
    You should define BUILD_DLL *only* when building the DLL.
 */
#ifdef BUILD_DLL
  // Define calling convention in one place, for convenience.
# define ADDCALL __cdecl

  /*
   Declares the functions to be imported by our application, and exported by our
   DLL, in a flexible and elegant way.
  */
# ifdef ADD_EXPORTS
#   define ADDAPI __declspec(dllexport)
# else  // ...otherwise is import
#   define ADDAPI __declspec(dllimport)
# endif
#else
  // Just ignore ADDAPI and ADDCALL, since not building DLL.
# define ADDAPI
# define ADDCALL
#endif


/* Make sure functions are exported with C linkage under C++ compilers. */
#ifdef __cplusplus
extern "C"
{
#endif

/* Declare our Add function using the above definitions. */
ADDAPI int ADDCALL Add(int a, int b);
ADDAPI void ADDCALL initData(void);

/* Exported variables. */
extern Data myData;
// extern ADDAPI int bar;

#ifdef __cplusplus
} // __cplusplus defined.
#endif

#endif // TestDll_H
