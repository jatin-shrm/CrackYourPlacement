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

void sortList(Node *head)
{
    int cnt[3] = {0, 0, 0};
    Node *ptr = head;
    while (ptr)
    {
        cnt[ptr->data] += 1;
        ptr = ptr->next;
    }

    int idx = 0;
    ptr = head;
    while (ptr != nullptr)
    {

        if (cnt[idx] == 0)
            idx += 1;
        else
        {
            ptr->data = idx;
            cnt[idx] -= 1;
            ptr = ptr->next;
        }
    }
}
