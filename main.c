#include <stdio.h>

int main()
{
  int character;
  int characterCount = 0;
  int characterCountTmp = 0;
  int characterCountTotal = 0;
  int wordCount = 0;
  int wordCountTmp = 0;
  int wordCountTotal = 0;
  int mostWords;
  int mostCharacters;
  int lineNumber = 1;
  int lineNumberTotal = 0;
  int wordState = 0;
  int newLine = 1;


  while((character = getchar()) != EOF)
  {
    if (newLine == 1)
    {
      printf("%2d. ", lineNumber);
    }
    if(character != '\n')
    {
      printf("%c", character);
      ++characterCount;
      newLine = 0;
    }
    if(character == '\n')
    {
      printf("(%d, %d)", wordCount, characterCount);
      printf("%c", character);
      ++lineNumber;
      newLine = 1;
      wordCountTotal += wordCount;
      if (wordCount >= wordCountTmp)
      {
        wordCountTmp = wordCount;
        mostWords = lineNumber;
      }
      wordCount = 0;
      characterCountTotal += characterCount;
      if (characterCount >= characterCountTmp)
      {
        characterCountTmp = characterCount;
        mostCharacters = lineNumber;
      }
      characterCount = 0;
    }
    if (character == ' ' || character == '\n' || character == '\t')
    {
      wordState = 0;
    }
    else if (wordState == 0)
    {
      wordState = 1;
      ++ wordCount;
    }
  }
  printf("%d lines, %d words, %d characters\n", lineNumber - 1,
         wordCountTotal, characterCountTotal);
  printf("Line %d has the most words with %d\n", mostWords - 1, wordCountTmp);
  printf("Line %d has the most characters with %d\n", mostCharacters - 1,
         characterCountTmp);
}
