/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 *
 * https://leetcode.com/problems/shortest-completing-word/description/
 *
 * algorithms
 * Easy (55.01%)
 * Likes:    135
 * Dislikes: 475
 * Total Accepted:    23.3K
 * Total Submissions: 42.3K
 * Testcase Example:  '"1s3 PSt"\n["step","steps","stripe","stepple"]'
 *
 * 
 * Find the minimum length word from a given dictionary words, which has all
 * the letters from the string licensePlate.  Such a word is said to complete
 * the given string licensePlate
 * 
 * Here, for letters we ignore case.  For example, "P" on the licensePlate
 * still matches "p" on the word.
 * 
 * It is guaranteed an answer exists.  If there are multiple answers, return
 * the one that occurs first in the array.
 * 
 * The license plate might have the same letter occurring multiple times.  For
 * example, given a licensePlate of "PP", the word "pair" does not complete the
 * licensePlate, but the word "supper" does.
 * 
 * 
 * Example 1:
 * 
 * Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe",
 * "stepple"]
 * Output: "steps"
 * Explanation: The smallest length word that contains the letters "S", "P",
 * "S", and "T".
 * Note that the answer is not "step", because the letter "s" must occur in the
 * word twice.
 * Also note that we ignored case for the purposes of comparing whether a
 * letter exists in the word.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
 * Output: "pest"
 * Explanation: There are 3 smallest length words that contains the letters
 * "s".
 * We return the one that occurred first.
 * 
 * 
 * 
 * Note:
 * 
 * licensePlate will be a string with length in range [1, 7].
 * licensePlate will contain digits, spaces, or letters (uppercase or
 * lowercase).
 * words will have a length in the range [10, 1000].
 * Every words[i] will consist of lowercase letters, and have length in range
 * [1, 15].
 * 
 * 
 */
class Solution {
public:
    //Use prime num for exisit.
    int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101}; 

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        //primes.
        long long l_p = get_product(licensePlate);
        cout<<l_p<<endl;
        // unsigned int length=INT_MAX;
        string ans(20, 'a');//make it size big enough.
        for(auto w:words)
        {
            cout<<get_product(w)%l_p <<endl;
            if(w.size()<ans.size() && get_product(w)%l_p == 0)//==0 means only have this chars.
            {
                ans = w;
            }
        }

        return ans;
    }

    long long get_product(string s)
    {
        long long product = 1;
        for(auto c : s)
        {
            if(c<='Z' && c>='A')
                c += 32;
            if(c>='a' && c<='z')
            {
                product*=primes[c-'a'];
                cout<<primes[c-'a']<<endl;
            }
        }

        return product;
    }
};

