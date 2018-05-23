#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#define FIFO_FILE "file"

int main(int argc, char *argv[])
{
  FILE *fp;
  umask(0);
  mknod(FIFO_FILE, S_IFIFO | 0666, 0);

  if ((fp = fopen(FIFO_FILE, "w")) == NULL) {
    perror("fopen");
    exit(1);
  }

  fputs(argv[1], fp);
  fclose(fp);

  return(0);
}
