/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
    T* A;
    int size;
    int length;
    
    
    void swap(T* x, T* y);
public:
    Array()
    {
        size=10;
        length=0;
        A=new T[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new T[size];
    }
    ~Array()
    {
        delete []A;
        A=NULL;
        
    }
    
    void Display();
    void Append(T x);
    void Insert(int index, T x);
    T Delete(int index);
    int LinearSearch(T key);
    int LinearSearch2(T key);
    int LinearSearch3(T key);
    int BinSearch(T key);
    int RBinSearch(int l, int h, T key);
    T Get(int index);
    void Set(int index, T x);
    T Max();
    T Min();
    T Sum();
    T Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(T x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array* arr2);
    Array* Union(Array* arr2);
    Array* Intersection(Array* arr2);
    Array* Difference(Array* arr2);
};

template<class T>
void Array<T>::Display()
{
    int i;
    printf("Elements are\n");
    for (i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    printf("\n");
}


template<class T>
void Array<T>::Append(T x)
{
    if (length < size) {
        A[length++] = x;
    }
}

template<class T>
void Array<T>::Insert(int index, T x)
{
    int i = 0;
    if (index >= 0 && index <= length) {
        for (i=length; i > index; i--) {
            A[i] = A[i-1];
        }
        A[index]=x;
        length++;
    }
}

template<class T>
T Array<T>::Delete(int index)
{
    T x = 0;
    int i = 0;
    if (index >= 0 && index <= length) {
        x = A[index];
        for(i=index; i < length-1; i++) {
            A[i] = A[i+1];
        }
        length--;
        
    }
    return x;
}

template<class T>
void Array<T>::swap(T* x, T* y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

template<class T>
int Array<T>::LinearSearch(T key)
{
    int i =0;
    for (i = 0; i < length; i++) {
       if (key == A[i]) return i;
    }
    return -1;
}

template<class T>
int Array<T>::LinearSearch2(T key)
{
    int i =0;
    for (i = 0; i < length; i++) {
       if (key == A[i]) {
           swap(&A[i], &A[i-1]);
           return i;
       }
    }
    return -1;
}


template<class T>
int Array<T>::LinearSearch3(T key)
{
    int i =0;
    for (i = 0; i < length; i++) {
       if (key == A[i]) {
           swap(&A[i], &A[0]);
           return i;
       }
    }
    return -1;
}

template<class T>
int Array<T>::BinSearch(T key)
{
    int l = 0,h = length-1;
    
    while (l <= h) {
        int mid = (l+h)/2;
        if (key == A[mid]) return mid;
        else if (key < A[mid]) h = mid - 1;
        else if (key > A[mid]) l = mid + 1;
    }
    return -1;
}

template<class T>
int Array<T>::RBinSearch(int l, int h, T key)
{
     int mid;
    if (l < h) {
         mid = (l+h)/2;
        if (key == A[mid]) return mid;
        else if (key < A[mid]) return RBinSearch(l , mid-1, key);
        else if (key > A[mid]) return RBinSearch(mid+1, h, key);
    }
    return -1;
}

template<class T>
T Array<T>::Get(int index)
{
    if (index >= 0 && index < length) {
        return A[index];
    }
    return -1;
}

template<class T>
void Array<T>::Set(int index, T x) {
    if (index >= 0 && index < length) {
        A[index] = x;
    }
}

template<class T>
T Array<T>::Max() {
    T max = A[0];
    int i = 0;
    for (i=1;i<length;i++) {
        if(A[i] > max) max = A[i];
    }
    return max;
}

template<class T>
T Array<T>::Min() {
    T min = A[0];
    int i = 0;
    for (i=1;i<length;i++) {
        if(A[i] < min) min = A[i];
    }
    return min;
}

template<class T>
T Array<T>::Sum()
{
    T s = 0;
    int i;
    for (i = 0; i < length; i++) {
        s+= A[i];
    }
    return s;
}

template<class T>
T Array<T>::Avg()
{
    return (float)Sum()/length;
}


template<class T>
void Array<T>::Reverse()
{
    T *B;
    int i,j;
    
    B = new Array(length);
    
    for (i=length-1,j=0; i>=0; i--,j++) {
        B[j] = A[i];
    }
    for (i = 0; i < length; i++) {
        A[i] = B[i];
    }
    
    delete B;
}

template<class T>
void Array<T>::Reverse2()
{
    int i =0, j =0;
    for (i=0, j =length-1; i < j; i++,j--) {
        swap(&A[i], &A[j]);
    }
}

template<class T>
void Array<T>::InsertSort(T x)
{
    if (length == size) return;
    int i = length-1;
    
    while (i >= 0 && A[i] > x) {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
    printf("length = %d\n", length);
}

template<class T>
int Array<T>::isSorted()
{
    int i = 0;
    for ( i = 0; i < length-1; i++) {
        if (A[i] > A[i+1]) return 0;
    }
    return 1;
}

template<class T>
void Array<T>::Rearrange()
{
    int i = 0,j = length-1;
    while (i < j)
    {
        while(A[i] < 0) i++;
        while(A[j] >= 0) j--;
        if (i < j) {
           swap(&A[i], &A[j]); 
        }
    }
}

template<class T>
Array<T>* Array<T>::Merge(Array* arr2)
{
    int i,j, k;
    Array* arr3 = (Array*)malloc(sizeof(Array));
    
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j]) {
            arr3->A[k++] = A[i++];
        } else {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    
    for (; i < length; i++) {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2->length; j++) {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = length + arr2->length;
    arr3->size=10;
    return arr3;
}

template<class T>
Array<T>* Array<T>::Union(Array* arr2)
{
    int i,j, k;
    Array* arr3 = (Array*)malloc(sizeof(Array));
    
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j]) {
            arr3->A[k++] = A[i++];
        } else if (A[i] > arr2->A[j]) {
            arr3->A[k++] = arr2->A[j++];
        } else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    
    for (; i < length; i++) {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2->length; j++) {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size=10;
    return arr3;
}

template<class T>
Array<T>* Array<T>::Intersection(Array* arr2)
{
    int i,j, k;
    Array* arr3 = (Array*)malloc(sizeof(Array));
    
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j]) {
            i++;
        } else if (A[i] > arr2->A[j]) {
            j++;
        } else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    

    arr3->length = k;
    arr3->size=10;
    return arr3;
}

template<class T>
Array<T>* Array<T>::Difference(Array* arr2)
{
    int i,j, k;
    Array* arr3 = (Array*)malloc(sizeof(Array));
    
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j]) {
            arr3->A[k++] = A[i++];
        } else if (A[i] > arr2->A[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    
    for (; i < length; i++) {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2->length; j++) {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size=10;
    return arr3;
}


int main()
{
    Array<float>* arr1;
    int ch, sz;
    float x;
    int index;
    
    printf("Enter size of array ");
    scanf("%d", &sz);
    arr1=new Array<float>(sz);
    
    do
    {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        
        printf("Enter your choice :");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1: {
                printf("Enter an element and index :");
                scanf("%f%d", &x, &index);
                arr1->Insert(index, x);
                break;
            }
            case 2: {
                printf("Enter index :");
                scanf("%d", &index);
                x=arr1->Delete(index);
                cout << "Delte element is " << x << endl;
                break;
            }
            case 3: {
                printf("Enter element to search :");
                scanf("%f", &x);
                index=arr1->LinearSearch(x);
                printf("Element index %d", index);
                break;
            }
            case 4: {
                printf("Sum is : %f\n", arr1->Sum());
                break;
            }
            case 5: {
                arr1->Display();
                break;
            }
    
        }
        
        
        
    } while (ch < 6);
    
    
    return 0;
}





