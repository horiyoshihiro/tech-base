/*--- —v‘f•Ê‚Ì‚ğasctimeŠÖ”‚É€‚¶‚Ä•ÏŠ·i‰üs•¶š‚Í•t‰Á‚µ‚È‚¢j---*/
char *asctime2(const struct tm *timeptr)
{
	const char wday_name[7][3] = {					/* —j“ú */
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
	};
	const char mon_name[12][3] = {					/* Œ–¼ */
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	};
	static char result[25];				/* •¶š—ñŠi”[æ‚ÍÃ“I‚È—Ìˆæ */

	sprintf(result, "%.3s %.3s %02d %02d:%02d:%02d %4d",
					wday_name[timeptr->tm_wday], mon_name[timeptr->tm_mon],
					timeptr->tm_mday, timeptr->tm_hour, timeptr->tm_min,
					timeptr->tm_sec,  timeptr->tm_year + 1900);
	return (result);
}
