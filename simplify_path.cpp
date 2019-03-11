#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> s;
		string ans = "";
		int start;
		int end;
		int len;
		int pos;
		/*
		We could use istringstream got stringstream, and a getline split by '/'
		istringstream ss(path);
        while(getline(ss, val, '/'))
		*/
		for (pos = 0; pos < path.size(); pos++) {
			if (path[pos] == '/') {
				continue;
			}
			start = pos;
			end = start;
			while (end < path.size() && path[end] != '/') {
				end++;
			}
			pos = end;
			len = end - start;
			string p = path.substr(start, len);//substr(start_pos, str_length);
			if (p == "..") {
				if(!s.empty())
					s.pop_back();
			}
			else if(p == "."){
			}
			else {
				s.push_back(p);
			}
		}
		for (int i = 0; i < s.size(); i++) {
			ans += '/';
			ans += s[i];
		}

		return ans.empty() ? "/" : ans;
	}
};

/*
int main() {
	string path = "/../";
	string ans = Solution().simplifyPath(path);

	cout << ans << endl;
	system("pause");
}	
*/