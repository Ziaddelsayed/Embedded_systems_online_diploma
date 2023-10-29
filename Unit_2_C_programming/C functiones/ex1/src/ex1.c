
#include <stdio.h>
#include <stdlib.h>

int Check_prime(int num){
	int j,prime=1;
	for(j=2;j<num;j++)
	{
		if(num%j==0)
		{
			prime=0;
			break;
		}
	}
	return prime;
}

int main(void) {
	int start, end, prime,i;
	printf("Enter two numbers(intervals) ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&start,&end);
	printf(" prime numbers between %d & %d is:\n ",start,end);
	for(i=start;i<=end;i++)
	{
		prime= Check_prime(i);

		if(prime)
		{
			printf("  %d \t",i);
		}
	}
	return 0;
}

