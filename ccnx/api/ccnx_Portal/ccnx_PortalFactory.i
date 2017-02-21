%module (jniclassname="CcnxPortalFactory") test
%{
#include "ccnx_PortalFactory.h"
#include "ccnx_PortalRTA.h"
%}

%include "ccnx_PortalFactory.h"

/* Helper Functions */
%inline %{
void ccnxPortalFactory_Release1(CCNxPortalFactory *factoryPtr) {
     ccnxPortalFactory_Release(&factoryPtr);
}

CCNxPortal *ccnxPortalFactory_CreatePortal1(const CCNxPortalFactory *factory) {
    return ccnxPortalFactory_CreatePortal(factory, ccnxPortalRTA_Message);
}
%}
