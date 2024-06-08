#ifndef RTW_HEADER_Fuzzy_Manobra_cap_host_h__
#define RTW_HEADER_Fuzzy_Manobra_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap_simtarget.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
Fuzzy_Manobra_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void Fuzzy_Manobra_host_InitializeDataMapInfo (
Fuzzy_Manobra_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
