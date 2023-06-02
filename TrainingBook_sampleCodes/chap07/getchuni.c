/* getchの利用例
   ※Cursesライブラリが提供されるUNIX／Linux／OS Xで動作 */

#include <curses.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int ch;
	int retry;

	initscr();
	cbreak();
	noecho();
	refresh();

	do {
		printf("キーを押してください。");
		fflush(stdout);

		ch = getch();

		printf("\n\r押されたキーは%cで値は%dです。\n\r",
											 isprint(ch) ? ch : ' ', ch);

		printf("もう一度？（Y／N）：");
		fflush(stdout);
		retry = getch();
		if (isprint(retry))
			putchar(retry);

		putchar('\n');
		fflush(stdout);
	} while (retry == 'Y' || retry == 'y');

	endwin();

	return (0);
}