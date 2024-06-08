#include "Fuzzy_Manobra_capi_host.h"
static Fuzzy_Manobra_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        Fuzzy_Manobra_host_InitializeDataMapInfo(&(root), "Fuzzy_Manobra");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction(){return(getRootMappingInfo());}
