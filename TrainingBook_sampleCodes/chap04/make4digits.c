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
