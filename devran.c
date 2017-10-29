#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int ranNum(){
  int fd = open("/dev/random", O_RDONLY);
  int *ip = malloc(sizeof(int));
  read(fd, ip, 4);
  int val = *ip;
  free(ip);
  return val;
}
void main(){
  //printf("%d\n", ranNum());
  umask(0);
  int arr1[10];
  int arr2[10];
  int i;

  printf("\nGenerating random numbers:\n");
  for (i = 0; i < 10; i++){
    arr1[i] = ranNum();
    printf("\trandom %d: %d\n", i, arr1[i]);
  }

  printf("\nWriting numbers to file...\n");
  int fd = open("file", O_CREAT | O_WRONLY, 0644);
  write(fd, arr1, 40);
  close(fd);

  printf("\nReading numbers from file...\n");
  fd = open("file", O_RDONLY, 0644);
  read(fd, arr2, 40);
  close(fd);

  printf("\nVerification that written values were the same:\n");
  for (i = 0; i < 10; i++){
    printf("\trandom %d: %d\n", i, arr2[i]);
  }
}
