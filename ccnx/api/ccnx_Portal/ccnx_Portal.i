%module (jniclassname="CcnxPortal") test
%{
#include "ccnx_Portal.h"
%}

%include "stdint.i"
%include "typemaps.i"

%apply long int { time_t };
%apply uint64_t *INPUT { CCNxStackTimeout* };

%include "ccnx_Portal.h"

/* Helper Functions */
%inline %{
void ccnxPortal_Release1(CCNxPortal *portalPtr) {
     ccnxPortal_Release(&portalPtr);
}
%}
