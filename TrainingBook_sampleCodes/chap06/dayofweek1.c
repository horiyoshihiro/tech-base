/* —j“ú‚ğ‹‚ß‚éi‚»‚Ì‚PFmktimeŠÖ”‚ğ—˜—pj*/

#include <time.h>
#include <stdio.h>

/*--- year”NmonthŒday“ú‚Ì—j“ú‚ğ‹‚ß‚é ---*/
int dayofweek(int year, int month, int day)
{
	struct tm t;

	t.tm_year  = year - 1900;	/* ”N‚ğ’²® */
	t.tm_mon   = month - 1;		/* Œ‚ğ’²® */
	t.tm_mday  = day;			/* “ú */
	t.tm_hour  = 0;				/*  */
	t.tm_min   = 0;				/* •ª */
	t.tm_sec   = 0;				/* •b */
	t.tm_isdst = -1;			/* ‰ÄŠÔ */

	if (mktime(&t) == (time_t)-1)	/* •ÏŠ·‚É¸”s‚µ‚½‚ç */
		return (-1);				/* -1‚ğ•Ô‹p */
	return (t.tm_wday);			/* mktimeŠÖ”‚É‚æ‚Á‚Äİ’è‚³‚ê‚½—j“ú‚ğ•Ô‹p */
}

int main(void)
{
	int  y, m, d, w;
	char *ws[] = {"“ú", "Œ", "‰Î", "…", "–Ø", "‹à", "“y"};

	printf("—j“ú‚ğ‹‚ß‚Ü‚·B\n");
	printf("”NF");	  scanf("%d", &y);
	printf("ŒF");	  scanf("%d", &m);
	printf("“úF");	  scanf("%d", &d);

	w = dayofweek(y, m, d);			/* —j“ú‚ğ‹‚ß‚é */

	if (w != -1)
		printf("‚»‚ê‚Í%s—j“ú‚Å‚·B\n", ws[w]);
	else
		printf("‹‚ß‚ç‚ê‚Ü‚¹‚ñ‚Å‚µ‚½B\n");

	return (0);
}
