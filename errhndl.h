/* This file has no copyright assigned and is placed in the Public Domain. */
#ifndef ERRHNDL_H
#define ERRHNDL_H

#include <setjmp.h>

/* "Internal" structure; only access through provided macros */
typedef struct {
	jmp_buf buffer;
	int type, in_try_block;
} errinfo;

#define ERRGET(err) ((err).type)

#define ERRTHROW(err, t) do{ if((err).in_try_block){ longjmp((err).buffer, (err).type = (t)); } }while(0)
#define ERRTRY(err, body) if((((err).in_try_block = 1) == 2) || (!setjmp((err).buffer))){ body (err).in_try_block = 0; }
#define ERRCATCH(err, body) else{ (err).in_try_block = 0; body }

#endif
