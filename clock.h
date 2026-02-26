#include <time.h>
int return_sec(void);
int return_min(void);
int return_hour(void);
int return_bin(int data);
int sec(void);
int min(void);
int hour(void);
#if defined(CLOCK_IMPLEMENTATION)
int return_sec(){
    time_t now = time(NULL);      
    struct tm *t = localtime(&now);  
    return t->tm_sec;
}
int return_min(){
    time_t now = time(NULL);      
    struct tm *t = localtime(&now);    
   return t->tm_min;
}

int return_hour(){
    time_t now = time(NULL);      
    struct tm *t = localtime(&now);  
    return t->tm_hour;
}

int return_bin(int data) {
    int remainder,result = 0,multiplier = 1;
    int input=data;
    
    while(input){
        remainder = input%2;
        result = remainder*multiplier + result;
        multiplier*=10;
        input/=2;
    }
    return result;}
    int sec(){
   
    return return_sec();
}
int min(){
   
    return return_min();
}
int hour(){
   
    return return_hour();
}

#endif //CLOCK_IMPLEMENTATION