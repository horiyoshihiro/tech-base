/* 複数文字列によるキータイピング練習（その１）*/

#include <time.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"

#define QNO		12		/* 問題数 */

int main(void)
{
	char	*str[QNO] = {"book",   "computer", "default",  "comfort",
						 "monday", "power",    "light",    "music", 
						 "programming", "dog", "video",    "include"};
	int   	i, stage;
	clock_t	start, end;				/* 開始時刻・終了時刻 */

	init_getputch();
	printf("タイピング練習を始めます。\n");
	printf("スペースキーで開始します。\n");
	while (getch() != ' ')			/* スペースキーが押下 */
		;							/* されるまで待つ */

	start = clock();				/* 開始時刻 */

	for (stage = 0; stage < QNO; stage++) {
		int len = strlen(str[stage]);	/* 文字列str[stage]の文字数 */
		for (i = 0; i < len; i++) {
			/* str[stage][i]以降を表示してカーソルを先頭へ戻す */
			printf("%s \r", &str[stage][i]);

			fflush(stdout);
			while (getch() != str[stage][i])
				;
		}
	}

	end = clock();					/* 終了時刻 */

	printf("\r%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return (0);
}
