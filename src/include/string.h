/* Copyright (c) 2017 Tohack<tohack@foxmail.com>. All Rights Reserved. */

#ifndef _ToHack_CL_STRING_H
#define _ToHack_CL_STRING_H

typedef struct _string String;
struct _string{
	String* next;
	int	hash;
	int	len;
	char	data[0];
};

String* StoreString(char*, int);
String* CreateLabelString();
String* GetModuleName(char*);

#endif