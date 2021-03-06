.\" This is -*-nroff-*-
.\" XXX standard disclaimer belongs here....
.\" $Header: /usr/local/cvsroot/postgres95-support/doc/man/end.l,v 1.1.1.1 1996/08/18 22:14:24 scrappy Exp $
.TH END SQL 01/23/93 Postgres95 Postgres95
.SH NAME
end \(em commit the current transaction 
.SH SYNOPSIS
.nf
\fBend [transaction]\fR
.fi
.SH DESCRIPTION
This commands commits the current transaction.  All changes made by
the transaction become visible to others and are guaranteed to be
durable if a crash occurs.
.SH "SEE ALSO"
abort(l),
begin(l).
