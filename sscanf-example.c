// jdh 12-16-22
// fgets() and sscanf() example

#include <stdio.h>
#include <stdlib.h>

#define BUFFLEN    1024
#define TMPBUFFLEN 64

int main(int argc, char *argv[]) {
  char buffer[BUFFLEN];
  char tmpbuf1[64];
  char tmpbuf2[64];
  int tmpval;
  int linenum;
  int nf;
  FILE *fp;
  char *chp;

  if (argc < 2) {
    printf("error: need filename\n");
    return 8;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("cannot open file '%s' for reading\n", argv[1]);
    return 8;
  }

  linenum = 0;

  chp = fgets(buffer, BUFFLEN, fp);
  while ( chp != NULL ) {
    linenum = linenum + 1;
    // this will parse a line from a CSV file; it expects string,string,integer
    nf = sscanf(buffer, "%[A-Za-z.' -],%[A-Za-z.' -],%d,", tmpbuf1, tmpbuf2, &tmpval);
    if (nf == 3) {
      printf("val1 = '%s'; val2 = '%s'; val3 = %d\n", tmpbuf1, tmpbuf2, tmpval);
    } else {
      printf("line %d error: not enough values; or incorrect format\n", linenum);
    }
    chp = fgets(buffer, BUFFLEN, fp);
  }

  fclose(fp);

  return 0;
} // main()
