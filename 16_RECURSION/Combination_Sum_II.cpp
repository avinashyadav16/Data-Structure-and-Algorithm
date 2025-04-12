/**
 *  @file: Combination_Sum_II.cpp
 *  @author: Avinash Yadav
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH: TLE
// 1. Generate all possible combinations of the candidates array using recursion.
// 2. For each combination, check if the sum of the elements equals the target.
//        If it does, add it to the result set.
// 3. Use a set to store the combinations to avoid duplicates.
// 4. Return the result set as a vector of vectors.
// 5. The time complexity is O(2^n * k) in the worst case, where n is the number of candidates and k is the average size of the combinations found.
//        This is because we are generating all possible combinations of the candidates array.
// 6. The space complexity is O(n) for the recursion stack and the result set.
// 7. The set is used to store unique combinations, so the space complexity for the set is O(k), where k is the number of unique combinations found.
// 8. The overall space complexity is O(n + k).

class Solution
{
public:
    void findCombinations(int idx, int target, vector<int> &candidates, set<vector<int>> &result, vector<int> &ds)
    {
        if (idx == candidates.size())
        {
            if (target == 0)
            {
                result.insert(ds);
            }

            return;
        }

        // PICK UP THE ELEMENT:
        if (candidates[idx] <= target)
        {
            ds.push_back(candidates[idx]);

            findCombinations(idx + 1, target - candidates[idx], candidates, result, ds);

            ds.pop_back();
        }

        findCombinations(idx + 1, target, candidates, result, ds);
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        set<vector<int>> result;

        vector<int> ds;

        sort(candidates.begin(), candidates.end());

        findCombinations(0, target, candidates, result, ds);

        return vector<vector<int>>(result.begin(), result.end());
    }
};

int main()
{

    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> combinations = sol.combinationSum2(candidates, target);

    for (const auto &comb : combinations)
    {
        for (int num : comb)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}