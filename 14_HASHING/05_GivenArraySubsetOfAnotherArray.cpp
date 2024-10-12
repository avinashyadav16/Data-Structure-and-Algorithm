#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> givenVector = {1, 6, 5, 2, 7, 9, 0, 8, 3, 1};
    vector<int> searchVector = {1, 3, 5, 9, 1};

    unordered_map<int, int> res;

    for (int i = 0; i < givenVector.size(); i++)
    {
        res[givenVector[i]]++;
    }

    bool isSubsetUsingMap = true;
    int countMap = 0;

    cout << "Using unordered_map:\n";
    for (int i = 0; i < searchVector.size(); i++)
    {
        if (res[searchVector[i]] > 0)
        {
            cout << searchVector[i] << " ";
            res[searchVector[i]]--;
            countMap++;
        }
        else
        {

            isSubsetUsingMap = false;
        }
    }
    cout << (countMap == searchVector.size() ? "\nYES" : "\nNO") << endl;

    set<int> stt;

    for (int i = 0; i < givenVector.size(); i++)
    {
        stt.insert(givenVector[i]);
    }

    bool isSubsetUsingSet = true;
    cout << "\nUsing set:\n";

    for (int i = 0; i < searchVector.size(); i++)
    {
        if (stt.find(searchVector[i]) == stt.end())
        {
            cout << "Missing Elements: " << searchVector[i] << " ";
            isSubsetUsingSet = false;
        }
        cout << searchVector[i] << " ";
    }
    cout << (isSubsetUsingSet ? "\nYES" : "\nNO") << endl;




    // Determine the maximum value in givenVector for the vector<bool> size
    int maxElement = 0;
    for (int x : givenVector)
    {
        if (x > maxElement)
        {
            maxElement = x;
        }
    }

    // Create a vector<bool> with size maxElement + 1 and initialize all to false
    vector<bool> isPresent(maxElement + 1, false);

    // Mark elements present in givenVector as true in vector<bool>
    for (int x : givenVector)
    {
        isPresent[x] = true;
    }

    // Check if all elements in searchVector are marked as true in vector<bool>
    bool isSubset = true;
    cout << "Using vector<bool>:\n";
    for (int x : searchVector)
    {
        if (x > maxElement || !isPresent[x])
        {
            // If x is outside the range or is not marked as present, it's not a subset
            cout << x << " ";
            isSubset = false;
        }
    }

    cout << (isSubset ? "\nYES" : "\nNO") << endl;

    return 0;
}
