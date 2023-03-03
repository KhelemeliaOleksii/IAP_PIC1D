##########
# We use #
##########
# GCC C Compiler FLAGS
# See: https://www.rapidtables.com/code/linux/gcc.html
# -Idir -> add include directory of header files
# -c -> compile source files to object files without linking
# -o output file -> write build output to output file
##########
# Automatic Variables
# See: https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# $^ -> The names of all the prerequisites, with spaces between them.
# $@ -> The file name of the target of the rule.
# $< -> The name of the first prerequisite. 
##########
# Functions for String Substitution and Analysis
# See: https://www.gnu.org/software/make/manual/make.html#Search-Algorithm
# $(patsubst pattern,replacement,text)
##########
# Phony Targets
# See: https://www.gnu.org/software/make/manual/make.html#Phony-Targets
# .PHONY -> A phony target is one that is not really the name of a file; 
#           rather it is just a name for a recipe to be executed 
#           when you make an explicit request. 
##########
#           

#Compiler configuration
CC = gcc
CFLAGS = -I${INCDIR}
LIBS = -lm

#Layout configuration
INCDIR = include
OBJDIR = obj
LIBDIR = lib
SRCDIR = src

#Project configuraton
TARGET = run

_DEPS = runModel.h
DEPS = ${patsubst %, ${INCDIR}/%, ${_DEPS}}

_OBJ = main.o runModel.o
OBJ = ${patsubst %, ${OBJDIR}/%, ${_OBJ}}

#Deployment configuration
${TARGET} : ${OBJ}  
	${CC} -o $@ $^ ${CFLAGS} ${LIBS}

${OBJDIR}/%.o: ${SRCDIR}/%.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

.PHONY: clean
clean : 
	rm -f ${OBJDIR}/*.o *~ ${TARGET} ${INCDIR}/*~ *.bak
	
