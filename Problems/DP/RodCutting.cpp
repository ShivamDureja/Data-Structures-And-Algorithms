#include <iostream>
#include<algorithm> // To use the built in max function
using namespace std;

int main() {
  int price[] = {2,5,7,8};
  int n = 5;

  // Declaring a 2D array, T
  int T[n-1][n+1];

  // Initializing the array to all zeros
  for(int i=0; i < n-1; i++)
  {
    for(int j=0; j < n+1; j++ )
    {
      T[i][j] = 0;
    }
  }

  for(int i=0; i < n-1; i++)
  {
    for(int j=0; j < n+1; j++ )
    {
      // First column => 0 length of rod => 0 profit
      if(j == 0) {
        continue;
      }

      // First row => T[i-1][j] doesn't exist so just pick the second value
      else if(i == 0) {
        T[i][j] = price[i] + T[i][j-i-1];
      }

      // where j <= i => T[i][j-i-1] doesn't exist so just pick the first value
      else if(j-i-1 < 0) {
        T[i][j] = T[i-1][j];
      }

      // using the whole expression
      else {
        T[i][j] = std::max(T[i-1][j], (price[i] + T[i][j-i-1]));
      }
    }
  }
  // Answer in the extreme bottom right cell
  cout << "Maximum profit is " << T[n-2][n] << endl;



  return 0;
}





