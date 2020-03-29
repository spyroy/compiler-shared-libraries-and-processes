#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <stddef.h>

void(*messege)(const char*);

bool init_lib(){
    void *hdl = dlopen("./libhello_Ariel.so", RTLD_LAZY);
    if(hdl == NULL){
        return false;
    }
    messege = (void(*)(const char *))dlsym(hdl,"my_print");
    if(messege == NULL){
        return false;
    }
    return true;
}

int main(){
    if(init_lib()){
        messege("Ariel");
    }
    else{
        printf("library was not loaded\n");
    }
    return 0;
}