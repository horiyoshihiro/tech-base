/* getchの利用例
   ※Visual C++などのMS-Windows／MS-DOSで動作 */

#include <conio.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int ch;
	int retry;

	do {
		printf("キーを押してください。");
		ch = getch();

		printf("\n押されたキーは%cで値は%dです。\n",
											 isprint(ch) ? ch : ' ', ch);

		printf("もう一度？（Y／N）：");
		retry = getch();
		if (isprint(retry))
			putch(retry);

		putchar('\n');

	} while (retry == 'Y' || retry == 'y');

	return (0);
}
