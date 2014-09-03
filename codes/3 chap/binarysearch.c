
/*BINARY SARCH*/
#include<stdio.h>
int binsearch(int x,int v[],int n)
{
	int low=0,high,mid;
	high =n-1;
	mid=(low+high)/2;
	while(low<=high&&x!=v[mid]){
		if(x<v[mid])
			high=mid-1;
		else
		     low=mid+1;
		mid=(low+high)/2;
	}
	if(x==v[mid])
		return mid+1;
	else
		return -1;
}

main()
{
	int x,n,i;
	printf("x=");
	scanf("%d",&x);
	printf("n=");
	scanf("%d",&n);
        int v[n];
	printf("enter elememts in array");
	for(i=0;i<n;++i){
		scanf("%d",&v[i]);
	}
	printf("%d",binsearch(x,v,n));
}
