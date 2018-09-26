/*
Given a string, find the length of the longest substring without repeating characters.
*/

#include<iostream>
#include<string>
#include<cassert>
using namespace std ;

class Solution {
public:
    /*solution1: computational complexity is  O(n^2) */
    int lengthOfLongestSubstring(string s) {
        int len = s.length() ;
        char const* ps = s.c_str() ;
        int table[256] ;
        int max_s = 0 ;
        int max_tmp = 0 ;

        if(len == 0)
            return 0 ;


        for(int i=0;i<len;i++)
        {
            for(int j=0;j<256;j++)
                table[j] = 0 ;

            for(int j=i;j<len;j++)
            {
                table[ps[j]]++ ;
                if(table[ps[j]] > 1)
                    break ;
                max_tmp++ ;
            }

            if(max_tmp > max_s)
            {
                max_s = max_tmp ;
            }
            max_tmp = 0 ;
        }
        return max_s ;
    }
};

/* 
solution2: computational complexity is O(n) ;
*/
int lengthOfLongestSubstring(string s) {
        int table[256] ;
        int head  = 0 ;
        int max_s = 0 ;
        for(int i = 0;i < 256; i++)
            table[i] = -1 ;

        for(int i=0;i<s.length();i++)
        {
            if(table[s[i]] > -1)
            {
                head = max(head, table[s[i]]+1) ;           //the key to understand this algorithm is to understand this line well.
            }
            max_s = max(max_s , i - head + 1) ;
            table[s[i]] = i ;
        }

        return max_s ;
    }
} ;

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().lengthOfLongestSubstring(s);

        //string out = to_string(ret);
        cout << ret << endl;
    }
    return 0;
}
