/*-------------------------------------------------------------------------
 *
 * pg_id.c--
 *    Print the user ID for the login name passed as argument,
 *    or the real user ID of the caller if no argument.  If the
 *    login name doesn't exist, print "NOUSER" and exit 1.
 *
 * Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *    $Header: /usr/local/cvsroot/postgres95/src/bin/pg_id/pg_id.c,v 1.1.1.1 1996/07/09 06:22:14 scrappy Exp $
 *
 *-------------------------------------------------------------------------
 */
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
    struct passwd *pw;
    int ch;
    extern int optind;

    while ((ch = getopt(argc, argv, "")) != EOF)
	switch (ch) {
	case '?':
	default:
	    fprintf(stderr, "usage: pg_id [login]\n");
	    exit(1);
	}
    argc -= optind;
    argv += optind;

    if (argc > 0) {
	if (argc > 1) {
	    fprintf(stderr, "usage: pg_id [login]\n");
	    exit(1);
	}
	if ((pw = getpwnam(argv[0])) == NULL) {
	    printf("NOUSER\n");
	    exit(1);
	}
	printf("%d\n", pw->pw_uid);
    } else {
	printf("%d\n", getuid());
    }

    exit(0);
}
