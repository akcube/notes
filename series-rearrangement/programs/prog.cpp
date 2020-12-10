#include<bits/stdc++.h>

using namespace std;

long double eval_term(int n){
	long double val = (long double)1/n;
	if(!(n&1))
		val *= -1;
	return val;
}

int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	long double res = 0;
	int count = 0;
	for(int i=1; i<=n; i++, count++){
		res += eval_term(i);
		if(count==3){
			printf("%0.50Lf\n", res);
			count=0;
		}
	}
	return 0;
}