/* 一つの文字列によるキータイピング練習（その２：打った文字が消えていく）*/

#include <time.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"

int main(void)
{
	int 	i;
	char	*str = "How do you do?";	/* タイプする文字列 */
	int 	len = strlen(str);			/* 文字列strの文字数 */
	clock_t	start, end;					/* 開始時刻・終了時刻 */

	init_getputch();
	printf("このとおりタイプしてください。\n");

	start = clock();					/* 開始時刻 */

	for (i = 0; i < len; i++) {
		/* str[i]以降を表示してカーソルを先頭へ戻す */
		printf("%s \r", &str[i]);

		fflush(stdout);
		while (getch() != str[i])
			;
	}

	end = clock();						/* 終了時刻 */
 
	printf("\r%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return (0);
}