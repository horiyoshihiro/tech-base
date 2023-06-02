/* トライグラフ連想トレーニング（数字・英字の３文字の並びを完成させる）*/

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getputch.h"

#define	MAX_STAGE	20					/* 挑戦回数 */
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	char *qstr[] = {"0123456789",					/* 数字 */
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ",	/* 英大文字 */
					"abcdefghijklmnopqrstuvwxyz",	/* 英小文字 */
				   };
	/* それぞれの文字数 */
	int 	chmax[] = {10, 26, 26};
	int 	i, stage;
	int 	key;							/* 読み込んだキー */
	double	jikan;							/* 時間 */
	clock_t	start, end;						/* 開始時刻・終了時刻 */

	init_getputch();

	srand(time(NULL));						/* 乱数の種を初期化 */

	printf("□連続する三つの数字あるいは英字から\n");
	printf("□隠されている文字を入力してください。\n");
	printf("□たとえば A ? C : と表示されたらBを\n");
	printf("□　　　　 4 5 ? : と表示されたら6を\n");
	printf("□入力します。\n");
	printf("★スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int qtype = rand() % 3;		/* 0:数字／1:英大文字／2:英小文字 */
		int nhead = rand() % (chmax[qtype] - 2);	/* 先頭文字の添字 */
		int x     = rand() % 3;		/* ３文字のどれを'?'にするか */

		putchar('\r');
		for (i = 0; i < 3; i++) {	/* 問題を表示 */
			if (i != x)
				printf(" %c", qstr[qtype][nhead + i]);
			else
				printf(" ?");
		}
		printf(" : ");

		do {
			key = getch();
			if (isprint(key)) {						/* 表示可能であれば */
				putch(key);							/* 押されたキーを表示 */
				if (key != qstr[qtype][nhead + x])	/* 正解でなければ */
					putch('\b');					/* カーソルを一つ戻す */
			}
		} while (key != qstr[qtype][nhead + x]);
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("\n%.1f秒かかりました。\n", jikan);

	if (jikan > 50.0)
		printf("鈍すぎます。\n");
	else if (jikan > 40.0)
		printf("少し鈍いですね。\n");
	else if (jikan > 34.0)
		printf("まあまあですね。\n");
	else
		printf("素早いですね。\n");

	term_getputch();

	return (0);
}
