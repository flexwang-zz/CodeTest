#include <string>
#include <iostream>
#include <stack>

using namespace std;

const int max_n = 'z'+1;
char graph[max_n];
bool used[max_n];
int  n;
int  indegree[max_n];

void build_graph(const string &str) {
    used[str[0]] = true;
    for (int i=0; i+1<str.length(); ++i) {
        char next = str[i+1];
        graph[str[i]] = next;
        indegree[next] = 1;
    }    
}

int main()
{   
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        build_graph(str);
    }
    stack<char> st;
    for (char i='a'; i<='z'; ++i) 
        if (!indegree[i] && used[i]) st.push(i);
    while (!st.empty()) {
        char p = st.top();
        st.pop();
        cout << p;
        if (graph[p]) st.push(graph[p]);
    }
    return 0;
}