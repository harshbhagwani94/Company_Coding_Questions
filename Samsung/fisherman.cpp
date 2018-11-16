#include <iostream>
#include <climits>
/*#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <stack>
#include <queue>*/

using namespace std;

int findSum(int arr[], int N)
{
	int sum=0;
	for(int i=0;i<N;i++)
		sum+=arr[i];
	return sum;
}


int findMinimum(int index, int persons[], int pos[], int L, int  R) {
	if(index==3) return 0;
	
	int val=INT_MAX, tot=0;

		for(int i=L; i<=R-persons[index]+1; i++) {
		// i ... i + persons[index] - 1
		int sum=0;
		
		for(int j=i; j<i+persons[index]; j++)
			sum += (j<=pos[index])?(pos[index]-j+1):(j-pos[index]+1);
		
		int num = findMinimum(index+1, persons, pos, i+persons[index], R);
		if(num==INT_MAX)
			continue;
		else
			val = min(val, sum+num);
	}
	return val;
}

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int N,num, r;
	    cin>>N;
	    int pos[3], persons[3];
	    for(int i=0;i<3;i++)	
		cin>>pos[i]>>persons[i];
		//int arr[N]={};
	    cout<<findMinimum(0, persons, pos, 1, N);

	}
	return 0;
}