/*You are given a string of length N.
The string consists of lowercase english alphabets only i.e. a to z.
You are also given an integer K. You need the find the Kth most frequent alphabet 
in the string. 
If more than one alphabet share the Kth frequency, 
you need to find the lexicographically smallest alphabet among them. 
In case no Kth most popular alphabet exists, you need to write "NONE" (without the inverted commas).

Input Format:
The first line contains T
1≤ T ≤100, the number of test cases in the input.
This is follwed by T test cases, each test case containing 2 lines. 
The first line of each test case contains the values N, 1≤N≤1E5 and K, 1≤K≤N for the test case, 
and the second line contains the string.

Output Format:
For each test case, output the required answer for the string in the test case.

Sample Input:
4
6 3
aaabbc
5 1
aaabb
8 3
aaabbbcc
5 2
aabcd

Sample Output:
c
a
NONE
b

Explanation:
In the first test case, the frequencies are: a-3, b-2, c-1. Therefore, the 3rd most frequent 
alphabet is 'c'.
In the third test case, both 'a' and 'b' have the highest frequency of 3, and 'c' has the second 
highest frequency of 2. Since there exists no alphabet with 3rd highest frequency, 
the answer is 'NONE'.
In the fourth test case, 'b', 'c' and 'd' have the second highest frequency of 1. 
Therefore, we report the lexicographically smallest of them i.e. 'b'.
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        string str;
        cin>>k>>k>>str;
        int c[26]={};
        for(char ch : str)
            c[ch-'a']++;
        map<int, set<char>> mp;
        for(int i=0; i<26; i++)
            if(c[i])
                mp[-c[i]].insert('a'+i);
        
        int fl =0;
        for(auto m :mp)
        {
            if(!--k)
            {
                cout<<*m.second.begin()<<'\n';
                fl = 1;
                break;
            }
        }
        if(fl==0)
            cout<<"NONE\n";
    }
    return 0;
}
