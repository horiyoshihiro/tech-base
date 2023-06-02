/*数当てゲーム_01*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int main(void){

    int no;

    srand(time(NULL));
    char ans = rand() % 1998 - 1000 + 1;

    printf("-----数当てゲーム-----\n");
    
    do{
        printf("数を入力してね\n");
        scanf("%d", &no);

        if(ans > no){
            printf("残念、数が小さいよ！\n");
        }else if(ans < no){
            printf("残念、数が大きいよ！\n");
        }
    }while(ans != no);
   
    printf("正解！\n");

        

}

