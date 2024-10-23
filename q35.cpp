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
    // To do a binary search we are going to take the total length and then search by dividing the list in half
    int vecLength = nums.capacity();
    int index = 0;
    int numIterations = ceil(log(vecLength));
    // cout << vecLength;
    int midpoint = vecLength / 2;
    for (int i = 0; i < numIterations; i++)
    {
      if (nums[midpoint] == target)
      {
        // cout << "midpoint early: " << midpoint << "\n";
        return midpoint;
      }
      else if (nums[midpoint] > target)
      {
        midpoint = midpoint - (midpoint / 2);
      }
      else if (nums[midpoint] < target)
      {
        midpoint = midpoint + (midpoint / 2);
      }
    }

    // cout << "location to place: " << midpoint << "\n";
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
  s.searchInsert(v, 5);
  return 0;
}