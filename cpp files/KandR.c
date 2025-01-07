#include<stdio.h>

#define RESET 0
#define RUN 1
#define STOP 0

int main(){
    FILE* fil = fopen("test.txt", "r");
    int c, lenc[10], len = RESET, state = RUN;
    for(int i = 0; i<10; ++i) lenc[i] = 0;
    while((c = fgetc(fil)) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            if(len > 0) ++lenc[len-1];
            len = RESET;
        }
        else ++len;
    }
    // for(int i = 0; i<10; ++i){
    //     printf("%3d --> ", i+1);
    //     for(int j = 0; j<lenc[i]; ++j) printf("*");
    //     printf("\n");
    // }
    for(int i = 0; i<10; ++i) printf("%3d", i+1);
    printf("\n");
    while(state){
        for(int i = 0; i<10; ++i){
            if(lenc[i]){
                printf("  *");
                --lenc[i];
            }
            else printf("   ");
        }
        printf("\n");
        for(int i = 0; i<10; ++i){
            if(lenc[i] == 0) state = STOP;
            else{
                state = RUN;
                break;
            }
        }
    }
    printf("\nFin");

    printf("\n\n");
return 0;
}