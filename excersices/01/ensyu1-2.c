/*おみくじゲーム_02*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int main(void){

    srand(time(NULL));
    char fortune = rand() % 6;
    if(fortune > 3){
        char fortune = rand() % 6;
    }

    printf("おみくじ\n");
    
    switch (fortune)
    {
    case 0:
        printf("[大吉]");
        break;
    case 1:
        printf("[中吉]");
        break;
    case 2:
        printf("[小吉]");
        break;
    case 3:
        printf("[吉]");
        break;
    case 4:
        printf("[末吉]");
        break;
    case 5:
        printf("[凶]");
        break;
    case 6:
        printf("[大凶]");
        break;

    default:
        break;
    }
}

