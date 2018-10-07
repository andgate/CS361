// Gabriel Anderson
// Lab 2
// CS361

#include <iostream>
#include <fstream>

using namespace std;


void swap(string& str, int i, int j)
{
  char tmp = str[i];
  str[i] = str[j];
  str[j] = tmp;
}


void reverse(string& str, int i, int j)
{
  int wordSize = j - i + 1;
  int mid = i + wordSize/2;

  while (i < mid) {
    swap(str, i, j);
    ++i, --j;
  }
}


int main(int argc, char* argv[])
{
  ifstream file("input.txt");

  while (file.good())
  {
    string line;
    getline(file, line);
    if (file.eof()) break;

    int wordBegin = 0;
    int wordEnd = 0;
    for (int i = 0; i < line.length(); ++i)
    {
      if ( isspace(line[i]) ) {
        wordBegin = wordEnd = i+1;
      } else {
        wordEnd = i;
      }

      bool isNextCharSpace = i+1 < line.length() && isspace(line[i+1]);
      bool isLastChar = i+1 == line.length();
      bool canReverseWord = (wordEnd - wordBegin) > 0;
      bool shouldReverseWord = (isNextCharSpace || isLastChar) && canReverseWord;

      if (shouldReverseWord) reverse(line, wordBegin, wordEnd);
    }

    cout << line << endl;
  }

  return 0;
}


