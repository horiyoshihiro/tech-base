/* カレンダー表示（表示する年月をコマンドラインで指定）*/

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*--- 各月の日数 ---*/
int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*--- year年month月day日の曜日を求める ---*/
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return ((year + year/4 - year/100 + year/400 + (13*month+8)/5 + day) % 7);
}

/*--- year年は閏年か？（0…平年／1…閏年） ---*/
int is_leap(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

/*--- year年month月の日数（28～31） ---*/
int monthdays(int year, int month)
{
	if (month-- != 2)						/* monthが２月でないとき */
		return (mday[month]);
	return (mday[month] + is_leap(year));	/* monthが２月であるとき */
}

/*--- y年m月のカレンダーを表示 ---*/
void put_calendar(int y, int m)
{
	int i;
	int wd = dayofweek(y, m, 1);	/* y年m月1日の曜日 */
	int mdays = monthdays(y, m);	/* y年m月の日数 */

	printf(" 日 月 火 水 木 金 土 \n");
	printf("----------------------\n");

	printf("%*s", 3 * wd, "");		/* 1日より左側のスペースを表示 */

	for (i = 1; i <= mdays; i++) {
		printf("%3d", i);
		if (++wd % 7 == 0)			/* 土曜日を表示したら */
			putchar('\n');		/* 改行 */
	}
	if (wd % 7 != 0)
		putchar('\n');
}

/*--- 文字列の先頭n文字を比較（大文字・小文字を区別しない） ---*/
int strncmpx(const char *s1, const char *s2, size_t n)
{
	while (n && toupper(*s1) && toupper(*s2)) {
		if (toupper(*s1) != toupper(*s2))			/* 等しくない */
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	if (!n)	 return (0);
	if (*s1) return (1);
	return (-1);
}

/*--- 文字列から月の値を得る ---*/
int get_month(char *s)
{
	int i;
	int m;		/* 月 */
	char *month[] = {"", "January", "February", "March", "April",
					 "May", "June", "July", "August", "September",
					 "October", "November", "December"};

	m = atoi(s);
	if (m >= 1 && m <= 12)		/* 数字表記："1", "2", …, "12" */
		return (m);

	for (i = 1; i <= 12; i++)		/* 英語表記 */
		if (strncmpx(month[i], s, 3) == 0)
			return (i);

	return (-1);					/* 変換失敗 */
}

int main(int argc, char *argv[])
{
	int  y, m;
	time_t t = time(NULL);				/* 現在の時刻を取得 */
	struct tm *local = localtime(&t);	/* 要素別の時刻（地方時）に変換 */

	y = local->tm_year + 1900;			/* 今日の年 */
	m = local->tm_mon + 1;				/* 今日の月 */

	if (argc >= 2) {				/* argv[1]の解析 */
		m = get_month(argv[1]);
		if (m < 0 || m > 12) {
			fprintf(stderr, "月の値が不正です。\n");
			return (1);
		}
	}
	if (argc >= 3) {				/* argv[2]の解析 */
		y = atoi(argv[2]);
		if (y < 0) {
			fprintf(stderr, "年の値が不正です。\n");
			return (1);
		}
	}

	printf("%d年%d月\n\n", y, m);

	put_calendar(y, m);		/* y年m月のカレンダーを表示 */

	return (0);
}
