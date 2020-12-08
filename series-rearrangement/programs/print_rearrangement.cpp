#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

long double eval_term(int n){
	long double val = (long double)1/n;
	if(!(n&1))
		val *= -1;
	return val;
}

int main(int argc, char *argv[]){

	if(argc != 4){
		printf("Incorrect usage. Usage: ./print_rearrangement [Real Number K] [Number of groups of +ve/-ve terms to iterate through] [Delay in ms]\n");
		return 1;
	}
	system("clear");
	int lim = atoi(argv[2]), time = atoi(argv[3]);
	long double num = stold(argv[1]), res = 0;
	bool flag = false, flag2 = false;

	int count = 0, count2 = 0;
	for(int p=1, n=2, c=0; c < lim;count++, count2++){
		if(count2==16){
			printf("\n");
			count2=0;
		}
		if(res <= num){
			if(!flag)
			{
				flag = true;
				flag2 = false;
				c++;
			}	
			res += eval_term(p);
			printf(" + 1/%-7d", p);
			fflush(stdout);
			p+=2;
		}
		else{
			if(!flag2)
			{
				flag = false;
				flag2 = true;
				c++;
			}
			res += eval_term(n);
			printf(" - 1/%-7d", n);
			fflush(stdout);
			n+=2;
		}
		/*if(count==3){
			printf("%0.50Lf\n", res);
			count=0;
		}*/
		usleep(time);
	}

	printf("\n\n Sum: %0.15Lf\n", res);
	return 0;
}