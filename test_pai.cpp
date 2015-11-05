#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LENGTH (8)

void swap(int *a , int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

class heap
{
public:
	heap(int *p, int len):
		m_array(NULL), m_len(len), m_max(m_len * 2)
	{
		m_array = new int[m_max];	
		memcpy(m_array, p, sizeof(int) * len);
		build();
	}
	heap(const heap& src):
		m_len(src.m_len), m_max(src.m_max)
	{
		m_array = new int[m_max];
		memcpy(m_array,src.m_array,m_len * sizeof(int)); 
		build();
	}
	heap& operator=(const heap& src)
	{
		m_len = src.m_len;
		m_max = src.m_max;
		m_array = new int[m_max];
		memcpy(m_array, src.m_array, m_len * sizeof(int));
		build();
		return *this;
	}

	virtual ~heap()
	{
		delete[] m_array;
	}

	//删除堆中第一个元素
	void delete_heap_head()
	{
	}

	void print()
	{
		int i = 0;
		cout<<"Heap:";
		for(; i < m_len; i++)
			printf("%d ", m_array[i]);
		cout<<endl;
	}
private:

	void build()
	{
		int i = m_len - 1;
		for(; i > 0; i--)
		{
			int son = i;
			int parent = (son - 1)/2;
			while(son > 0 && parent >= 0)
			{
				if(m_array[son] < m_array[parent])
					swap(&m_array[son], &m_array[parent]);
				son = parent;
				parent = (son - 1)/2;
			}
		}
	}
	int* m_array;
	int m_len;
	int m_max;
};



int main()
{
	int array[LENGTH] = {5,6,3,1,4,2,8,7};
	heap test_heap(array, LENGTH);
	test_heap.print();
	
}
