/*履歴が出るようにした版*/
// ensyu3-3からコピー
// 2023/03/22

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

unsigned char hmn_hand;
unsigned char cmp_hand;
unsigned char result;
unsigned int turn_cnt;
bool try;

struct resultQue
{
    int turn;
    char hmn;
    char cmp;
    char winner; // 0:draw, 1:hmn, 2:cmp
    struct resultQue *next;
};

struct resultQue resultQue_Top;

struct resultQue *presultQue_Top;

char *hd[] = {"グー", "パー", "チョキ"}; /* 手 */

// gu    : 0
// pa-   : 1
// choki : 2

void init_janken(void)
{
    hmn_hand = 0;
    cmp_hand = 0;
    result = 0;
    turn_cnt = 0;
    try = false;

    presultQue_Top = &resultQue_Top;
    presultQue_Top->turn = 1;
    presultQue_Top->hmn = 0;
    presultQue_Top->cmp = 0;
    presultQue_Top->winner = 0;
    presultQue_Top->next = NULL;

    srand(time(NULL));

    return;
}

char scan_hmn_hand(void)
{
    char ret;

    printf("何を出す？\n");
    for (int i = 0; i < 3; i++)
    {
        int j = i + 1;
        printf("%s(%d) ", hd[i], j);
    }
    printf("：");
    scanf("%d", &ret);

    ret--;

    return ret;
}

char generate_cmp_hnd(void)
{
    char ret;

    if (turn_cnt != 1)
    {
        ret = rand() % 3;
    }
    else
    {
        ret = 0; // 最初のターンのみグー
    }

    return ret;
}

char judge(void)
{
    signed int dif;
    char ret; // 0:引き分け、1:hmnの勝ち、2:cmpの勝ち

    ret = 0;

    dif = hmn_hand - cmp_hand + 3;
    dif = dif % 3;

    if (dif == 1)
    {
        ret = 1; // hmpの勝ち
    }
    else if (dif == 2)
    {
        ret = 2; // cmpの勝ち
    }

    return ret;
}

void disp_result(void)
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

    if (scan == 1)
    {
        ret = true;
    }

    return ret;
}

void save_result(void)
{
    struct resultQue *wkdata;

    wkdata = (struct resultQue *)malloc(sizeof(struct resultQue));

    wkdata->turn = turn_cnt;
    wkdata->hmn = hmn_hand;
    wkdata->cmp = cmp_hand;
    wkdata->winner = result;
    wkdata->next = NULL;

    struct resultQue *pCurrentQue;
    pCurrentQue = presultQue_Top;

    if (turn_cnt != 1)
    {
        while (1)
        {
            if (pCurrentQue->next == NULL)
            {
                pCurrentQue->next = wkdata;
                break;
            }
            else
            {
                pCurrentQue = pCurrentQue->next;
            }
        }
    }else{
        presultQue_Top->next = wkdata;
    }

    return;
}

void disp_all_result(void)
{
    struct resultQue *pCurrentQue;
    pCurrentQue = presultQue_Top->next;

    while (1)
    {

        printf("---------------------\n");
        printf("ターン：%d\n", pCurrentQue->turn);
        printf("あなたの手：%s\n", hd[pCurrentQue->hmn]);
        printf("コンピュータの手：%s\n", hd[pCurrentQue->cmp]);

        switch (pCurrentQue->winner)
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

        printf("---------------------\n");

        if (pCurrentQue->next == NULL)
        {
            break;
        }
        else
        {
            pCurrentQue = pCurrentQue->next;
        }
    }
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

        result = judge();

        disp_result();

        save_result();

        try = ask_retry();
    } while (try);

    disp_all_result();
}