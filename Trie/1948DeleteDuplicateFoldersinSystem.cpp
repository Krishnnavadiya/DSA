#include <bits/stdc++.h>
using namespace std;

// 1948. Delete Duplicate Folders in System

class Node
{
public:
    map<string, Node *> children;
    bool deleted = false;

    Node() = default;
    ~Node()
    {
        for (auto &pair : children)
        {
            delete pair.second;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        Node *root = new Node();

        for (const auto &path : paths)
        {
            Node *curr = root;
            for (const string &name : path)
            {
                if (curr->children.find(name) == curr->children.end())
                {
                    curr->children[name] = new Node();
                }
                curr = curr->children[name];
            }
        }

        unordered_map<string, vector<Node *>> map;
        encode(root, map);

        for (const auto &group : map)
        {
            if (group.second.size() > 1)
            {
                for (Node *n : group.second)
                {
                    n->deleted = true;
                }
            }
        }

        vector<vector<string>> result;
        vector<string> path;
        collect(root, path, result);

        delete root;
        return result;
    }

private:
    string encode(Node *node, unordered_map<string, vector<Node *>> &map)
    {
        if (node->children.empty())
            return "()";

        vector<string> parts;
        for (const auto &entry : node->children)
        {
            string sub = encode(entry.second, map);
            parts.push_back(entry.first + sub);
        }
        sort(parts.begin(), parts.end());

        string sign = "(";
        for (const string &part : parts)
        {
            sign += part;
        }
        sign += ")";

        map[sign].push_back(node);
        return sign;
    }

    void collect(Node *node, vector<string> &path, vector<vector<string>> &res)
    {
        for (const auto &entry : node->children)
        {
            if (entry.second->deleted)
                continue;
            path.push_back(entry.first);
            res.push_back(path);
            collect(entry.second, path, res);
            path.pop_back();
        }
    }
};

int main()
{
    Solution sol;

    vector<vector<string>> paths = {
        {"a"},
        {"c"},
        {"a", "b"},
        {"c", "b"},
        {"a", "b", "x"},
        {"c", "b", "x"},
        {"a", "b", "x", "y"}};

    vector<vector<string>> result = sol.deleteDuplicateFolder(paths);

    cout << "Remaining folders after deleting duplicates:\n";
    for (const auto &path : result)
    {
        cout << "/";
        for (size_t i = 0; i < path.size(); ++i)
        {
            cout << path[i];
            if (i != path.size() - 1)
                cout << "/";
        }
        cout << "\n";
    }

    return 0;
}