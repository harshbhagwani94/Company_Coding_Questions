#include<bits/stdc++.h>
using namespace std;
/*


K caterpillars are eating their way through N leaves. 
Each caterpillar falls from leaf to leaf in a unique sequence.
All caterpillars start at a twig in position 0 and fall onto the leaves at positions between 1 and N. 
Each caterpillar i has an associated ‘jump-number’ A . 
A caterpillar with jump number j eats leaves at positions that are multiples of j. 
It will proceed in the order j, 2j, 3j, … till it reaches the end of the leaves, 
then it stops and builds its cocoon.

Given a set A of K elements, K ≤ 15, N ≤ 10 , we need to determine the number of uneaten leaves.
Input Format:
N = number of leaves
K = number of caterpillars
A = Array of integer jump numbers (one per line).
Output Format:

An integer denoting the number of uneaten leaves.

Sample Input:

10

3

2

4

5

Sample Output:

4

Explanation

[2,4,5] is the 3-member set of jump numbers. All leaves which are multiples of 2, 4, and 5 are eaten. Leaves 1,3,7,9 are left, and they number 4.

*/

int findGCD(int num1, int num2)
{
    if(num2==0)
        return num1;
    return findGCD(num2, num1%num2);
}

int lcm(int a, int b)
{
    return a*(b/findGCD(a,b));
}

int main()
{
    int lvs, cp;
    cin>>lvs>>cp;
    int bLvs = lvs;
    int N = lvs;
    vector<int> jmps(cp,0);
    for(int i=0;i<cp;i++)    
    {
        cin>>jmps[i];
        int gcd = jmps[i];
        for(int j=0; j<=i && bLvs>0; j++)
        {
            gcd = findGCD(jmps[j], jmps[i]);   
            if(gcd > 1 && gcd< jmps[i])
                break;
        }
        if(gcd==jmps[i])    
        {
            bLvs = bLvs - (N/jmps[i]);
            set<int> commonMultiples;
            for(int j=0;j<i;j++)
            {
                int lc = lcm(jmps[j], jmps[i]);
                int lc1 = lc;
                while(lc<=N)
                {
                    commonMultiples.insert(lc);
                    lc+=lc1;
                }
            }
            bLvs+=commonMultiples.size();
        }
    }
    cout<<bLvs<<endl;
    return 0;
}
