#include<stdio.h>
#include<math.h>

int ucln(int a, int b){
	if(b==0)
	   return a;
	else 
	       return ucln(b, a%b);
}

int bcnn(int a, int b){
	return (a*b)/ucln(a, b);
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int i,j;
	for(i=a; i<=b ;i++){
		for(j=i+1 ; j<=b ; j++){
			if(ucln(i, j)==1)
			   printf("(%d,%d)\n", i, j);
		}
	}

}
