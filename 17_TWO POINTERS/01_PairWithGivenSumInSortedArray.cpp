#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to count pairs in a sorted array that sum up to a given target
    int countPairs(vector<int> &arr, int target)
    {
        int start = 0;
        int end = arr.size() - 1;

        // Initialize count of pairs
        int cnt = 0;

        while (start < end)
        {
            // Calculate sum of elements at start and end pointers
            int sum = arr[start] + arr[end];

            if (sum == target)
            {
                // Increment count if sum equals target
                cnt++;

                // Temporary pointer to check for duplicates
                int temp = start + 1;

                // Check for duplicates and increment count accordingly
                while (temp < end && arr[temp] == arr[temp - 1])
                {
                    cnt++;
                    // Move temporary pointer forward
                    temp++;
                }

                // Move end pointer backward
                end--;
            }
            else if (sum < target)
            {
                // Move start pointer forward if sum is less than target
                start++;
            }
            else
            {
                // Move end pointer backward if sum is greater than target
                end--;
            }
        }

        return cnt;
    }
};

int main()
{
    Solution solution;

    vector<int> arr = {1, 2, 2, 3, 4, 5};
    int target = 5;

    int result = solution.countPairs(arr, target);
    cout << "Number of pairs with sum " << target << " is: " << result << endl;

    return 0;
}