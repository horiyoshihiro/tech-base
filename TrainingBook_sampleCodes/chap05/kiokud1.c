/* 単純記憶トレーニング（４桁の数値を記憶）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE	10							/* ステージ数 */

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
	int 	stage;
	int 	success = 0;						/* 正解数 */
	clock_t	start, end;							/* 開始時刻・終了時刻 */

	srand(time(NULL));							/* 乱数の種を初期化 */

	printf("４桁の数値を記憶しましょう。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x;								/* 読み込んだ値 */
		int no = rand() % 9000 + 1000;		/* 記憶すべき数値 */

		printf("%d", no);
		fflush(stdout);
		sleep(500);	/* 問題提示は0.5秒だけ */

		printf("\r入力せよ：");
		scanf("%d", &x);

		if (x != no)
			printf("\a間違いです。\n");
		else {
			printf("正解です。\n");
			success++;
		}
	}
	end = clock();

	printf("%d回中%d回成功しました。\n", MAX_STAGE, success);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return (0);
}
