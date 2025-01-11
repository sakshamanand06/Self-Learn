#include<stdio.h>

int main(){
    FILE* textFile = fopen("test.txt", "r");
    int maxLen = 21;
    int c, lengthArray[maxLen], wordLength = 0;
    for(int i = 0; i<maxLen; ++i) lengthArray[i] = 0;
    while(1){
        c = fgetc(textFile);
        // c=getchar(); // for terminal input
        if(c == ' ' || c == '\t' || c == '\n'){
            if(wordLength > 0) ++lengthArray[wordLength];
            wordLength = 0;
        }
        else ++wordLength;
        if(c==EOF) break;
        // if(c=='\n') break; // for terminal input
    }
    for(int i = 1; i<maxLen; ++i){
        printf("%3d --> ", i);
        for(int j = 0; j<lengthArray[i]; ++j) printf("*");
        printf("\n");
    }

    int maxv;
    for(int i=1; i<maxLen; i++) if(maxv<lengthArray[i]) maxv=lengthArray[i];
    for(int lr = maxv+1; lr>0; lr--){
        printf("%3d |", lr);
        for(int i=1; i<maxLen; i++){
            if(lengthArray[i] == lr){
                printf(" * ");
                --lengthArray[i];
            }
            else printf("   ");
        }
        printf("\n");
    }
    printf("    +");
    for(int i=1; i<maxLen; i++){
        printf("---");
    }
    printf("\n     ");
    for(int i=1; i<maxLen; i++){
        printf("%2d ", i);
    }

    fclose(textFile);
    printf("\n\n");
return 0;
}