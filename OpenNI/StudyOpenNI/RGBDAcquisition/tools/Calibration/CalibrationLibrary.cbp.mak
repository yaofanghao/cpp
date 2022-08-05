#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -fPIC
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -Wall -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = ./libCalibrationLibrary.a

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2 -Wall -fPIC
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = ./libCalibrationLibrary.a

OBJ_DEBUG = $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix3x3Tools.o $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix4x4Tools.o $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrixCalculations.o $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/ocvStaging.o $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveHomography.o $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveLinearSystemGJ.o $(OBJDIR_DEBUG)/calibration.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix3x3Tools.o $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix4x4Tools.o $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrixCalculations.o $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/ocvStaging.o $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveHomography.o $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveLinearSystemGJ.o $(OBJDIR_RELEASE)/calibration.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d . || mkdir -p .
	test -d $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix || mkdir -p $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(AR) rcs $(OUT_DEBUG) $(OBJ_DEBUG)

$(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix3x3Tools.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix3x3Tools.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix3x3Tools.c -o $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix3x3Tools.o

$(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix4x4Tools.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix4x4Tools.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix4x4Tools.c -o $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix4x4Tools.o

$(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrixCalculations.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrixCalculations.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrixCalculations.c -o $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrixCalculations.o

$(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/ocvStaging.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/ocvStaging.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/ocvStaging.c -o $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/ocvStaging.o

$(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveHomography.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveHomography.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveHomography.c -o $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveHomography.o

$(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveLinearSystemGJ.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveLinearSystemGJ.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveLinearSystemGJ.c -o $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveLinearSystemGJ.o

$(OBJDIR_DEBUG)/calibration.o: calibration.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c calibration.c -o $(OBJDIR_DEBUG)/calibration.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf .
	rm -rf $(OBJDIR_DEBUG)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d . || mkdir -p .
	test -d $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix || mkdir -p $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(AR) rcs $(OUT_RELEASE) $(OBJ_RELEASE)

$(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix3x3Tools.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix3x3Tools.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix3x3Tools.c -o $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix3x3Tools.o

$(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix4x4Tools.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix4x4Tools.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix4x4Tools.c -o $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrix4x4Tools.o

$(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrixCalculations.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrixCalculations.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrixCalculations.c -o $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/matrixCalculations.o

$(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/ocvStaging.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/ocvStaging.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/ocvStaging.c -o $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/ocvStaging.o

$(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveHomography.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveHomography.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveHomography.c -o $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveHomography.o

$(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveLinearSystemGJ.o: ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveLinearSystemGJ.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../../opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveLinearSystemGJ.c -o $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix/solveLinearSystemGJ.o

$(OBJDIR_RELEASE)/calibration.o: calibration.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c calibration.c -o $(OBJDIR_RELEASE)/calibration.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf .
	rm -rf $(OBJDIR_RELEASE)/__/__/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/src/AmMatrix
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release
