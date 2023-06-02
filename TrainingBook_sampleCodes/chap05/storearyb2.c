/* 好きな個数だけ値を読み込んで要素数10の配列に最後の10個を格納（その２）*/

#include <stdio.h>

#define MAX		10			/* 配列の要素数 */

int main(void)
{
	int i;
	int a[MAX];				/* 読み込んだ値を格納する配列 */
	int cnt = 0;			/* 読み込んだ個数 */
	int retry;				/* もう一度？ */

	printf("整数を入力してください。\n");

	do {
		printf("%d個目の整数：", cnt + 1);
		scanf("%d", &a[cnt++ % MAX]);

		printf("続けますか？（Yes…1／No…0）：");
		scanf("%d", &retry);
	} while (retry == 1);

	i = cnt - MAX;
	if (i < 0) i = 0;

	for ( ; i < cnt; i++)
		printf("%2d個目 : %d\n", i + 1, a[i % MAX]);

	return (0);
}
