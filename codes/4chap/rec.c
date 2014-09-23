#include<stdio.h>
void qsort(int  v[],int left,int right);
main()
{
	int v[100]={0,9,4,7,1},m=0,n=3;
	qsort(v,m,n);	
}
void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);
	if (left >= right) /* do nothing if array contains */
		return;
/* fewer than two elements */
	swap(v, left, (left + right)/2); /* move partition elem */
		last = left;
printf("%d\t%d\t%d\t%d\n%d\t%d\n",v[0],v[1],v[2],v[3],left,right);
/* to v[0] */
	for (i = left + 1; i <= right; i++) /* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);
printf("%d\t%d\t%d\t%d\n",v[0],v[1],v[2],v[3]);
	swap(v, left, last);
printf("%d\t%d\t%d\t%d\n",v[0],v[1],v[2],v[3]);
	qsort(v, left, last-1);
printf("%d\t%d\t%d\t%d\n",v[0],v[1],v[2],v[3]);
	qsort(v, last+1, right);
printf("%d\t%d\t%d\t%d\n",v[0],v[1],v[2],v[3]);
}
/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
int temp;
temp = v[i];
v[i] = v[j];
v[j] = temp;
}
