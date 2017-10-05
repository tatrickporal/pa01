all	:	graph01.c intVec.c intVec.h
		gcc -o graph01 graph01.c intVec.c 

graph01 : graph01.c intVec.c intVec.h
		gcc -c graph01.c intVec.c

clean :
		rm graph01 graph01.o intVec.o
         
