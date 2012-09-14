#ifndef _BufferedInput
#define _BufferedInput

#include<ifstream.h>

struct BufferedInputStream

extern BufferedIStream * BufferedInputStream(File *);
extern BufferedIStream * BufferedInputStream();

extern char bufferedReadChar(struct BufferedInputStream);
extern signed char bufferedReadSignedChar(struct BufferedInputStream);
extern unsigned char bufferedReadUnsignedChar(struct BufferedInputStream);

extern short bufferedReadShort(struct BufferedInputStream);
extern short int bufferedReadShortInt(struct BufferedInputStream);
extern signed short bufferedReadSignedShort(struct BufferedInputStream);
extern signed short int bufferedReadSignedShortInt(struct BufferedInputStream);
extern unsigned short bufferedReadUnsignedShort(struct BufferedInputStream);
extern unsigned short int bufferedReadUnsignedShortInt(struct BufferedInputStream);

extern int bufferedReadInt(struct BufferedInputStream);
extern signed int bufferedReadSignedInt(struct BufferedInputStream);
extern unsigned bufferedReadUnsigned(struct BufferedInputStream);
extern unsigned int bufferedReadUnsignedInt(struct BufferedInputStream);

extern long bufferedReadLong(struct BufferedInputStream);
extern long int bufferedReadLongInt(struct BufferedInputStream);
extern signed long bufferedReadSignedLongInt(struct BufferedInputStream);
extern signed long int bufferedReadSignedLongInt(struct BufferedInputStream);
extern unsigned long bufferedReadUnsignedLong(struct BufferedInputStream);
extern unsigned long int bufferedReadUnsignedLongInt(struct BufferedInputStream);

extern long long bufferedReadLongLong(struct BufferedInputStream);
extern long long int bufferedReadLongLongInt(struct BufferedInputStream);
extern signed long long bufferedReadSignedLongLong(struct BufferedInputStream);
extern signed long long int bufferedReadSignedLongLongInt(struct BufferedInputStream);
extern unsigned long long bufferedReadUnsignedLongLong(struct BufferedInputStream);
extern unsigned long long int bufferedReadUnsignedLongLongInt(struct BufferedInputStream);

extern float bufferedReadFloat(struct BufferedInputStram);
extern double bufferedReadDouble(struct BufferedInputStram);
extern long double bufferedReadLongDouble(struct BufferedInputStram);

extern char * bufferedReadLine(struct BufferedInputStram);
extern char * bufferedReadDelimitedString(struct BufferedInputStram, char *);

#endif
