#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    vector<Node *> children;
    bool end;
    Node()
    {
        children.assign(26, NULL);
        end = false;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        auto it = root;
        for (auto ch : word)
        {
            if (it->children[ch - 'a'] == NULL)
                it->children[ch - 'a'] = new Node();
            it = it->children[ch - 'a'];
        }
        it->end = true;
    }

    bool search(string word)
    {
        auto it = root;
        for (auto ch : word)
        {
            if (it->children[ch - 'a'] == NULL)
                return false;
            it = it->children[ch - 'a'];
        }
        return it->end;
    }

    bool startsWith(string prefix)
    {
        auto it = root;
        for (auto ch : prefix)
        {
            if (it->children[ch - 'a'] == NULL)
                return false;
            it = it->children[ch - 'a'];
        }
        return true;
    }
};

int main()
{

    return 0;
}