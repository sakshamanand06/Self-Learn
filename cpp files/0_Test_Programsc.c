// #include<stdio.h>

// #define RESET 0
// #define RUN 1
// #define STOP 0

// int main(){
//     char from[50], to[50];
//     printf("Enter sht: ");
//     scanf("%s", from);
//     for(int i = 0; (to[i] = from[i]) != '\0'; ++i);
//     printf("Str 1 -> %s\nStr 2 -> %s", from, to);
//     // int c, lenc[10], len = RESET, state = RUN;
//     // for(int i = 0; i<10; ++i) lenc[i] = 0;
//     // while((c = getchar()) != '\n'){
//     //     if(c == ' ' || c == '\t' || c == '\n'){
//     //         if(len > 0) ++lenc[len-1];
//     //         len = RESET;
//     //     }
//     //     else ++len;
//     // }
//     // for(int i = 0; i<10; ++i){
//     //     printf("%3d --> ", i+1);
//     //     for(int j = 0; j<lenc[i]; ++j) printf("*");
//     //     printf("\n");
//     // }
//     // for(int i = 0; i<10; ++i) printf("%3d", i+1);
//     // printf("\n");
//     // while(state){
//     //     for(int i = 0; i<10; ++i){
//     //         if(lenc[i]){
//     //             printf("  *");
//     //             --lenc[i];
//     //         }
//     //         else printf("   ");
//     //     }
//     //     printf("\n");
//     //     for(int i = 0; i<10; ++i){
//     //         if(lenc[i] == 0) state = STOP;
//     //         else{
//     //             state = RUN;
//     //             break;
//     //         }
//     //     }
//     // }
//     printf("\nFin");

//     printf("\n\n");
// return 0;
// }

// // void sort(int* p, int n){
// //     int temp;
// //     for(int i = 0; i<n-1; i++){
// //         for(int j=0; j<n-i-1; j++){
// //             if(*p > *(p+1)){
// //                 temp = *p;
// //                 *p = *(p+1);
// //                 *(p+1) = temp;
// //                 // temp = p[j];
// //                 // p[j] = p[j+1];
// //                 // p[j+1] = temp;
// //             }
// //         }
// //     }
// // }
//     // int n;
//     // printf("Enter size: ");
//     // scanf("%d", &n);
//     // printf("Enter elements: ");
//     // int arr[n];
//     // for(int i = 0; i<n; i++) scanf("%d", &arr[i]);
//     // int *p = arr;
//     // for(int i = 0; i<n; i++) printf("%d ", arr[i]);
//     // printf("\n");
//     // sort(p, n);
//     // for(int i = 0; i<n; i++) printf("%d ", arr[i]);
//     // printf("\n");

//     // printf("\n\n");
//     // int i = 0;
//     // while(str[i] != '\0'){
//     //     if(str[i]>='a' && str[i]<='z') str[i]-=32;
//     //     i++;
//     // }

/***********************************************************
 * You can use all the programs on  www.c-program-example.com
 * for personal and learning purposes. For permissions to use the
 * programs for commercial purposes,
 * contact [email protected]
 * To find more C programs, do visit www.c-program-example.com
 * and browse!
 *
 *                      Happy Coding
 ***********************************************************/
#include <stdio.h>

#define MAXLN 10

int main(void)
{
    int c;
    int inspace = 0;
    long lengtharr[MAXLN + 1];
    int wordlen = 0;

    int firstletter = 1;
    long value = 0;
    long maxval = 0;
    int index = 0;
    int done = 0;

    for (index = 0; index <= MAXLN; index++)
    {
        lengtharr[index] = 0;
    }

    while (done == 0)
    {
        c = getchar();

        if (c == ' ' || c == '\t' || c == '\n' || c == EOF)
        {
            if (inspace == 0)
            {
                firstletter = 0;
                inspace = 1;

                if (wordlen <= MAXLN)
                {
                    if (wordlen > 0)
                    {
                        value = ++lengtharr[wordlen - 1];
                        if (value > maxval)
                        {
                            maxval = value;
                        }
                    }
                }
                else
                {
                    value = ++lengtharr[MAXLN];
                    if (value > maxval)
                    {
                        maxval = value;
                    }
                }
            }
            if (c == '\n')
            {
                done = 1;
            }
        }
        else
        {
            if (inspace == 1 || firstletter == 1)
            {
                wordlen = 0;
                firstletter = 0;
                inspace = 0;
            }
            ++wordlen;
        }
    }

    for (value = maxval; value > 0; value--)
    {
        printf("%4ld  | ", value);
        for (index = 0; index <= MAXLN; index++)
        {
            if (lengtharr[index] >= value)
            {
                printf("*  ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("      +");
    for (index = 0; index <= MAXLN; index++)
    {
        printf("---");
    }
    printf("\n       ");
    for (index = 0; index < MAXLN; index++)
    {
        printf("%2d ", index + 1);
    }
    printf(">%d\n", MAXLN);

    return 0;
}