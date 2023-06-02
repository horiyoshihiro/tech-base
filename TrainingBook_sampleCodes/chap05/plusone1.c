/* プラスワントレーニング（複数の数値を記憶して１を加えた値を入力）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE	10				/* ステージ数 */
#define LEVEL_MIN	2				/* 最小レベル（数値の個数）*/
#define LEVEL_MAX	6				/* 最大レベル（数値の個数）*/

/*--- xミリ秒経過するのを待つ ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	/* エラー */
			return (0);
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x); 
	return (1);
}

int main(void)
{
	int 	i, stage;
	int 	level;						/* レベル */
	int 	success;					/* 正解数 */
	int 	score[MAX_STAGE];			/* 全ステージの正解数 */
	clock_t	start, end;					/* 開始時刻・終了時刻 */

	srand(time(NULL));					/* 乱数の種を初期化 */

	printf("プラスワントレーニング開始!!\n");
	printf("２桁の数値を記憶します。\n");
	printf("１を加えた値を入力してください。\n");

	do {
		printf("挑戦するレベル（%d～%d）：", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	success = 0;
	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int no[LEVEL_MAX];					/* 記憶する数 */
		int x[LEVEL_MAX];					/* 読み込んだ値 */
		int seikai = 0;						/* このステージでの正解数 */

		printf("\n第%dステージ開始!!\n", stage + 1);

		for (i = 0; i < level; i++) {		/* level個だけ */
			no[i] = rand() % 90 + 10;		/* 10～99の乱数を生成して */
			printf("%d ", no[i]);			/* 表示する */
		}
		fflush(stdout);
		sleep(300 * level);					/* 0.30×level秒待って */
		printf("\r%*s\r", 3 * level, "");	/* 問題を消す */

		for (i = 0; i < level; i++) {		/* 解答を読み込む */
			printf("%d番目の数：", i + 1);
			scanf("%d", &x[i]);
		}

		for (i = 0; i < level; i++) {		/* 正誤を判定・表示 */
			if (x[i] != no[i] + 1)
				printf("× ");
			else {
				printf("○ ");
				seikai++;
			}
		}
		putchar('\n');

		for (i = 0; i < level; i++)			/* 正解を表示 */
			printf("%2d ", no[i]);

		printf(" … %d個正解です。\n", seikai);
		score[stage] = seikai;				/* ステージの正解数を記録 */
		success += seikai;					/* 全体の正解数を更新 */
	}
	end = clock();

	printf("%d個中%d個正解しました。\n", level * MAX_STAGE, success);

	for (stage = 0; stage < MAX_STAGE; stage++)
		printf("第%2dステージ：%d\n", stage + 1, score[stage]);

	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return (0);
}
