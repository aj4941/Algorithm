#include <bits/stdc++.h>
using namespace std;

struct Node {
    string head, number, tail, org;
    int num;
};

vector<Node> v;

bool cmp(Node &a, Node &b)
{
    string ahead = a.head, bhead = b.head;
    for (auto &to : ahead)
    {
        if ('A' <= to && to <= 'Z') 
            to = to - 'A' + 'a';
    }
    for (auto &to : bhead)
    {
        if ('A' <= to && to <= 'Z')
            to = to - 'A' + 'a';
    }
    if (ahead != bhead)
        return ahead < bhead;
    
    if (stoi(a.number) != stoi(b.number))
        return stoi(a.number) < stoi(b.number);
    
    return a.num < b.num;
}

Node newNode(string head, string number, string tail, string org, int num)
{
    Node node;
    node.head = head, node.number = number, node.tail = tail;
    node.org = org, node.num = num;
    return node;
}

Node calc(string s, int num)
{
    string head = "", number = "", tail = "";
    int idx = 0;
    
    while (!('0' <= s[idx] && s[idx] <= '9'))
        head += s[idx++];
    while ('0' <= s[idx] && s[idx] <= '9')
        number += s[idx++];
    
    tail = s.substr(idx);
    
    string org = head + number + tail;
    return newNode(head, number, tail, org, num);
}
vector<string> solution(vector<string> files) 
{
    for (int i = 0; i < files.size(); i++)
        v.push_back(calc(files[i], i));
    
    sort(v.begin(), v.end(), cmp);
    vector<string> ans;
    
    for (auto to : v)
        ans.push_back(to.org);
    
    return ans;
}