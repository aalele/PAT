#include <iostream>
#include <vector>

using namespace std;

class Node
{
  public:
    int value;
    Node *lchild;
    Node *rchild;
    Node(int value)
    {
        this->value = value;
        lchild = rchild = NULL;
    }
};

Node *buildBST(vector<int> &v, int begin, int end)
{
    if (begin == end)
        return NULL;
    Node *root = new Node(v[begin]);
    int mid;
    for (mid = begin; mid < end; mid++)
    {
        if (v[mid] > v[begin])
            break;
    }
    root->lchild = buildBST(v, begin + 1, mid);
    root->rchild = buildBST(v, mid, end);

    return root;
}

void prtVec(vector<int> &v)
{
    for (auto e : v)
    {
        cout << e << endl;
    }
}

void search(vector<int> &a, int value, Node *root)
{
    if (root == NULL)
    {
        return;
    }
    a.push_back(root->value);
    if (value > root->value)
    {
        search(a, value, root->rchild);
    }
    else if (value < root->value)
    {
        search(a, value, root->lchild);
    }
}

int main(void)
{
    int M, N;
    cin >> M >> N;
    vector<int> v;
    for (int i = 0; i < N; ++i)
    {
        int value;
        cin >> value;
        v.push_back(value);
    }
    Node *root = buildBST(v, 0, N);
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        vector<int> uPath, vPath;
        search(uPath, u, root);
        search(vPath, v, root);
        //prtVec(uPath);
        //prtVec(vPath);
        int uLast = *uPath.rbegin();
        int vLast = *vPath.rbegin();
        if (uLast != u && vLast != v)
        {
            cout << "ERROR: " << u << " and " << v << " are not found." << endl;
        }
        else if (uLast != u && vLast == v)
        {
            cout << "ERROR: " << u << " is not found." << endl;
        }
        else if (uLast == u && vLast != v)
        {
            cout << "ERROR: " << v << " is not found." << endl;
        }
        else
        {
            int k;
            for (k = 0; i < uPath.size() && k < vPath.size(); ++k)
            {
                if (uPath[k] != vPath[k])
                {
                    break;
                }
            }
            if (k == uPath.size())
            {
                cout << u << " is an ancestor of " << v << '.' << endl;
            }
            else if (k == vPath.size())
            {
                cout << v << " is an ancestor of " << u << '.' << endl;
            }
            else
            {
            cout << "LCA of " << u << " and " << v << " is " << uPath[k - 1] << '.' << endl;
            }
        }
    }
    return 0;
}