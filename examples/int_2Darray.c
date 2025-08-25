#include <stdio.h>
#include <string.h>
#include "../dyarr.h"

/*
    This program reads 3 lines of space-separated integers from standard input,
    stores them in a dynamic 2D array, and then prints the 2D array to standard output.
*/

int main(int argc, char const *argv[])
{
    int **arr = NULL;
    for(int i = 0; i < 3; i++) {
        int* subarr = NULL;
        char buf[255];

        scanf("%[^\n]s", buf);
        char* tok = strtok(buf, " \t");
        while(tok != NULL) {
            int val = atoi(tok); // assime user input is valid integer
            arrpush(subarr, val);
            tok = strtok(NULL, " \t");
        }

        if( strlen(buf) == 0 || subarr == NULL ) {
            // make empty subarray if user input is empty line
            arrpush(subarr, 0); 
            arrpop(subarr);
        }

        if( strlen(buf) == 0 || subarr == NULL ) {
            // make empty subarray if user input is empty line
            arrpush(subarr, 0); 
            arrpop(subarr);
        }
        arrpush(arr, subarr);
        buf[0] = '\0';
        getchar();
    }

    printf("[\n");
    for(int i = 0; i < arrlen(arr); i++) {
        printf("  [ ");
        for(int j = 0; j < arrlen(arr[i]); j++) {
            printf("%d, ", arr[i][j]);
        }
        printf("],");
        printf("\n");
    }
    printf("]\n");


    return 0;
}
