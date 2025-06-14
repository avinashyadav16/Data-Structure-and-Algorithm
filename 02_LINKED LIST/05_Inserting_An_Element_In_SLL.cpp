#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// ---------------------------------------------------------------

Node *insertBeforeElement(Node *head, int ele, int val)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->data == val)
    {
        Node *newNode = new Node(ele, head);

        return newNode;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        if (temp->next->data == val)
        {
            Node *newNode = new Node(ele);
            newNode->next = temp->next;

            temp->next = newNode;

            break;
        }

        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        cout << "Given Value is out of bound." << endl;
    }

    return head;
}

// ---------------------------------------------------------------
// DRIVER CODE:

Node *convertArrayToLL(vector<int> nums)
{
    Node *head = new Node(nums[0]);
    Node *mover = head;

    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i]);

        mover->next = temp;

        mover = temp;
    }

    return head;
}

void displayLL(Node *head)
{
    cout << "The Linked List Is: ";

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
}

int main()
{
    cout << "Enter The LL Values:  ";

    string line;
    getline(cin, line);

    stringstream ss(line);

    int input;
    vector<int> nums;

    while (ss >> input)
    {
        nums.push_back(input);
    }

    Node *head = convertArrayToLL(nums);

    int val;
    cout << "Enter The New Node Value: ";
    cin >> val;

    int k;
    cout << "Enter The Element Value: ";
    cin >> k;

    head = insertBeforeElement(head, val, k);

    displayLL(head);

    return 0;
}