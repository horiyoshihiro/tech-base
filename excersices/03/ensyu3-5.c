/*cmpが5回ごとに後出しする*/
//ensyu3-4からコピー
//2023/03/22

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

unsigned char hmn_hand;
unsigned char cmp_hand;
unsigned char result;
unsigned int  turn_cnt;
bool try;

char *hd[] = {"グー", "パー", "チョキ"};		/* 手 */

//gu    : 0
//pa-   : 1
//choki : 2

void init_janken(void)
{
    hmn_hand = 0;
    cmp_hand = 0;
    result = 0;
    turn_cnt = 0;
    try = false;

    srand(time(NULL));
    
}

char scan_hmn_hand(void)
{
    char ret;

    printf("何を出す？\n");
    for(int i = 0; i < 3; i++){
        int j = i + 1;
        printf("%s(%d) ", hd[i],j);
    }
    printf("：");
    scanf("%d", &ret);

    ret--;

    return ret;
}

char generate_cmp_hnd(void)
{
    char ret;

    if(turn_cnt % 5 != 0){
        ret = rand() % 3;  //通常ターン
    }else{
        ret = (hmn_hand + 1) % 3;  //後出しターン
    }

    return ret;
}

char judge(char hmn, char cmp)
{
    signed int dif;
    char ret;       //0:引き分け、1:hmnの勝ち、2:cmpの勝ち

    ret = 0;

    dif = hmn -cmp + 3;
    dif = dif % 3;

    if(dif == 1){
        ret = 1; //hmpの勝ち
    }else if(dif == 2){
        ret = 2; //cmpの勝ち
    }
    
    return ret;
}

void disp_result(char result)
{
    printf("\nあなたの手は%sで私の手は%sでした\n", hd[hmn_hand], hd[cmp_hand]);

    switch (result)
    {
    case 0:
        printf("引き分けです\n");
        break;
    case 1:
        printf("あなたの勝ちです！\n");
        break;
    case 2:
        printf("あなたの負けです...\n");
        break;
    }

    printf("\n-------------------\n");

    return;
}

bool ask_retry(void)
{
    bool ret;
    char scan;

    ret = false;
    scan = 0;

    printf("もう一度じゃんけんしますか？\n");
    printf("やめる(0)・もう一度(1)");
    scanf("%d", &scan);

    if(scan == 1){
        ret = true;
    }

    return ret;
}

int main(void)
{

    init_janken();

    do
    {
        turn_cnt++;

        printf("\n%dターン目：じゃんけんをしよう！\n", turn_cnt);

        hmn_hand = scan_hmn_hand();

        cmp_hand = generate_cmp_hnd();

        result = judge(hmn_hand, cmp_hand);

        disp_result(result);

        try = ask_retry();
    } while (try);
}