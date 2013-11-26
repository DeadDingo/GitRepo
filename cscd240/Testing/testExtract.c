#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {

  char buffer[30];
  char *line;
  line = (char *)malloc(30 * sizeof(char));

  printf("Enter a name for tokenization: ");
  scanf("%s", line);
  int len = strlen(line);

  char *curPos;

  curPos = &line[0];

  strncpy(buffer, curPos, len);

  buffer[len] = '\0';
  
  printf("%s\n", buffer);

  return 0;

}
