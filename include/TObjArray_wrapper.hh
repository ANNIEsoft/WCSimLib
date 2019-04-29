#ifndef TObj_Array_wrapper
#define TObj_Array_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    TObjArray_wrapper                                                 //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObjArray.h"

class TObjArray_wrapper : public TObjArray{
	public:
	TObjArray_wrapper(int a, int b) : TObjArray(a,b){};
	TObjArray_wrapper(const TObjArray &a) : TObjArray(a){};
	ClassDef(TObjArray_wrapper,1)
};

#endif
