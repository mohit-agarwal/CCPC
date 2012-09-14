#ifndef BUFFEREDINPUT
#define BUFFEREDINPUT

const static unsigned long long _DEFAULT_INPUT_BUFFER_SIZE = 786432; // Defaut size is 0.75 MB

struct BufferedInputStream;

extern struct BufferedInputStream * bufferedInputStream_sb (FILE * , unsigned long long);
extern struct BufferedInputStream * bufferedInputStream_s (FILE *);
extern struct BufferedInputStream * bufferedInputStream_b (unsigned long long);
extern struct BufferedInputStream * bufferedInputStream ();

extern int isBufferedInputError(struct BufferedInputStream *);

extern char bufferedReadChar(struct BufferedInputStream *);
extern short bufferedReadShort(struct BufferedInputStream *);
extern int bufferedReadInt(struct BufferedInputStream *);
extern long bufferedReadLong(struct BufferedInputStream *);
extern long long bufferedReadLongLong(struct BufferedInputStream *);
extern float bufferedReadFloat(struct BufferedInputStream *);
extern double bufferedReadDouble(struct BufferedInputStream *);
extern long double bufferedReadLongDouble(struct BufferedInputStream *);

extern char * bufferedReadLine(struct BufferedInputStream *);
extern char * bufferedReadDelimitedString(struct BufferedInputStream *, char *);

#endif
