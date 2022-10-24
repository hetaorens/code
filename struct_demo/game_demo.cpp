#include <iostream>
#include <unordered_map>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0)
    {
        this->x=x;
        this->y=y;
    }
    void displayPoint() 
    {
    cout << "(" << this->x << "," 
         << this->y << ")" << endl;
    }
};

class Solution {
public:
    struct pair_hash {
        inline size_t operator()(const pair<int,int>&p)const{
            return (((unsigned)p.first<<17)+p.second);
        }
    };

    unordered_map<pair<int,int>,int,pair_hash>josephus;
    int lastRemaining(int n, int m) {
        auto state=make_pair(n,m);
        if(josephus[state])return josephus[state];
        return josephus[state]=(n?(lastRemaining(n-1,m)+m)%n:1);
    }
};
int main()
{
    Point p = 1;
    p.displayPoint();
    Solution s;
    cout<<s.lastRemaining(10,1);
}