#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int ranNum() {
  int fd = open("/dev/random", O_RDONLY);
  int *ip = malloc(sizeof(int));
  read(fd, ip, 4);
  int val = *ip;
  free(ip);
  return val;
}
int main() {
  printf("%d\n", ranNum());
  return 0;
}
