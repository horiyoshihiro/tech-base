/*数当てゲーム_03*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void){

    /*変数宣言*/
    int no;
    int ans;
    int upper;
    int lower;
    int width;
    int chance;
    int cnt;
    int sqr;

    /*解答となる数の設定*/
    
    do{
        srand(time(NULL) % 20);
        upper = rand();
        srand(time(NULL) %20);
        lower = rand();
    }while(upper == lower);
    
    if(upper < lower){
        int tmp = lower; 
        lower = upper;
        upper = tmp;
    }
    width = upper - lower + 1;
    srand(time(NULL) % 20);
    ans = rand() % width + lower;

    cnt = 0;
    sqr = 1;
    /*入力可能回数*/
    while(width > sqr){
        sqr = 2 * sqr;
        cnt++;
    }
    
    printf("-----数当てゲーム-----\n");
    
    do{
        printf("数を入力してね:正解は%d、幅は%d、残り解答回数は%d、lowerは%d、upperは%d\n",ans, width, cnt, lower, upper);
        scanf("%d", &no);

        if(ans > no){
            printf("残念、数が小さいよ！\n");
        }else if(ans < no){
            printf("残念、数が大きいよ！\n");
        }
        cnt--;
    }while(ans != no && cnt != 0);

    if(ans == no){
        printf("正解！\n");
    }else{
        printf("残念、不正解！\n");
    }
}

