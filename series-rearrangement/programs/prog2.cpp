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
	int lim = atoi(argv[2]);
	long double num = stold(argv[1]);
	long double res = 0;
	bool flag = false, flag2 = false;

	int count = 0;
	for(int p=1, n=2, c=0; c < lim;count++){
		if(res <= num){
			if(!flag)
			{
				flag = true;
				flag2 = false;
				c++;
			}	
			res += eval_term(p);
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
			n+=2;
		}
		if(count==3){
			printf("%0.50Lf\n", res);
			count=0;
		}
		//sleep(1);
	}

	printf("%0.15Lf\n", res);
	return 0;
}