#include <vector>
#include <iostream>
#include <assert.h>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Heap
{
public:
    Heap(){}
    Heap(const vector<int> &a):v(a){
        make_heap();
    }
    int top(){
        assert(v.size() > 0);
        return v[0];
    }
    void pop(){
        assert(v.size() > 0);
        v[0] = v.back();
        percolate_down(0);
        v.resize(v.size()-1);
    }
    void insert(int x) {
        v.push_back(x);
        percolate_up(v.size()-1);
    }
    bool empty() {
        return v.size()==0;
    }
private:
    void make_heap()
    {
        for (int i=v.size()/2-1; i>=0; i--)
            percolate_down(i);
    }
    void percolate_up(int id) {
        int x = v[id];
        for (;id>0&&v[(id-1)/2]<x;id=(id-1)/2)
            v[id] = v[(id-1)/2];
        v[id] = x;
    }
    void percolate_down(int id) {
        int x = id;
        int child;
        for (; id*2+1<v.size();id=child) {
            child = id*2+1;
            if (child+1<v.size()&&v[child]<v[child+1])
                child++;
            if (x > v[child]) break;
            else v[id] = v[child];
        }
        v[id] = x;
    }
    vector<int> v;
};

void test_make_heap()
{
    vector<int> v;
    for (int i=0; i<10007; i++)
        v.push_back(rand());
    Heap hp(v);
    v.clear();

    while (!hp.empty()) {
        v.push_back(hp.top());
        hp.pop();
    }
    for (int i=0; i<v.size(); i++)
        printf("%d%c", v[i], i%35==34||i==v.size()-1?'\n':' ');
    bool flag=true;
    for (int i=1; i<v.size(); i++) {
        if (v[i] > v[i-1]) {
            flag = false;
            cout << "Wrong index: " << v[i-1] << " " << v[i] << endl;
        }
    }
    printf("%s\n", flag?"Succeed":"Fail");
}

int main()
{
    //test_make_heap();
    Heap hp;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string type;
        cin >> type;
        if (type == "A") {
            int x;
            cin >> x;
            hp.insert(x);
        }
        else {
            cout << hp.top() << endl;
            hp.pop();
        }
    }
    return 0;
}