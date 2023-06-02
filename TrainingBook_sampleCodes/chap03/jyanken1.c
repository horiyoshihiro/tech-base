/* じゃんけんゲーム（その１）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int human;				/* 人間の手 */
	int comp;				/* コンピュータの手 */
	int judge;				/* 勝敗 */
	int retry;				/* もう一度？ */

	srand(time(NULL));		/* 乱数の種を初期化 */

	printf("じゃんけんゲーム開始!!\n");

	do {
		comp = rand() % 3;		/* コンピュータの手（0～2）を乱数で生成 */

		printf("\n\aじゃんけんポン…(0)グー (1)チョキ (2)パー：");
		scanf("%d", &human);		/* 人間の手を読み込む */

		printf("私は");				/* コンピュータの手を表示 */
		switch (comp) {
		 case 0: printf("グー");	break;
		 case 1: printf("チョキ");	break;
		 case 2: printf("パー");	break;
		}
		printf("です。\n");

		judge = (human - comp + 3) % 3;		/* 勝敗を判定 */

		switch (judge) {
		 case 0: puts("引き分けです。");		break;
		 case 1: puts("あなたの負けです。");	break;
		 case 2: puts("あなたの勝ちです。");	break;
		}

		printf("もう一度しますか…(0)いいえ (1)はい：");
		scanf("%d", &retry);
	} while (retry == 1);

	return (0);
}
