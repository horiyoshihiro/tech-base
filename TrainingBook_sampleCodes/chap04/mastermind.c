/* マスターマインド */

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- 相異なる四つの数字の並びを生成して配列xに格納 ---*/
void make4digits(int x[])
{
	int i, j, val;

	for (i = 0; i < 4; i++) {
		do {
			val = rand() % 10;			/* 0～9の乱数 */
			for (j = 0; j < i; j++)		/* その数が既に得られているか */
				if (val == x[j])
					break;
		} while (j < i);		/* 重複しない値が得られるまで繰り返す */
		x[i] = val;
	}
}

/*--- 入力された文字列sの妥当性をチェック ---*/
int check(const char s[])
{
	int i, j;

	if (strlen(s) != 4)			/* 文字列の長さが4でない */
		return (1);

	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return (2);			/* 数字以外の文字が含まれている */
		for (j = 0; j < i; j++)
			if (s[i] == s[j])
				return (3);		/* 同一の数字が含まれている */
	}

	return (0);					/* 文字列は妥当 */
}

/*--- ヒット＆ブローの判定 ---*/
void judge(const char s[], const int no[], int *hit, int *blow)
{
	int i, j;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j])	/* 数字が一致 */
				if (i == j)
					(*hit)++;			/* ヒット（位置も一致） */
				else
					(*blow)++;			/* ブロー（位置が不一致） */
		}
	}
}

/*--- 判定結果を表示 ---*/
void print_result(int snum, int spos)
{
	if (spos == 4)
		printf("正解です!!");
	else if (snum == 0)
		printf("　　それらの数字はまったく含まれません。\n");
	else {
		printf("　　それらの数字中%d個の数字が含まれます。\n", snum);

		if (spos == 0)
			printf("　　ただし位置もあっている数字はありません。\n");
		else
			printf("　　その中の%d個は位置もあっています。\n", spos);
	}
	putchar('\n');
}

int main(void)
{
	int try_no = 0;		/* 入力回数 */
	int chk;			/* 入力された文字列のチェック結果 */
	int hit;			/* 位置も数字も当たっている個数 */
	int blow;			/* 数字が当たって位置が当たっていない数字の個数 */
	int no[4];			/* 当てる数字の並び */
	char buff[10];		/* 読み込む数字の並びを格納する文字列 */
	clock_t	start, end;				/* 開始時刻・終了時刻 */

	srand(time(NULL));				/* 乱数の種を初期化 */

	puts("■ マスターマインドをしましょう。");
	puts("■ 四つの数字の並びを当ててください。");
	puts("■ 同じ数字が複数含まれることはありません。");
	puts("■ 4307のように連続して入力してください。");
	puts("■ スペース文字などを入力してはいけません。\n");

	make4digits(no);					/* 相異なる四つの数字の並びを生成 */

	start = clock();					/* 計測開始 */

	do {
		do {
			printf("入力してください：");
			scanf("%s", buff);			/* 文字列として読み込む */

			chk = check(buff);			/* 読み込んだ文字列をチェック */

			switch (chk) {
			 case 1: puts("\aきちんと４文字で入力してください。"); break;
			 case 2: puts("\a数字以外の文字を入力しないでください。"); break;
			 case 3: puts("\a同一の数字を複数入力しないでください。"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, no, &hit, &blow);	/* 判定 */
		print_result(hit + blow, hit);	/* 判定結果を表示 */

	} while (hit < 4); 

	end = clock();						/* 計測終了 */

	printf("%d回かかりました。\n所要時間は%.1f秒でした。\n",
							try_no, (double)(end - start) / CLOCKS_PER_SEC);

	return (0);
}
