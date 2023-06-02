/* 整数の読込み（その２：文字列として読み込んで変換）*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char temp[20];		/* 読込み用文字列 */

	printf("整数を入力してください：");
	scanf("%s", temp);

	printf("%dと入力しましたね。\n", atoi(temp));

	return (0);
}
