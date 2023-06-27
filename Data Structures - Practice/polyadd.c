#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[10],b[10],c[10],i,m,n,count=0;
	printf("Enter the highest degree of first polynomial:");
	scanf("%d",&m);
	for(i=m;i>=0;i--){
		printf("Enter the coefficient of x^%d :",i);
		scanf("%d",&a[i]);
	}
	printf("Enter the highest degree of second polynomial:");
	scanf("%d",&n);
	for(i=n;i>=0;i--){
		printf("Enter the coefficient of x^%d :",i);
		scanf("%d",&b[i]);
	}
	printf("Addition of two polynomials\n");
	if(m>n){
		for(i=m;i>=0;i--){
			c[i]=a[i]+b[i];
			count++;
		}
	}
	else{
		for(i=n;i>=0;i--){
			c[i]=a[i]+b[i];
			count++;
		}
	}
	printf("The Resultant polynomial is\n");
	for(i=count-1;i>0;i--)
		printf("%dx^%d+",c[i],i);
	printf("%d",c[i]);
	printf("\nMultiplication of two polynomials\n");
	//int i,count=0;
	int j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			c[i+j]+=a[i]*b[j];
		}
		count++;
	}
	printf("The Resultant polynomial is\n");
	for(i=count-1;i>0;i--)
		printf("%dx^%d+",c[i],i);
	printf("%d",c[i]);
}
