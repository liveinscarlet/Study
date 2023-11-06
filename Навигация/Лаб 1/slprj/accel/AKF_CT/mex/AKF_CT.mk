﻿# Copyright 1994-2022 The MathWorks, Inc.
#
#
# Abstract:
#       Template makefile for building a Windows-based stand-alone embedded
#       real-time version of Simulink model using generated C code and the
#          Microsoft Visual C/C++ compiler for x64.
#
#       Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#         OPT_OPTS       - Optimization option. See DEFAULT_OPT_OPTS in
#                          vctools.mak for default.
#         OPTS           - User specific options.
#         CPP_OPTS       - C++ compiler options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set DEBUG_BUILD = 1, which will trigger OPTS=-Zi (may vary with
#                               compiler version, see compiler doc) 
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see ert.tlc


#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = nmake
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = any
BUILD_SUCCESS	= ^#^#^# Created

# Opt in to simplified format by specifying compatible Toolchain
TOOLCHAIN_NAME = [\
    "Microsoft Visual C++ 2022 v17.0 | nmake (64-bit Windows)", \
    "Microsoft Visual C++ 2019 v16.0 | nmake (64-bit Windows)", \
    "Microsoft Visual C++ 2017 v15.0 | nmake (64-bit Windows)"]

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  NUMST               - Number of sample times
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  INTEGER_CODE        - yes (1) or no (0): Is generated code purely integer
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done,
#                        if 0, the generated code runs indefinitely
#  MULTI_INSTANCE_CODE - Is the generated code multi instantiable (1/0)?
#  MODELREFS           - List of referenced models
#  SHRLIBTARGET        - Is this build intended for generation of a shared library instead 
#                        of executable (1/0)?
#  MAKEFILEBUILDER_TGT - Is this build performed by the MakefileBuilder class
#                        e.g. to create a PIL executable?
#  STANDALONE_SUPPRESS_EXE - Build the standalone target but only create object code modules 
#                            and do not build an executable

MODEL                   = AKF_CT
MODULES                 = AKF_CT_acc.c AKF_CT_acc_data.c c_mexapi_version.c
PRODUCT                 = $(RELATIVE_PATH_TO_ANCHOR)\AKF_CT_acc.mexw64
MAKEFILE                = AKF_CT.mk
MATLAB_ROOT             = D:\Matlab2023
ALT_MATLAB_ROOT         = D:\Matlab2023
START_DIR               = D:\Учеба\Study\Study\Навигация\Лаб 1
S_FUNCTIONS_LIB         = 
NUMST                   = 7
NCSTATES                = 0
BUILDARGS               =  OPTS="-DTID01EQ=0"
MULTITASKING            = 0
INTEGER_CODE            = 0
MAT_FILE                = 0
ALLOCATIONFCN           = 0
ONESTEPFCN              = 0
TERMFCN                 = 1
ENABLE_SLEXEC_SSBRIDGE  = 0
MULTI_INSTANCE_CODE     = 0
CLASSIC_INTERFACE       = 1
MODELREFS               = 
TARGET_LANG_EXT         = c
SHRLIBTARGET            = 1
MAKEFILEBUILDER_TGT     = 0
STANDALONE_SUPPRESS_EXE = 0
OPTIMIZATION_FLAGS      = /DNDEBUG /Od /Oy-
ADDITIONAL_LDFLAGS      =  /IMPLIB:AKF_CT_acc.lib /EXPORT:mexFunction /EXPORT:mexfilerequiredapiversion
INTERLEAVED_COMPLEX_FLAGS = -R2018a
DEFINES_CUSTOM          = 
DEFINES_OTHER           = -DHAVESTDIO -DMDL_REF_SIM_TGT=1 -DMATLAB_MEX_FILE -DMATLAB_DEFAULT_RELEASE=R2018a
COMPILE_FLAGS_OTHER     = /wd4701 /wd4100 /wd4189 /wd4090 /wd4505
SYSTEM_LIBS             = /LIBPATH:"D:\Matlab2023\extern\lib\win64\microsoft" libmwipp.lib libut.lib libmwmathutil.lib libmwsl_simtarget_instrumentation.lib libmwsl_simtarget_core.lib libmwsl_fileio.lib libmwsigstream.lib libmwslexec_simlog.lib libmwsl_AsyncioQueue.lib sf_runtime.lib libmwsimulink.lib libmwslexec_simbridge.lib libmwstringutil.lib libemlrt.lib libmwslio_core.lib libmwslio_clients.lib libmwsl_services.lib libmx.lib libmex.lib
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD             = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = AKF_CT_acc.mexw64
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = AKF_CT_ref.rsp
COMPILER_COMMAND_FILE     = AKF_CT_comp.rsp
RELATIVE_PATH_TO_ANCHOR   = ..\..\..\..
MODELREF_TARGET_TYPE      = NONE

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif

#--------------------------- Tool Specifications ------------------------------
!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak

CMD_FILE             = $(MODEL).rsp

#------------------------------ Include/Lib Path ------------------------------

INCLUDE = .;$(RELATIVE_PATH_TO_ANCHOR);$(INCLUDE)

#----------------- Compiler and Linker Options --------------------------------

# Optimization Options
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
!if "$(DEBUG_BUILD)" == "0"
DBG_FLAG =
!else
#   Set OPT_OPTS=-Zi and any additional flags for debugging
DBG_FLAG = -Zi
!endif

!if "$(OPTIMIZATION_FLAGS)" != ""
CC_OPTS = $(OPTS) $(COMPILE_FLAGS_OTHER) $(OPTIMIZATION_FLAGS)
!else
CC_OPTS = $(OPTS) $(COMPILE_FLAGS_OTHER) $(OPT_OPTS) 
!endif

# Defines
CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DNUMST=$(NUMST) -DNCSTATES=$(NCSTATES) \
		  -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DHAVESTDIO -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		  -DCLASSIC_INTERFACE=$(CLASSIC_INTERFACE) \
		  -DALLOCATIONFCN=$(ALLOCATIONFCN) \
		  $(DEFINES_CUSTOM) $(DEFINES_OTHER)

!if "$(MODELREF_TARGET_TYPE)" == "SIM"
!if "$(ENABLE_SLEXEC_SSBRIDGE)" != "0"
CPP_REQ_DEFINES = $(CPP_REQ_DEFINES) -DENABLE_SLEXEC_SSBRIDGE=$(ENABLE_SLEXEC_SSBRIDGE)
!endif
!else
CPP_REQ_DEFINES = $(CPP_REQ_DEFINES) -DMT=$(MULTITASKING)
!endif

CPP_REQ_DEFINES = $(CPP_REQ_DEFINES) -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=$(MODEL_HAS_DYNAMICALLY_LOADED_SFCNS)

CVARSFLAG = $(cvarsdll)

CFLAGS = $(cflags) @$(COMPILER_COMMAND_FILE) $(CVARSFLAG) \
	 -D_CRT_SECURE_NO_WARNINGS $(DBG_FLAG) $(CC_OPTS) $(CPP_REQ_DEFINES) \
	 $(USER_INCLUDES)

CPPFLAGS = $(cflags) @$(COMPILER_COMMAND_FILE) $(CVARSFLAG) \
	   -EHs -D_CRT_SECURE_NO_WARNINGS $(DBG_FLAG) $(CPP_OPTS) $(CC_OPTS) \
	   $(CPP_REQ_DEFINES) $(USER_INCLUDES)

LDFLAGS = $(ldebug) $(conflags) $(conlibs) $(ADDITIONAL_LDFLAGS)

#----------------------------- Source Files -----------------------------------

ADD_SRCS =

SRCS = $(ADD_SRCS) $(MODULES) $(USER_SRCS)

USER_SRCS =


OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)

#-------------------------- Additional Libraries -------------------------------

LIBS = 


LIBS = $(LIBS) $(S_FUNCTIONS_LIB)

#--------------------------------- Rules --------------------------------------
all: set_environment_variables $(PRODUCT)

!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Shared library target (.dll) ---
!if $(SHRLIBTARGET)==1
$(PRODUCT) : $(LIBS) $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(LD) $(LDFLAGS) $(LIBS) $(SYSTEM_LIBS) \
    @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) -dll -def:$(MODEL).def -out:$@
	@cmd /C "echo $(BUILD_SUCCESS) dynamically linked library  $(PRODUCT)"
!else
!if $(MAKEFILEBUILDER_TGT)==1
PREBUILT_SRCS  = $(MODULES)
PREBUILT_OBJS_CPP_UPPER = $(PREBUILT_SRCS:.CPP=.obj)
PREBUILT_OBJS_CPP_LOWER = $(PREBUILT_OBJS_CPP_UPPER:.cpp=.obj)
PREBUILT_OBJS_C_UPPER = $(PREBUILT_OBJS_CPP_LOWER:.C=.obj)
PREBUILT_OBJS = $(PREBUILT_OBJS_C_UPPER:.c=.obj)
$(PRODUCT) : $(LIBS) $(PREBUILT_OBJS) $(OBJS) $(MODELLIB) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(LD) $(LDFLAGS) $(MODELLIB) $(LIBS) $(PREBUILT_OBJS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) -out:$@
	@cmd /C "echo $(BUILD_SUCCESS) executable $(PRODUCT)"
!else
!if $(STANDALONE_SUPPRESS_EXE)==1
#  Build object code only for top level model
.PHONY: $(PRODUCT)
$(PRODUCT) : $(LIBS) $(OBJS) $(LIBS)
	@cmd /C "echo $(BUILD_SUCCESS) object modules $(PRODUCT)"
!else
#--- Stand-alone model (.exe) ---
$(PRODUCT) : $(LIBS) $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(LD) $(LDFLAGS) $(LIBS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) $(SYSTEM_LIBS) -out:$@
	@cmd /C "echo $(BUILD_SUCCESS) executable $(PRODUCT)"
!endif
!endif
!endif
!else
#--- Library target ---
$(PRODUCT) : $(LIBS) $(OBJS) 
	@cmd /C "echo ### Linking ..."
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE)
	@cmd /C "echo  $(BUILD_SUCCESS) static library $(MODELLIB)"
!endif	


#-------------------------- Support for building modules ----------------------
AKF_CT_acc.obj : $(START_DIR)\slprj\accel\AKF_CT\AKF_CT_acc.c
	@cmd /C "echo ### Compiling $(START_DIR)\slprj\accel\AKF_CT\AKF_CT_acc.c
	$(CC) $(CFLAGS) $(START_DIR)\slprj\accel\AKF_CT\AKF_CT_acc.c

AKF_CT_acc_data.obj : $(START_DIR)\slprj\accel\AKF_CT\AKF_CT_acc_data.c
	@cmd /C "echo ### Compiling $(START_DIR)\slprj\accel\AKF_CT\AKF_CT_acc_data.c
	$(CC) $(CFLAGS) $(START_DIR)\slprj\accel\AKF_CT\AKF_CT_acc_data.c

c_mexapi_version.obj : $(MATLAB_ROOT)\extern\version\c_mexapi_version.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\extern\version\c_mexapi_version.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\extern\version\c_mexapi_version.c






# Put these rules last, otherwise nmake will check toolboxes first

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

# Libraries:






#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) 
