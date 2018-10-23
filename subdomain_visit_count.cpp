#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		vector<string> ans_vec;
		//unordered_map is faster than map;
		unordered_map<string, int> map;
		for (auto cpdomain : cpdomains) {
			int pos = cpdomain.find(' ');
			int num = stoi(cpdomain.substr(0, pos));
			string domain = cpdomain.substr(pos+1, -1);
			map[domain] += num;
			//string.find will find the no.1 '.''s position.
			while (domain.find('.') != string::npos) {
				map[domain.substr(domain.find('.') + 1, -1)] += num;
				domain = domain.substr(domain.find('.') + 1, -1);
			}
		}

		auto it = map.begin();
		while (it != map.end()) {
			//to_string() int->string
			ans_vec.push_back(to_string(it->second) + ' ' + it->first);//Traversal a map
			it++;
		}

		return ans_vec;

	}
};

int main() {
	Solution sol = Solution();
	vector<string> vec{ "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
	sol.subdomainVisits(vec);
	//cout << << endl;

	system("pause");
	return 0;
}