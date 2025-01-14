#include<iostream>
#include<cmath>
using namespace std;
int solution(int testCase)
{
    int answer=0;
  int to=ceil((-1+sqrt(1+8*testCase))/2);
    for(int i=1;i<=to;i++)
  {
    if(i%2==1&&testCase%i==0)
    {
      answer++; 
    }
    else if(i%2==0&&(testCase%i)==(i/2))
    {
      answer++;
    }
  }

    return answer;
}
