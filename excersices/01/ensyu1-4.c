/*数当てゲーム_02*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MODE 0



int main(void){

    int no;
    int ans;

    srand(time(NULL));
    ans = (rand() % 333 + 1) * 3;

    printf("-----数当てゲーム-----\n");
    
    do{
        printf("3の倍数を入力してね:正解は%d\n",ans);
        scanf("%d", &no);

        if(MODE == 0){
            if(no % 3 != 0){
                break;
            }
        }else{
            if(no % 3 != 0){
                continue;
            }
        }

        if(ans > no){
            printf("残念、数が小さいよ！\n");
        }else if(ans < no){
            printf("残念、数が大きいよ！\n");
        }
    }while(ans != no);

    if(ans == no){
        printf("正解！\n");
    }
   
    

        

}

