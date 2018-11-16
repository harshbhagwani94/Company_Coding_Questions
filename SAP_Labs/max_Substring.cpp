#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string str;
	    cin>>str;
	    int minLength , maxLength, maxUnique;
	    unordered_map<string , int> mp;
	    cin>>minLength>>maxLength>>maxUnique;
	    for(int i=minLength; i<=maxLength; i++)
	    {
	    	int start= 0;
	    	for(int j = 0; j<=((int)str.length() - i); j++)
	    	{
		    	string temp = str.substr(j, i);
		    	string sortedString = temp;
		    	sort(sortedString.begin(), sortedString.end());
		    	if(unique(sortedString.begin(), sortedString.end())- sortedString.begin() <=  maxUnique)
		    		mp[temp]++;
	    		
	    	}
	    }

	    int maxCount = mp.begin()->second;
	    for(auto &kv : mp)
	    {
	    	maxCount = max(maxCount, kv.second);
	    }
	    cout<<maxCount<<endl;
	}
	return 0;
}
