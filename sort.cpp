
#include"stdio.h"

//��������
void InsertSort(int A[],int n);
void InsertSort_SplitHalf(int A[],int n);
void ShellSort(int A[],int n);

//��������
void BubbleSort(int A[],int n);
void QuickSort(int A[],int low,int high);

//ѡ������
void SelectSort(int A[],int n);
void HeapSort(int A[],int len);

//�鲢����
void MergSort(int A[],int low,int high);
int main()
{
    int test[11];
    test[0]=0;

    for(int i=1;i<11;++i)
        scanf("%d",&test[i]);

    //InsertSort(test,10);
    //InsertSort_SplitHalf(test,10);
    //ShellSort(test,10);
    //BubbleSort(test,11);
    //QuickSort(test,0,10);
    //SelectSort(test,11);
    //HeapSort(test,11);
    MergSort(test,0,10);
    for(int j=0;j<11;++j)
        printf("%d ",test[j]);

    printf("\n");

    return 0;
}

/**
�ڱ�����˵���������ڱ���Ŀ���ǿ���ʹ����forѭ���ڲ���ȥ�ж������Ƿ��Խ�磬
���Ա��ⲻ��Ҫ���ж���䡣
**/
//ֱ�Ӳ�������
void InsertSort(int A[],int n){
   int i,j;
   for(i=2;i<=n;++i)               //���ν�A[2]-A[n]���뵽ǰ������������
    {
      if(A[i]<A[i-1]){             //��A[i]С��A[i-1],����Ҫ��A[i]���뵽ǰ�����ź�����������
        A[0]=A[i];                //����Ϊ�ڱ���A[0]�����Ԫ��
        for(j=i-1;A[0]<A[j];--j)  //�Ӻ���ǰ���Ҵ�����λ�ã��ڱ����ӣ�
        {
            A[j+1]=A[j];
        }
        A[j+1]=A[0];              //���Ƶ�����λ��
      }

    }
}
//�۰��������
void InsertSort_SplitHalf(int A[],int n){

    int i,j,low,high,mid;

    for(i=2;i<=n;++i){

        A[0]=A[i];
        low=1;
        high=i-1;

        while(low<=high){
            mid=(low+high)/2;
            if(A[mid]>A[0])
              high=mid-1;
            else
              low=mid+1;
        }

        for(j=i-1;j>=high+1;--j)
           A[j+1]=A[j];
        A[high+1]=A[0];        //�����λ��Ϊhigh+1

    }
}
//ϣ������
void ShellSort(int A[],int n){
  //��˳�����ϣ���������򣬱��㷨��ֱ�Ӳ���������ȣ�����һ���޸ģ�
  //1��ǰ���¼λ�õ�������dk������1
  //2��A[0]ֻ���ݴ�Ԫ�أ������ڱ�����j<0ʱ������λ���ѵ�
  int i,j,dk;
  for(dk=n/2;dk>=1;dk=dk/2){   //dk��n/2һֱ������1
     for(i=dk+1;i<=n;++i){
        if(A[i]<A[i-dk]){
            A[0]=A[i];
            for(j=i-dk;j>0&&A[0]<A[j];j-=dk)  //ע��A[0]��û�г䵱�ڱ�������
                A[j+dk]=A[j];
            A[j+dk]=A[0];
        }
     }

  }
}

//ð������
void BubbleSort(int A[],int n){

    int i,j;
    bool flag;              //��ʾ����ð���Ƿ��������ı�־
   for(i=0;i<n-1;++i){
     flag=false;
     for(j=n-1;j>1;j--)
     if(A[j-1]>A[j]){
        int temp=A[j-1];
        A[j-1]=A[j];
        A[j]=temp;
        flag=true;
     }

     if(flag==false) return;
   }
}

//���ֲ���
int Partition(int A[],int low,int high){
  int pivot=A[low];   //����ǰ���еĵ�һ��Ԫ����Ϊ����ֵ���Ա���л���
  while(low<high){
     while(low<high&&A[high]>=pivot) --high;
     A[low]=A[high];      //��������ֵС��Ԫ���Ƶ����
     while(low<high&&A[low]<=pivot) ++low;
     A[high]=A[low];      //��������ֵ���Ԫ���Ƶ��Ҷ�
  }
  A[low]=pivot;
  return low;
}
//��������
void QuickSort(int A[],int low,int high){
    if(low<high){                             //�ݹ���������
        int pivotpos=Partition(A,low,high);   //����
        QuickSort(A,low,pivotpos-1);          //�ֱ�������ӱ���еݹ����
        QuickSort(A,pivotpos+1,high);
    }
}

//��ѡ������
void SelectSort(int A[],int n){
   int i,j,Min;
   for(i=0;i<n-1;i++){
     Min=i;
     for(j=i+1;j<n;j++)
        if(A[j]<A[Min]) Min=j;   //������СԪ��λ��
     if(Min!=i){
        int temp=A[i];
        A[i]=A[Min];
        A[Min]=temp;
     }
   }
}

//���µ�����
void AdjustDown(int A[],int k,int len){
   int i;
   A[0]=A[k];
   for(i=2*k;i<=len;i*=2){          //�ؽϴ���ӽ������ɸѡ
       if(i<len&&A[i]<A[i+1]) ++i;  //ȡ�ϴ�ֵ�ӽ����±�
       if(A[0]>=A[i]) break;
        else{
            A[k]=A[i];              //��A[i]������˫�׽����
            k=i;                    //�޸�kֵ���Ա��������ɸѡ
        }
   }//for
   A[k]=A[0];                       //��ɸѡ����ֵ��������λ��
}
//���������
void BuildMaxHeap(int A[],int len){
    for(int i=len/2;i>0;i--){
        AdjustDown(A,i,len);
    }

}
//�����򣨶����������±���������ȫ�������ģ��±��1��ʼ�������±�Ϊ0��Ԫ�ز���������
void HeapSort(int A[],int len){

     BuildMaxHeap(A,len);       //��ʼ����
     for(int i=len;i>1;i--){        //n-1�˵Ľ����ͽ��ѹ���
        int temp=A[i];
        A[i]=A[1];
        A[1]=temp;              //���ջ��Ԫ�أ���ջ��Ԫ�ؽ�����
        AdjustDown(A,1,i-1);   //������ʣ���i-1��Ԫ������ɶ�
     } //for
}


//����������й鲢
void Merge(int A[],int low,int mid,int high){

  int i,j,B[50],k;

  for( k=low;k<=high;++k)                   //��A������Ԫ�ظ��Ƶ�B��
    B[k]=A[k];

  for(i=low,j=mid+1,k=i;i<=mid&&j<=high;++k){
     if(B[i]<=B[j])                           //�Ƚ�B�����������е�Ԫ��
        A[k]=B[i++];                          //����Сֵ��ֵ��A��
     else
        A[k]=B[j++];
  }//for
  while(i<=mid) A[k++]=B[i++];                //����һ����δ����꣬����
  while(j<=high) A[k++]=B[j++];               //���ڶ�����δ����꣬����

}
//�鲢����
void MergSort(int A[],int low,int high){
    if(low<high){                            //���м仮������������
        int mid=(low+high)/2;
        MergSort(A,low,mid);                 //����������н��еݹ�����
        MergSort(A,mid+1,high);              //���Ѳ������н��еݹ�����
        Merge(A,low,mid,high);               //�鲢
    }//if
}



















