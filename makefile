CC = gcc
Ar = ar
MAINOBJECTS = main1_1.o
LIBOBJECTS = hello_Ariel.o
LIBa = libhello_ariel.a
LIBso = libhello_Ariel.so
FLAGS = -Wall -g

all: main1_1 hello_Arield

main1_1: $(MAINOBJECTS) 
	 $(CC) $(FLAGS) hello_Ariel.c main1_1.c -o main1_1

hello_Arield: $(LIBOBJECTS)
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) -fPIC $(FLAGS) -c hello_Ariel.c	 

# hello_Ariels: $(LIBOBJECTS)
 	# $(Ar) -rcs $(LIBa) $(LIBOBJECTS)	

# main1_1.o: hello_Ariel.c hello_Ariel.h
#  	$(CC) $(FLAGS) -c hello_Ariel.c	

# main1_1s: $(MAINOBJECTS) $(liba)
# 	$(CC) $(FLAGS) -o main1_1s $(MAINOBJECTS) $(LIBa)
# main1_1d: $(MAINOBJECTS)
# 	$(CC) $(FLAGS) -o main1_1d $(MAINOBJECTS) ./$(LIBso)	




# .PHONY: clean all main1_1d main1_1s

# clean:
# 	rm -f *.o main1_1s main1_1d $(LIBso) $(LIBa)