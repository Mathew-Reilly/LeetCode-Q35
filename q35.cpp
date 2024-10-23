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
    // To do a binary search we are going to take the total length and then
    // search by dividing the list in half
    int vecLength = nums.size();
    // int numIterations = ceil(log(vecLength));
    // cout << vecLength;
    int midpoint = (vecLength / 2);
    int change = midpoint;

    if (nums[0] >= target)
    {
      return 0;
    }
    if (nums[vecLength - 1] < target)
    {
      return vecLength;
    }

    while (change > 0)
    {
      change = ((midpoint) / 2.0);
      if (nums[midpoint - 1] == target)
      {
        // cout << "midpoint early: " << midpoint << "\n";
        return midpoint;
      }
      else if (nums[midpoint] > target)
      {
        midpoint = midpoint - change;
      }
      else if (nums[midpoint] < target)
      {
        midpoint = midpoint + change;
      }
    }

    // cout << "location to place: " << midpoint - 1 << "\n";
    return midpoint;
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
  s.searchInsert(v, 2);
  return 0;
}
