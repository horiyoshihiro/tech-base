/*--- x•bŒo‰ß‚·‚é‚Ì‚ğ‘Ò‚Â ---*/
int ssleep(double x)
{
	time_t t1 = time(NULL), t2;

	do {
		if ((t2 = time(NULL)) == (time_t)-1)		/* ƒGƒ‰[ */
			return (0);
	} while (difftime(t1, t2) < x); 
	return (1);
}
