CC = gcc
Ar = ar
HEADER = hello_Ariel.h
MAINFUNC = hello_Ariel.c
LIBa = libhello_ariel.a
LIBso = libhello_Ariel.so
FLAGS = -Wall -g

all: main1_1 main1_2 main1_3 hello_Arield

main1_1: $(HEADER) $(MAINFUNC) main1_1.c 
	$(CC) $(FLAGS) $(MAINFUNC) main1_1.c -o main1_1

hello_Arield: $(HEADER) $(MAINFUNC)
	$(CC) -shared $(MAINFUNC) -fPIC -o $(LIBso)

main1_2: $(HEADER) $(MAINFUNC) hello_Arield
	$(CC) $(FLAGS) main1_1.c -L. -l hello_Ariel -o main1_2 

main1_3: $(HEADER) main1_3.c hello_Arield
	$(CC) $(FLAGS) main1_3.c -fPIC -ldl -o main1_3	

.PHONY: clean all 

clean:
	rm -f *.o main1_1 main1_2 main1_3 $(LIBso) $(LIBa)


	




