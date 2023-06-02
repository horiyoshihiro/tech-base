/* 動的に確保した整数にキーボードから読み込んだ値を格納（誤り）*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *x;

	x = calloc(1, sizeof(int));			/* 確保 */

	if (x == NULL)
		puts("記憶域の確保に失敗しました。");
	else {
		printf("*xに格納する値：");
		scanf("%d", &x);
		printf("*x = %d\n", *x);
		free(x);						/* 解放 */
	}

	return (0);
}
