#include <iostream>
using namespace std;
/*
����λ����������������
˼·1���鲢���������Ӷ�ΪO(m+n)����������Ŀ��˼�����Ǿ�Ȼ���ˡ����� Ϲ�˹��ۡ��� 
˼·2��
*/
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    int i, j, k;
    int *array = new int[m+n];
    i = 0;
    j = 0;
    k = 0;
    double ret;
    while (i < m && j< n)
    {
        if(A[i] <= B[j])
        {
            array[k++] = A[i++];
        }
        else
        {
            array[k++] = B[j++];
        }
    }
    while (i < m)
    {
        array[k++] = A[i++];
    }
    while (j < n)
    {
        array[k++] = B[j++];
    }
    for (i=0;i<m+n;i++)
        cout << array[i] << "  ";
    cout << endl;
    if ((m+n)%2 == 0)
    {
        ret = 1.0*(array[(m+n)/2 - 1] + array[(m+n)/2])/2;
    }
    else
    {
        ret = array[(m+n)/2];
    }
    delete[] array;
    return ret;
}
/*��Ŀ��˼��Ҫ�ҳ���λ�����临�Ӷ�Ҫ��O(log(m+n))
����m+nΪż������Ҫ�ҵ���С�ĵ� ��m+n��/2 -1 �� ��m+n��/2���������� ��
����m+nΪ��������Ҫ�ҵ���С�ĵ� ��m+n��/2 ����� 
˼·��ֱ�ӽ���������ϲ���Ȼ����ÿ��ŵ�partition�����֣��ҵ���Ҫ���Ǹ�Ԫ�ػ���������Ԫ�� 
*/ 
int partition(int a[], int left , int right)
{
    int middle = left;
    int pivot = a[right]; 
    //cout << a[right] << endl;
    for (int i = left ; i < right; i++)
    {
    	if (a[i] < pivot)
    	{
    		if (middle != i)
    		{
    			int temp = a[i];
    			a[i] = a[middle];
    			a[middle] = temp;
    		}
    		middle++;
    	}
    	
    }
    int temp = a[right];
    a[right] = a[middle];
    a[middle] = temp;
    
    return middle;
} 

double getK(int a[], int left, int right, int k)
{
	if (left >= right)
	{
		return a[left];
	}
	int middle = partition(a, left, right);
	cout << middle << endl;
	if (middle == k-1)
	{
		return a[middle];
	}
	else if (middle > k-1)
	{
		return getK(a, left, middle-1, k);  //����Ĳ���ʲô�еݹ飡���� ��Ĳ�Ҫ��ѭ������ˣ������� 
	}
	else //middle < k-1
	{
		return getK(a, middle+1, right, k-1-middle);
	}
		
}

void QuickSort(int a[],int p,int r){
    if (p<r){
        int q=partition(a,p,r);
        QuickSort(a,p,q-1);
        QuickSort(a,q+1,r);
    }
}

double findMedianSortedArrays2(int A[], int m, int B[], int n)
{
	double ret = 0.0;
	int* a = new int[m+n];
	for (int i = 0; i < m; i++)
	{
		a[i] = A[i];
	}
	for (int i =0; i < n; i++)
	{
		a[i+m] = B[i];
	}
	/*
	QuickSort(a, 0, m+n-1);
    for (int i = 0; i < m+n; i++)
    	cout << a[i] << "  ";
	cout << endl;
	*/
	if ((m+n)%2 == 0)
	{
		ret += getK( a, 0, m+n-1, (m+n)/2 );
		ret += getK( a, 0, m+n-1, (m+n)/2+1 );
		ret = ret*1.0/2;
	}
	else
	{
		ret = getK( a, 0, m+n-1, (m+n)/2+1 );
	}
	
	delete[] a;

	return ret;
}

int main()
{
    int A[] = {2,3,4,5};
    int B[] = {1};
    //double ret = findMedianSortedArrays(A, 5, B, 4);
    
    double ret = findMedianSortedArrays2(A, 4, B, 1);
    cout << endl;
    cout << ret << endl;
 
    return 0;
}
