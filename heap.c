#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxheap 20

typedef struct heaptype{
	int heapsize;
	int heap[maxheap];
}heaptype;

void init(heaptype *h)
{
	h->heapsize = 0;
}

void insert_Max_heap(heaptype *h, int key)
{
	int i;
	i = ++(h->heapsize);
	
	while((i!=1) && (h->heap[i/2] < key))//�θ��庸�� Ŭ������ 
	{
		h->heap[i] = h->heap[i/2];
		i/=2;
	}
	h->heap[i] = key;
}

int delete_Max_heap(heaptype *h)//��������Ʈ�� �̱⶧���� ��������带 ���� 
{
	int deleted_item = h->heap[1];
	int temp = h->heap[(h->heapsize)--];
	int parent=1, child=2;
	while(child <= h->heapsize)
	{
		if((child < h->heapsize) &&(h->heap[child] < h->heap[child+1]))
			child++;
		if(temp >= h->heap[child]) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *=2;
	}
	h->heap[parent] = temp;
	return deleted_item; 
}

void insert_Min_heap(heaptype *h, int key)//�θ�� �� 
{
	int i;
	i = ++(h->heapsize);
	while((i!=1) && key < h->heap[i/2])
	{
		h->heap[i] = h->heap[i/2];
		i/=2; 
	}
	h->heap[i] = key;
}

int delete_Min_heap(heaptype *h)
{
	int temp=h->heap[(h->heapsize)--], item=h->heap[1];
	int parent=1, child=2;
	while(child <= h->heapsize)
	{//child ���� ��� �����ϹǷ� ��������� Ŀ���� �ݺ� ���� 
		if((child < h->heapsize) &&(h->heap[child] < h->heap[child+1]))
			child++;
		if(temp <= h->heap[child]) break;
		parent = child;
		child *=2;
	}
	return item;
}

void print_arr(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("<%d>",arr[i]);
	}
	printf("\n"); 
}

void heap_sort_max(int arr[], int n)
{
	printf("Max heap sorting\n");
	int i;
	heaptype h;
	init(&h);
	for(i=0; i<n; i++)
	{
		insert_Max_heap(&h,arr[i]);
	}
	
	for(i=0; i<n; i++)
	{
		arr[i]=delete_Max_heap(&h);
	}
	
	print_arr(arr,n);
}

void heap_sort_min(int arr[], int n)
{
	printf("Min heap sorting\n");
	int i;
	heaptype h;
	init(&h);
	for(i=0; i<n; i++)
	{
		insert_Min_heap(&h,arr[i]);
	}
	
	for(i=0; i<n; i++)
	{
		arr[i]=delete_Min_heap(&h);
	}
	print_arr(arr,n);
}
void test()
{
	int size=15;
	srand(time(NULL));
	int arr[size],i;
	for(i=0; i<size; i++)
	 arr[i] = rand()%100;
	 
	heap_sort_max(arr,size);
	heap_sort_min(arr,size);
}

int main()
{
		printf("heap sort test\n");
		test();
}
