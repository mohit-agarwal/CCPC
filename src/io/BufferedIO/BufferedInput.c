#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "BufferedInput.h"

struct BufferedInputStream {
  FILE * inputStream;
  char * bufferStream;
  char * bufferPointer;
  unsigned long long bufferSize;
  unsigned long long bytesReadToBuffer;
  unsigned long long bytesReadFromBuffer;
  int eofRead;
  int readError;
};

void refreshBuffer (struct BufferedInputStream * bis) {
  if (bis->eofRead) return;
  
  unsigned long long bytesToCopy = 0;
  
  if (bis->bytesReadFromBuffer > 0) {
    bytesToCopy = bis->bytesReadToBuffer - bis->bytesReadFromBuffer;

    memmove(bis->bufferStream, bis->bufferPointer, bytesToCopy);
    
    bis->bufferPointer = bis->bufferStream;
    bis->bytesReadFromBuffer = 0;
    bis->bytesReadToBuffer = bytesToCopy;
  }
  
  size_t membersRead = fread_unlocked(bis->bufferStream + bytesToCopy, sizeof(char), bis->bufferSize - bis->bytesReadToBuffer, bis->inputStream);
  
  bis->bytesReadToBuffer += membersRead * (unsigned long long) sizeof(char);
  
  if (ferror(bis->inputStream)) {
    fprintf(stderr, "Error encountered in reading from input stream.");
    abort();
  } else if (feof(bis->inputStream)) {
    clearerr(bis->inputStream);
    bis->eofRead = 1;
  }
}

struct BufferedInputStream * bufferedInputStream_sb (FILE * inputStream, unsigned long long bufferSize) {
  struct BufferedInputStream * bis = (struct BufferedInputStream *) malloc(sizeof(struct BufferedInputStream));
  
  bis->inputStream = inputStream;
  bis->bufferStream = (char *) malloc(sizeof(char) * bufferSize);
  bis->bufferPointer = bis->bufferStream;
  bis->bufferSize = bufferSize;
  bis->bytesReadToBuffer = 0;
  bis->bytesReadFromBuffer = 0;
  bis->readError = 0;
  bis->eofRead = 0;
  
  refreshBuffer(bis);
  
  return bis;
}

struct BufferedInputStream * bufferedInputStream_s (FILE * inputStream) {
  return bufferedInputStream_sb (inputStream, _DEFAULT_INPUT_BUFFER_SIZE);
}

struct BufferedInputStream * bufferedInputStream_b (unsigned long long bufferSize) {
  return bufferedInputStream_sb (stdin, bufferSize);
}

struct BufferedInputStream * bufferedInputStream () {
  return bufferedInputStream_sb (stdin, _DEFAULT_INPUT_BUFFER_SIZE);
}

void setError(struct BufferedInputStream * bis) {
  bis->readError = 1;
}

int isBufferedInputError(struct BufferedInputStream * bis) {
  return bis->readError;
}

char bufferedReadChar(struct BufferedInputStream * bis) {
  if(bis->bytesReadToBuffer >= bis->bytesReadFromBuffer - 1){
    if(bis->eofRead) {
      setError(bis);
      return 0;
    }
    else {
      refreshBuffer(bis);
    }
  }

  char value = *(bis->bufferPointer);
  bis->bufferPointer += 1;
  bis->bytesReadFromBuffer += 1;
  return value;
}

short bufferedReadShort(struct BufferedInputStream * bis) {
  if(bis->bytesReadFromBuffer >= bis->bytesReadToBuffer - 1) {
    if(bis->eofRead) {
      setError(bis);
      return 0;
    }
    else {
      refreshBuffer(bis);
    }
  }
  
  char * tempPtr;
  short value = (short) strtol(bis->bufferPointer, &tempPtr, 0);
  if(tempPtr == bis->bufferPointer) {
    setError(bis);
    return 0;
  }
  
  if (tempPtr >= (bis->bufferStream + bis->bytesReadToBuffer) - 1) {
    if (!bis->eofRead) {
      refreshBuffer(bis);
        value = (short) strtol(bis->bufferPointer, &tempPtr, 0);    }
  }

  bis->bytesReadFromBuffer += (tempPtr - bis->bufferPointer);
  bis->bufferPointer = tempPtr;  
  return value;
}

int bufferedReadInt(struct BufferedInputStream * bis) {
  if(bis->bytesReadFromBuffer >= bis->bytesReadToBuffer - 1) {
    if(bis->eofRead) {
      setError(bis);
      return 0;
    }
    else {
      refreshBuffer(bis);
    }
  }

  char * tempPtr;
  int value = (int) strtol(bis->bufferPointer, &tempPtr, 0);
  if(tempPtr == bis->bufferPointer) {
    setError(bis);
    return 0;
  }

  if (tempPtr >= (bis->bufferStream + bis->bytesReadToBuffer) - 1) {
    if (!bis->eofRead) {
      refreshBuffer(bis);
      value = (int) strtol(bis->bufferPointer, &tempPtr, 0);
    }
  }

  bis->bytesReadFromBuffer += (tempPtr - bis->bufferPointer);
  bis->bufferPointer = tempPtr;
  return value;
}

long bufferedReadLong(struct BufferedInputStream * bis) {
  if(bis->bytesReadFromBuffer >= bis->bytesReadToBuffer - 1) {
    if(bis->eofRead) {
      setError(bis);
      return 0;
    }
    else {
      refreshBuffer(bis);
    }
  }

  char * tempPtr;
  long value = (long) strtol(bis->bufferPointer, &tempPtr, 0);
  if(tempPtr == bis->bufferPointer) {
    setError(bis);
    return 0;
  }

  if (tempPtr >= (bis->bufferStream + bis->bytesReadToBuffer) - 1) {
    if (!bis->eofRead) {
      refreshBuffer(bis);
      value = (long) strtol(bis->bufferPointer, &tempPtr, 0);
    }
  }

  bis->bytesReadFromBuffer += (tempPtr - bis->bufferPointer);
  bis->bufferPointer = tempPtr;  
  return value;
}

long long bufferedReadLongLong(struct BufferedInputStream * bis) {
  if(bis->bytesReadFromBuffer >= bis->bytesReadToBuffer - 1) {
    if(bis->eofRead) {
      setError(bis);
      return 0;
    }
    else {
      refreshBuffer(bis);
    }
  }

  char * tempPtr;
  long long value = (long long) strtol(bis->bufferPointer, &tempPtr, 0);
  if(tempPtr == bis->bufferPointer) {
    setError(bis);
    return 0;
  }

  if (tempPtr >= (bis->bufferStream + bis->bytesReadToBuffer) - 1) {
    if (!bis->eofRead) {
      refreshBuffer(bis);
      value = (long long) strtoll(bis->bufferPointer, &tempPtr, 0);
    }
  }

  bis->bytesReadFromBuffer += (tempPtr - bis->bufferPointer);
  bis->bufferPointer = tempPtr;  
  return value;
}

float bufferedReadFloat(struct BufferedInputStream * bis) {
  if(bis->bytesReadFromBuffer >= bis->bytesReadToBuffer - 1) {
    if(bis->eofRead) {
      setError(bis);
      return 0;
    }
    else {
      refreshBuffer(bis);
    }
  }

  char * tempPtr;
  float value = (float) strtof(bis->bufferPointer, &tempPtr);
  if(tempPtr == bis->bufferPointer) {
    setError(bis);
    return 0;
  }

  if (tempPtr >= (bis->bufferStream + bis->bytesReadToBuffer) - 1) {
    if (!bis->eofRead) {
      refreshBuffer(bis);
      value = (float) strtof(bis->bufferPointer, &tempPtr);
    }
  }

  bis->bytesReadFromBuffer += (tempPtr - bis->bufferPointer);
  bis->bufferPointer = tempPtr;  
  return value;
}

double bufferedReadDouble(struct BufferedInputStream * bis) {
  if(bis->bytesReadFromBuffer >= bis->bytesReadToBuffer - 1) {
    if(bis->eofRead) {
      setError(bis);
      return 0;
    }
    else {
      refreshBuffer(bis);
    }
  }

  char * tempPtr;
  double value = (double) strtod(bis->bufferPointer, &tempPtr);
  if(tempPtr == bis->bufferPointer) {
    setError(bis);
    return 0;
  }

  if (tempPtr >= (bis->bufferStream + bis->bytesReadToBuffer) - 1) {
    if (!bis->eofRead) {
      refreshBuffer(bis);
      value = (double) strtod(bis->bufferPointer, &tempPtr);
    }
  }

  bis->bytesReadFromBuffer += (tempPtr - bis->bufferPointer);
  bis->bufferPointer = tempPtr;  
  return value;
}

long double bufferedReadLongDouble(struct BufferedInputStream * bis) {
  if(bis->bytesReadFromBuffer >= bis->bytesReadToBuffer - 1) {
    if(bis->eofRead) {
      setError(bis);
      return 0;
    }
    else {
      refreshBuffer(bis);
    }
  }

  char * tempPtr;
  long double value = (long double) strtod(bis->bufferPointer, &tempPtr);
  if(tempPtr == bis->bufferPointer) {
    setError(bis);
    return 0;
  }

  if (tempPtr >= (bis->bufferStream + bis->bytesReadToBuffer) - 1) {
    if (!bis->eofRead) {
      refreshBuffer(bis);
      value = (long double) strtod(bis->bufferPointer, &tempPtr);
    }
  }

  bis->bytesReadFromBuffer += (tempPtr - bis->bufferPointer);
  bis->bufferPointer = tempPtr;  
  return value;
}

