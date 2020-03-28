CC = gcc
Ar = ar
MAINOBJECTS = main1_1.o
LIBOBJECTS = hello_Ariel.o
LIBa = libhello_ariel.a
LIBso = libhello_Ariel.so
FLAGS = -Wall -g

all: main1_1 main1_2 main1_3 hello_Arield

main1_1: $(MAINOBJECTS) 
	$(CC) $(FLAGS) hello_Ariel.c main1_1.c -o main1_1

hello_Arield: $(LIBOBJECTS)
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) -fPIC $(FLAGS) -c hello_Ariel.c

main1_2: $(LIBso)
	$(CC) $(FLAGS) main1_2.c -o main1_2 

main1_3: $(LIBso)
	$(CC) $(FLAGS) -o main1_3 $(MAINOBJECTS) ./$(LIBso)	

.PHONY: clean all 

clean:
	rm -f *.o main1_1 main1_2 main1_3 $(LIBso) $(LIBa)



# main1_2.o: hello_Ariel.c hello_Ariel.h
#    	$(CC) $(FLAGS) -c hello_Ariel.c	 

# hello_Ariels: $(LIBOBJECTS)
 	# $(Ar) -rcs $(LIBa) $(LIBOBJECTS)	

	

# main1_1s: $(MAINOBJECTS) $(liba)
# 	$(CC) $(FLAGS) -o main1_1s $(MAINOBJECTS) $(LIBa)
	




