// Mathew Reilly
// Binary Search Q35:
// Given a sorted array of (distinct) integers and a target value, return the index of the target value
// if it is already stored, otherwise return the index where it would be placed.
// must run in O(log n)
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {
    // First we need to do basic validations
    if (nums.empty() || nums.size() == 0)
    {
      return 0;
    }

    // Then we need our basic variables
    int median, left, right;

    // set our initial leftmost and rightmost indexes
    left = 0;
    right = nums.size() - 1; // subtract 1 to get last index

    // find the median repeatedly until the value is found or has failed to turn up
    while (left <= right)
    {
      // avoids overflow
      median = (left + (right - left)) / 2;

      if (nums[median] < target)
      {
        left = median + 1;
      }
      else if (nums[median] > target)
      {
        right = median - 1;
      }
      else
      {
        return median;
      }
    }

    // If the item is not found do one last check to place in the correct index
    return nums[median] < target ? median + 1 : median;
  }
};

int main()
{
  Solution s;
  vector<int> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(5);
  v.push_back(6);
  cout << "" << s.searchInsert(v, 5);
  return 0;
}
