#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> ans_vec;
		vector<vector<int>> pos_code_vec_pattern;
		vector<vector<int>> pos_code_vec_word;
		vector<int> pos_code;
		map<char, int> char_vector_map;//char c, int vector_no
		set<char> char_set;
		pos_code_vec_pattern = wordCode(pattern);
		
		for (int i = 0; i<words.size(); i++) {
			//cout << wordCode(words[i])->size() << endl;
			int flag = 1;
			pos_code_vec_word = wordCode(words[i]);
			for (int j = 0; j < min(pos_code_vec_pattern.size(),pos_code_vec_word.size())&&flag==1; j++) {
				if (pos_code_vec_pattern.size() != pos_code_vec_word.size()) {
					flag = 0;
					continue;
				}
				for (int k = 0; k < pos_code_vec_pattern[j].size(); k++) {
					if (pos_code_vec_word[j][k]!= pos_code_vec_pattern[j][k]) {
						flag = 0;
					}
				}
					
			}
			if (flag == 0) {
				flag = 1;
			}
			else {
				ans_vec.push_back(words[i]);
			}
				
		}
		
		return ans_vec;
	}

	vector<vector<int>> wordCode(string& word) {
		//cout << word<<endl;
		vector<vector<int>> pos_code_vec;
		vector<int> pos_code;
		map<char, int> char_vector_map;//char c, int vector_no
		set<char> char_set = {};
		int vector_no = 0;
		for (int j = 0; j < word.size(); j++) {
			//search in set
			if (char_set.find(word[j]) == char_set.end()) {
				char_set.insert(word[j]);
				char_vector_map[word[j]] = vector_no;
				pos_code.push_back(j);
				pos_code_vec.push_back(pos_code);
				pos_code.clear();
				vector_no++;
			}
			else {
				pos_code_vec[char_vector_map[word[j]]].push_back(j);
				//cout << pos_code_array[char_vector_map[word[j]]].size() << ' ' << j << endl;
			}

		}

		return pos_code_vec;

	}

};

int main() {
	Solution sol = Solution();
	//string s = "abc";
	//sol.wordCode(s);
	string str[] = { "abc","deq","mee","aqq","ccc" };
	vector<string> vec(str, str + sizeof(str) / sizeof(str[0]));
	vector<string> vec_ = sol.findAndReplacePattern(vec, "abb");
	for (int i = 0; i<vec_.size(); i++) {
		cout << vec_.at(i) << endl;
	}

	system("pause");
	return 0;
}