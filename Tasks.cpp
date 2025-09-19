#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
//Task1
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {
            if ((c == ')' && (!st.empty() && st.top() == '('))
                || (c == ']' && (!st.empty() && st.top() == '['))
                || (c == '}' && (!st.empty() && st.top() == '{'))) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}

//Task2
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, curr = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[i]) {
            nums1[curr--] = nums1[i--];
        }
        else {
            nums1[curr--] = nums2[j--];
        }
    }
}

//Task3
int maxProfit(vector<int>& prices) {
    int l = 0, r = 1, maxi = 0;
    while (r < prices.size()) {
        if (prices[l] < prices[r]) {
            int profit = prices[r] - prices[l];
            maxi = max(maxi, profit);
        }
        else {
            l = r;
        }
        r++;
    }
    return maxi;
}


//Task4
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    unordered_map<char, int> m;
    for (char c : s) {
        m[c] = 1 + m[c];
    }
    for (char c : t) {
        m[c]--;
    }
    for (pair<char, int> p : m) {
        if (p.second != 0) {
            return false;
        }
    }
    return true;
}

//Task5
class RecentCounter {
    queue<int> q;
public:
    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return (int)q.size();
    }
};
