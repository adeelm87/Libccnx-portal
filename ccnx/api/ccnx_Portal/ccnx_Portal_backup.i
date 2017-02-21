%module (jniclassname="CcnxPortal") test
%{
#include "ccnx_Portal.h"
%}

%apply long int { time_t };

%include "ccnx_Portal.h"

bool ccnxPortal_Send1(CCNxPortal *restrict portal, const CCNxMetaMessage *restrict message);
CCNxMetaMessage *ccnxPortal_Receive1(CCNxPortal *portal);
