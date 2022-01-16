#include <iostream>
using namespace std;

/**
 * MEMBER FUNCTION NAME:
 *    getMaxPond
 * PURPOSE:
 *    The function calculates the water retention of
 *    a potential dig site.
 * PARAMETER:
 *    int* arr, int n
 * RETURN VALUE:
 *    int: returns the maximum possible amount of retained water
 */
int getMaxPond(int* arr, int n)
{
  // find number of indicies that are equal or higher than current index
  // if they are less then that, add them to lowPoint
  // when the next index reached is greater or equal to current index,
  // add the lowPoint to the toatal and set lowPoint to 0
  // multiply that number by index depth (value) to get deposit
  // and add that to the max deposit then compare all other deposits
  int maxAmount = 0;
  for (int i = 0; i < n; i++)
  {
    int deposit = -1;
    int lowPoint = 0;
    for(int j = 0; j < n; j++)
    {
      if(arr[j] >= arr[i])
      {
        // add 1 + the lowPoint value, then reassing 0 to lowPoint
        deposit += 1 + lowPoint;
        lowPoint = 0;
      }
      else if(arr[j] < arr[i] && deposit >= 0)
      {
        lowPoint += 1;
      }
    }
    // determines and holds maxAmount
    deposit *= arr[i];
    if(deposit > maxAmount)
    {
      maxAmount = deposit;
    }
  }

  return maxAmount;
}
int main() {
  // EXAMPLE
  int arr[] = {1,99,1};
  cout << getMaxPond(arr, sizeof(arr)/sizeof(arr[0])) << endl; // 66

  return 0;
}
