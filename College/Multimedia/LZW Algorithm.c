#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_SIZE 5
#define IP_BIT_SIZE 5
#define OP_BIT_SIZE 6
#define INPUT_SIZE 1001

struct dict
{
  int code;
  char sequence[CHAR_SIZE];
} * dict;
int dictLength = 0;

void initDict();
void printDict(const char *);
char *decode(int *, int);
int *encode(const char *, int *);
char *findInDict_decode(int, int);
int findInDict_encode(char *, char, int);

int main()
{
  char *decodedData = "";
  int i, opLen, *opCode = NULL;

  // Use either const string or generate random

  // Const string
  // const char str[INPUT_SIZE] = "TOBEORNOTTTTOBEORTOBEORNOT";

  // Generate random string
  char str[INPUT_SIZE] = "";
  srand(time(0));
  for (i = 0; i < INPUT_SIZE - 1; i++)
    str[i] = 'A' + rand() % ('Z' - 'A' + 1);

  printf("Input string:\t %s\n", str);
  printf("Input size:\t %lu\n", strlen(str) * IP_BIT_SIZE);

  // ENCODE
  initDict();
  opCode = encode(str, &opLen);
  printf("Encoded data:\t ");
  for (i = 0; i < opLen; i++)
    printf("%d %s", opCode[i], (i == opLen - 1) ? "\n" : "| ");
  printf("Encoded size:\t %u\n", opLen * OP_BIT_SIZE);
  // printDict("Encode");

  // DECODE
  initDict();
  decodedData = decode(opCode, opLen);
  printf("Decoded data:\t %s\n", decodedData);
  printf("Decoded size:\t %lu\n", strlen(decodedData) * IP_BIT_SIZE);
  // printDict("Decode");

  printf("Compressed size: %lu%%\n", (opLen * OP_BIT_SIZE * 100) / (strlen(str) * IP_BIT_SIZE));
  printf("Same:\t\t %s\n", strcmp(str, decodedData) == 0 ? "True" : "False");

  return 0;
}

void initDict()
{
  int i, code;
  unsigned char seq[2];

  dictLength = 0;
  for (i = 'A', code = 1; i <= 'Z'; i++, code++)
  {
    dict = (struct dict *)realloc(dict, (++dictLength) * sizeof(struct dict));

    seq[0] = i;
    seq[1] = 0;

    dict[i - 'A'].code = code;
    strcpy(dict[i - 'A'].sequence, seq);
  }
}

void printDict(const char *str)
{
  int i;

  printf("%s Dictonary: \n", str);
  for (i = 0; i < dictLength; i++)
    printf("%d \t %s\n", dict[i].code, dict[i].sequence);

  printf("\n");
}

char *decode(int *opCode, int len)
{
  int i, opStrlen = 1;
  char *opStr = NULL, curSeq[CHAR_SIZE] = "";

  opStr = (char *)calloc(opStrlen, sizeof(char));

  for (i = 0; i < len; i++)
  {
    strcpy(curSeq, findInDict_decode(opCode[i], (i == 0) ? -1 : opCode[i - 1]));

    opStrlen += strlen(curSeq);
    opStr = (char *)realloc(opStr, opStrlen * sizeof(char));
    strcat(opStr, curSeq);
  }

  return opStr;
}

int *encode(const char *str, int *_opLen)
{
  const int len = strlen(str);

  int i, code, opCode, *_opCode = NULL;
  char cur[CHAR_SIZE] = "", next, seq[2] = "";

  *_opLen = 0;

  for (i = 0; i < len; i++)
  {
    seq[0] = str[i];
    strcat(cur, seq);
    next = str[i + 1];

    opCode = findInDict_encode(cur, next, i == len - 1);

    if (opCode != -1)
    {
      _opCode = (int *)realloc(_opCode, (*_opLen + 1) * sizeof(int));
      _opCode[*_opLen] = opCode;
      *_opLen += 1;

      strcpy(cur, "");
    }
  }

  return _opCode;
}

char *findInDict_decode(int cur, int prev)
{
  int i, flag = 0;
  char *curSeq = NULL, prevSeq[CHAR_SIZE] = "", combo[CHAR_SIZE + 1] = "", seq[2] = "";

  curSeq = (char *)calloc(CHAR_SIZE, sizeof(char));

  for (i = 0; i < dictLength; i++)
  {
    if (dict[i].code == cur)
    {
      flag = 1;
      strcpy(curSeq, dict[i].sequence);
    }

    if (prev != -1 && dict[i].code == prev)
      strcpy(prevSeq, dict[i].sequence);
  }

  if (flag == 0)
  {
    // Cur code in not in dict so make new curSeq
    // New encoded string = old encoded string + the first character of the old encoded string
    strcpy(curSeq, prevSeq);
    seq[0] = prevSeq[0];
    strcat(curSeq, seq);
  }

  if (prev != -1)
  {
    strcpy(combo, prevSeq);
    seq[0] = curSeq[0];
    strcat(combo, seq);

    dict = (struct dict *)realloc(dict, (dictLength + 1) * sizeof(struct dict));
    dict[dictLength].code = dict[dictLength - 1].code + 1;
    strcpy(dict[dictLength].sequence, combo);
    dictLength++;
  }

  return curSeq;
}

int findInDict_encode(char *cur, char next, int last)
{
  int i, pos = -1;
  char combo[CHAR_SIZE + 1] = "", seq[2] = {next, 0};

  strcpy(combo, cur);
  strcat(combo, seq);

  for (i = 0; i < dictLength; i++)
  {
    if (strcmp(dict[i].sequence, combo) == 0)
      return (last == 1) ? dict[i].code : -1;

    if (strcmp(dict[i].sequence, cur) == 0)
      pos = i;
  }

  dict = (struct dict *)realloc(dict, (dictLength + 1) * sizeof(struct dict));
  dict[dictLength].code = dict[dictLength - 1].code + 1;
  strcpy(dict[dictLength].sequence, combo);
  dictLength++;

  return dict[pos].code;
}