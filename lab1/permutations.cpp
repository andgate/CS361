#include <iostream>
#include <cstring>

using namespace std;

void permute(int n, int k, int acc[], int accSize, bool marks[]);

int main(int argc, char* argv[])
{
  int n = atoi(argv[1]);  // available digits
  int k = atoi(argv[2]);  // length of permutation

  // Heap allocate our marks and accumulator
  bool *marks = new bool[n] { false };
  int *acc = new int[k] { 0 };
  permute(n, k, acc, 0, marks);
  cout << endl;

  return 0;
}


void printAcc(int *acc, int k)
{
  for(int i = 0; i < k; ++i)
    cout << acc[i];
}


void permute(int n,  int k, int *acc, int accSize, bool *marks)
{
  // If acc is full then print
  if (accSize == k) {
    printAcc(acc, k);
    cout << " ";
    return;
  }

  for (int i = 0; i < n; ++i)
  {
    if (!marks[i])
    {
      marks[i] = true;
      acc[accSize] = i;
      permute(n, k, acc, accSize+1, marks);
      marks[i] = false;
    }
  }
}
