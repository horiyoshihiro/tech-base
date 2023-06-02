/* 配列をコピーして表示（要素を一つ飛ばす）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, x;
	int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a[8] = {0};

	srand(time(NULL));		/* 乱数の種を初期化 */

	x = rand() % 9;			/* xは0～8の乱数 */

	i = j = 0;
	while (i < 9) {			/* dgt[x]を飛ばしてコピー */
		if (i != x)
			a[j++] = dgt[i];
		i++;
	}

	for (i = 0; i < 8; i++)				/* 全要素を表示 */
		printf("%d ", a[i]);

	putchar('\n');

	return (0);
}
