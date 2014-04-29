#########################################################################################
# MAKEFILE for server									#
#											#
# Written By Josh Harshman								#
# April 23, 2014									#
#											#
# Functions:										#
#											#
# make <no args> - compiles and executes the program					#
# make <only> - compiles the program							#
# make <clean> - removes the compiled program						#
# make <cleanrun> - removes the compiled program, compiles, and executes		#
#											#
#########################################################################################


./startserver:	src/main.c
		gcc -pthread src/handler.c src/main.c -o startserver
		./startserver

only:		src/main.c
		gcc -pthread src/handler.c src/main.c -o startserver

clean:		
		rm -rf startserver

cleanrun:	src/main.c
		rm -rf startserver
		gcc -pthread src/handler.c src/main.c -o startserver
		./startserver

#end
