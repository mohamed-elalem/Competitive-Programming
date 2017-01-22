#include <iostream>
#include <stack>

using namespace std;

int t;
string expr;

int main() {
  
  cin >> t;
  while(t--) {
    cin >> expr;
    stack<char> st;
    for(int i = 0; i < expr.size(); i++) {
      if(expr[i] == ')') {
	while(st.top() != '(') {
	  cout << st.top();
	  st.pop();
	}
	st.pop();
      }
      else if(expr[i] == '(' || expr[i] == '*' || expr[i] == '+' || expr[i] == '-' || expr[i] == '/' || expr[i] == '^') {
	st.push(expr[i]);
      }
      else {
	cout << expr[i];
      }
    }
    cout << endl;
  }
}
