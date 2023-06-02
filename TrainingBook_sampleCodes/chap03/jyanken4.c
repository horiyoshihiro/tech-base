/* じゃんけんゲーム（その４：関数に分割／成績を表示）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int human;		/* 人間の手 */
int comp;		/* コンピュータの手 */
int win_no;		/* 勝った回数 */
int lose_no;	/* 負けた回数 */
int draw_no;	/* 引き分けた回数 */

char *hd[] = {"グー", "チョキ", "パー"};		/* 手 */

/*--- 初期処理 ---*/
void initialize(void)
{
	win_no  = 0;		/* 勝った回数 */
	lose_no = 0;		/* 負けた回数 */
	draw_no = 0;		/* 引き分けた回数 */

	srand(time(NULL));	/* 乱数の種を初期化 */

	printf("じゃんけんゲーム開始!!\n");
}

/*--- じゃんけん実行（手の読込み／生成） ---*/
void jyanken(void)
{
	int i;

	comp = rand() % 3;		/* コンピュータの手（0～2）を乱数で生成 */

	do {
		printf("\n\aじゃんけんポン …");
		for (i = 0; i < 3; i++)
			printf(" (%d)%s", i, hd[i]);
		printf("：");
		scanf("%d", &human);		/* 人間の手を読み込む */
	} while (human < 0 || human > 2);
}

/*--- 勝／負／引き分け回数を更新 ---*/
void count_no(int result)
{
	switch (result) {
	 case 0: draw_no++;	 break;						/* 引き分け */
	 case 1: lose_no++;	 break;						/* 負け */
	 case 2: win_no++;   break;						/* 勝ち */
	}
}

/*--- 判定結果を表示 ---*/
void disp_result(int result)
{
	switch (result) {
	 case 0: puts("引き分けです。");	   break;	/* 引き分け */
	 case 1: puts("あなたの負けです。");   break;	/* 負け */
	 case 2: puts("あなたの勝ちです。");   break;	/* 勝ち */
	}
}

/*--- 再挑戦するかを確認 ---*/
int confirm_retry(void)
{
	int x;

	printf("もう一度しますか…(0)いいえ (1)はい：");
	scanf("%d", &x);

	return (x);
}

int main(void)
{
	int judge;				/* 勝敗 */
	int retry;				/* もう一度？ */

	initialize();							/* 初期処理 */

	do {
		jyanken();							/* じゃんけん実行 */

		/* コンピュータと人間の手を表示 */
		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;		/* 勝敗を判定 */

		count_no(judge);					/* 勝／負／引き分け回数を更新 */

		disp_result(judge);					/* 判定結果を表示 */

		retry = confirm_retry();			/* 再挑戦するかを確認 */

	} while (retry == 1);

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);

	return (0);
}
