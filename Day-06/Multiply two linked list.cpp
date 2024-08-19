using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};
#define mod 1000000007
class solution
{
public:
    long long multiplyTwoLists(Node *first, Node *second)
    {
        long long num1 = 0;
        long long num2 = 0;
        // code here
        while (first || second)
        {
            while (first)
            {
                num1 = ((num1 * 10) % mod + first->data % mod) % mod;
                first = first->next;
            }
            while (second)
            {
                num2 = ((num2 * 10) % mod + second->data % mod) % mod;
                second = second->next;
            }
        }
        return (num1 % mod * num2 % mod) % mod;
    }
};