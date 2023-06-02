/* 暗算能力チェック（0～99の整数を四つ加算するのに要する時間を計測）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c, d;			/* 加える数値 */
	int x;					/* 読み込んだ値 */
	time_t start, end;		/* 開始時刻・終了時刻 */

	srand(time(NULL));		/* 乱数の種を初期化 */

	a = rand() % 100;		/* 0～99の乱数を生成 */
	b = rand() % 100;		/* 　　　 〃　　　　 */
	c = rand() % 100;		/* 　　　 〃　　　　 */
	d = rand() % 100;		/* 　　　 〃　　　　 */

	printf("%d + %d + %d + %dは何ですか：", a, b, c, d);

	start = time(NULL);						/* 計測開始 */

	while (1) {
		scanf("%d", &x);
		if (x == a + b + c + d)
			break;
		printf("\a違いますよ!!\n再入力してください：");
	}

	end = time(NULL);						/* 計測終了 */

	printf("%.0f秒かかりました。\n", difftime(end, start));

	return (0);
}
