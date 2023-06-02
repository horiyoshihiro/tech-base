/* コンピュータが必ず勝つじゃんけんゲーム */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int human;				/* 人間の手 */
	int comp;				/* コンピュータの手 */
	int judge;				/* 勝敗 */
	int retry;				/* もう一度？ */
	char *hd[] = {"グー", "チョキ", "パー"};		/* 手 */

	srand(time(NULL));		/* 乱数の種を初期化 */

	printf("じゃんけんゲーム開始!!\n");

	do {
		do {
			printf("\n\aじゃんけんポン …");
			for (i = 0; i < 3; i++)
				printf(" (%d)%s", i, hd[i]);
			printf("：");
			scanf("%d", &human);	/* 人間の手を読み込む */
		} while (human < 0 || human > 2);

		comp = (human + 2) % 3;		/* コンピュータは後出し！ */

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;					/* 勝敗を判定 */

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
