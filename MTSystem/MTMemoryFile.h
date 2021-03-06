//---------------------------------------------------------------------------
//
//	MadTracker System Core
//
//		Platforms:	All
//		Processors: All
//
//	Copyright � 1999-2006 Yannick Delwiche. All rights reserved.
//
//	$Id: MTMemoryFile.h 100 2005-11-30 20:19:39Z Yannick $
//
//---------------------------------------------------------------------------
#ifndef MTMEMORYFILE_INCLUDED
#define MTMEMORYFILE_INCLUDED
//---------------------------------------------------------------------------
class MTLocalHook;
class MTLocalFile;
class MTLocalFolder;
//---------------------------------------------------------------------------
#include "MTFile.h"
//---------------------------------------------------------------------------
class MTMemoryHook : public MTFileHook{
public:
	MTMemoryHook();
	MTFile* MTCT fileopen(const char *url,int flags);
	MTFolder* MTCT folderopen(char *url);
	bool MTCT filecopy(char *source,char *dest);
	bool MTCT filerename(char *source,char *dest);
	bool MTCT filedelete(char *url);
	void MTCT filetype(const char *url,char *type,int length);
};

class MTMemoryFile : public MTFile{
public:
	MTMemoryFile(void *mem,int length,int access);
	MTMemoryFile(MTFile *parent,int start,int end,int access);
	~MTMemoryFile();
	int MTCT read(void *buffer,int size);
	int MTCT readln(char *buffer,int maxsize);
//	int MTCT reads(char *buffer,int maxsize);
	int MTCT write(const void *buffer,int size);
	int MTCT seek(int pos,int origin);
	void* MTCT getpointer(int offset,int size);
	void MTCT releasepointer(void *mem);
	int MTCT length();
	int MTCT pos();
	bool MTCT eof();
	bool MTCT seteof();
	bool MTCT gettime(int *modified,int *accessed);
	bool MTCT settime(int *modified,int *accessed);
	MTFile* MTCT subclass(int start,int length,int access);
private:
	int maccess;
	void *m;
	char *c;
	int cpos;
	int al,l;
	bool subclassed,autosize,autofree;
};
//---------------------------------------------------------------------------
extern MTMemoryHook memoryhook;
//---------------------------------------------------------------------------
#endif
