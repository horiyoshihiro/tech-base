/* 一つの文字列によるキータイピング練習（その１）*/

#include <time.h>
#include <ctype.h>
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
	printf("%s\n", str);				/* タイプする文字列を表示 */
	fflush(stdout);

	start = clock();					/* 開始時刻 */

	for (i = 0; i < len; i++) {
		int ch;

		do {
			ch = getch();				/* キー読込み */
			if (isprint(ch)) {
				putch(ch);				/* 押されたキーを表示 */
				if (ch != str[i])		/* 違うキーが押されたら */
					putch('\b');		/* カーソルを一つ戻す   */
			}
		} while (ch != str[i]);
	}

	end = clock();						/* 終了時刻 */

	printf("\n%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return (0);
}
