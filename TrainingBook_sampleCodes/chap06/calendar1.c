/* カレンダー表示 */

#include <stdio.h>

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

int main(void)
{
	int y, m;

	printf("カレンダーを表示します。\n");
	printf("年：");	  scanf("%d", &y);
	printf("月：");   scanf("%d", &m);

	putchar('\n');

	put_calendar(y, m);		/* y年m月のカレンダーを表示 */

	return (0);
}
