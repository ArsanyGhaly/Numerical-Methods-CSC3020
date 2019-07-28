AutomatedMakefile = am
CC = g++

FILES_1 = Point.o SortPoints.o ClosestData.o PolyInterpolation.o PolyInterpolationDriver.o
FILES_2 = Point.o PolyRegression.o PolyRegressionDriver.o

PROJECT_PATH = $(PROJECT_PATH)

INC_DIRS = -I$(PROJECT_PATH)/include/
LIB_DIRS = -L$(PROJECT_PATH)/lib/
LIBS = -lCSC2110

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o

all: PolyInterpolation PolyRegression

PolyInterpolation: 	$(FILES_1)
			$(LINK) PolyInterpolation.exe $(FILES_1) $(LIBS)

PolyRegression: 	$(FILES_2)
			$(LINK) PolyRegression.exe $(FILES_2) $(LIBS)

Point.o:		Point.h Point.cpp
			$(COMPILE) Point.cpp

SortPoints.o:		SortPoints.h SortPoints.cpp
			$(COMPILE) SortPoints.cpp

ClosestData.o:		ClosestData.h ClosestData.cpp
			$(COMPILE) ClosestData.cpp

PolyInterpolation.o:		PolyInterpolation.h PolyInterpolation.cpp
				$(COMPILE) PolyInterpolation.cpp

PolyInterpolationDriver.o:	PolyInterpolationDriver.cpp
				$(COMPILE) PolyInterpolationDriver.cpp

PolyRegression.o:		PolyRegression.h PolyRegression.cpp
				$(COMPILE) PolyRegression.cpp

PolyRegressionDriver.o:		PolyRegressionDriver.cpp
				$(COMPILE) PolyRegressionDriver.cpp




