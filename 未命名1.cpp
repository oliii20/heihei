#include <stdio.h>
int main()
{
	int N,x=1,i=1;
	scanf("%d",&N);
	for(i=1;i<=N-1;i++){
		x=2*(x+1);
	}
	printf("%d",x);
	return 0;
}
