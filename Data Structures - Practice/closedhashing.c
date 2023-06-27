#include <stdio.h>
int size;
int hasht(int key){
	int i ;
	i = key % size ;
	return i;
}
int linear(int key){
	int i ;
	i = (key+1) % size ;
	return i ;
}
int quad(int key, int j){
 	int i ;
 	i = (key+(j*j)) % size ;
 	return i ;
}
int main(){
    int key,a[20],hash[20],i,n,op,j,k ;
    printf ("Enter the size of the hash table:  ");
    scanf ("%d",&size);
	printf ("\nEnter the number of elements: ");
    scanf ("%d",&n);
	printf ("Enter Elements: ");
    for (i=0;i<n;i++)
 		scanf("%d",&a[i]);
	do{
		printf("\n\n1.Linear Probing\n2.Quadratic Probing \n3.Exit \nEnter your option: ");
		scanf("%d",&op);
		switch(op){
			case 1:
			for (i=0;i<size;i++)
				hash[i]=-1 ;
			for(k=0;k<n;k++){
			  	key=a[k] ;
			  	i = hasht(key);
			  	while (hash[i]!=-1)
			      	i = linear(i);
			  	hash[i]=key ;
			}
			printf("\nThe elements in the array are: ");
			for (i=0;i<size;i++)
			  	printf("\n  Element at position %d: %d",i,hash[i]);
			break ;
			case 2:
			for (i=0;i<size;i++)
			  	hash[i]=-1 ;
			for(k=0;k<n;k++){
				j=1;
				key=a[k] ;
				i = hasht(key);
				while (hash[i]!=-1){
				    i = quad(i,j);
				    j++ ;
				}
				hash[i]=key ;
			}
			printf("\nThe elements in the array are: ");
			for (i=0;i<size;i++)
			  	printf("\n Element at position %d: %d",i,hash[i]);
			break ;
		}
    }while(op!=3);
}
