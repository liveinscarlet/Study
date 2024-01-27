# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64

MODEL  = CT_POI
TARGET = cgxe
MODULE_SRCS 	= m_IMv9yOrM7PumNuduIww3wH.c
MODEL_SRC	= CT_POI_cgxe.c
MODEL_REG = CT_POI_cgxe_registry.c
MAKEFILE    = CT_POI_cgxe.mak
MATLAB_ROOT	= D:\Matlab2023
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------


USER_INCLUDES   =  /I "D:\Учеба\Study\Study\навигация\Лаб3\ЛР3\slprj\_cgxe\CT_POI\src" /I "D:\Учеба\Study\Study\навигация\Лаб3\ЛР3" /I "D:\Учеба\Study\Study\Навигация\Лаб3\ЛР3\slprj\_cprj"

MLSL_INCLUDES     = \
    /I "D:\Matlab2023\extern\include" \
    /I "D:\Matlab2023\simulink\include" \
    /I "D:\Matlab2023\rtw\c\src"
COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   =  /I "D:\Учеба\Study\Study\Навигация\Лаб3\ЛР3\slprj\_cgxe\CT_POI\src" /I "D:\Учеба\Study\Study\Навигация\Лаб3\ЛР3"
INCLUDE_PATH = $(MLSL_INCLUDES) $(USER_INCLUDES) $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"
CFLAGS = /c /Zp8 /GR /w /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMX_COMPAT_64 /DMATLAB_MEXCMD_RELEASE=R2018a /DMATLAB_MEX_FILE /nologo /MD 
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction /export:mexfilerequiredapiversion
#----------------------------- Source Files -----------------------------------

USER_OBJS =

AUX_SRCS = D:\Matlab2023\extern\version\c_mexapi_version.c  

REQ_SRCS  = $(MODEL_SRC) $(MODEL_REG) $(MODULE_SRCS) $(AUX_SRCS)
REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_OBJS) $(AUX_ABS_OBJS)
OBJLIST_FILE = CT_POI_cgxe.mol
TMWLIB = "D:\Matlab2023\extern\lib\win64\microsoft\libmx.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libmex.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libmat.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libfixedpoint.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libut.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libmwmathutil.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libemlrt.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libmwcgxert.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libmwcgxeooprt.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libmwslexec_simbridge.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libmwslccrt.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libmwstringutil.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libcovrt.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libmwsl_sfcn_cov_bridge.lib" "D:\Matlab2023\extern\lib\win64\microsoft\libmwdsp_halidesim.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MODEL)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
all : $(MEX_FILE_NAME) 


$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS)
	@echo ### Linking ...
	$(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map" $(TMWLIB) $(THIRD_PARTY_LIBS) @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

