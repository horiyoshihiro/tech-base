/* 好きな個数だけ値を読み込んで要素数10の配列に最後の10個を格納（その１）*/

#include <stdio.h>

#define	MAX		10			/* 配列の要素数 */

int main(void)
{
	int i;
	int a[MAX];				/* 読み込んだ値を格納する配列 */
	int cnt = 0;			/* 読み込んだ個数 */
	int retry;				/* もう一度？ */

	printf("整数を入力してください。\n");

	do {
		if (cnt >= MAX) {		/* MAX+1個目以降を読み込む前に */
			for (i = 0; i < MAX - 1; i++)	/* 要素a[1]～a[MAX-1]を */
				a[i] = a[i + 1];			/* 一つ先頭側にずらす */
		}
		printf("%d個目の整数：", cnt + 1);
		scanf("%d", &a[cnt < MAX ? cnt : MAX - 1]);
		cnt++;

		printf("続けますか？（Yes…1／No…0）：");
		scanf("%d", &retry);
	} while (retry == 1);

	if (cnt <= MAX)					/* 読み込んだのはMAX個以下 */
		for (i = 0; i < cnt; i++)
			printf("%2d個目 : %d\n", i + 1, a[i]);
	else							/* 読み込んだのはMAX個より多い */
		for (i = 0; i < MAX; i++)
			printf("%2d個目 : %d\n", cnt - MAX + 1 + i, a[i]);

	return (0);
}
