# OUTPUT
EXENAME=h_pT
LIBNAME=IF97

OUTPUT_DIR = ./

WINLIB = -Wl,--output-def,$(LIBNAME).def,--out-implib,$(LIBNAME).lib
DEFINE = -D IF97EXPORTS
LIBOUT = -shared -o $(OUTPUT_DIR)$(LIBNAME).dll $(WINLIB) $(DEFINE)

EXEOUT = $(LIBNAME).lib -o $(OUTPUT_DIR)$(EXENAME).exe

# Debug: -g Profiling: -pg Performance: -O2
EXECODE = $(EXENAME).cpp
LIBCODE = $(LIBNAME).cpp
CFLAGS = -I./ -O2
CPP = g++

all: 
	@echo ""
	@echo "***** Building IAPW IF97 *****"
	@echo ""

	$(CPP) $(CFLAGS) $(LIBCODE) $(LIBOUT)

exe: 
	@echo ""
	@echo "***** Building Example *****"
	@echo ""

	$(CPP) $(CFLAGS) $(EXECODE) $(EXEOUT)

clean:
	del *.a
	del *.o
	del *.dll
	del *.def
	del *.exe
	del *.lib
	del *.csv
