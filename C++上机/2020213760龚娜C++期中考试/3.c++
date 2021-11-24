#include <cstring>
#include<iostream>
#include <math.h>
using namespace std;

class CArray
{
    int size;  //数组元素的个数
    int* ptr;  //指向动态分配的数组
public:
    CArray(int s = 0); 
    CArray(CArray & a);
    ~CArray();
    void push_back(int v);  
    CArray & operator = (const CArray & a);
    int length() const { return size; }  
    int & operator[](int i)
    {  
        return ptr[i];
    };
};
CArray::CArray(int s) : size(s)
{
    if (s == 0)
        ptr = NULL;
    else
        ptr = new int[s];
}
CArray::CArray(CArray & a)
{
    if (!a.ptr) {
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}
CArray::~CArray()
{
    if (ptr) delete[] ptr;
}
CArray & CArray::operator=(const CArray & a)
{ 
    if (ptr == a.ptr)  
        return *this;
    if (a.ptr == NULL) { 
        if (ptr)
            delete[] ptr;
        ptr = NULL;
        size = 0;
        return *this;
    }
    if (size < a.size) {  
        if (ptr)
            delete[] ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int)*a.size);
    size = a.size;
    return *this;
}
void CArray::push_back(int v)
{  //在数组尾部添加一个元素
    if (ptr) {
        int* tmpPtr = new int[size + 1];  //重新分配空间
        memcpy(tmpPtr, ptr, sizeof(int) * size);  //复制原数组内容
        delete[] ptr;
        ptr = tmpPtr;
    }
    else  //数组本来是空的
        ptr = new int[1];
    ptr[size++] = v;  //加入新的数组元素
}
int main()
{
    CArray a;  
    for (int i = 0; i<5; ++i)
        a.push_back(i);
    CArray a2, a3;
    a2 = a;
    for (int i = 0; i<a.length(); ++i)
        cout << a2[i] << " ";
    a2 = a3;  
    for (int i = 0; i<a2.length(); ++i)  
        cout << a2[i] << " ";
    cout << endl;
    a[3] = 100;
    CArray a4(a);
    for (int i = 0; i<a4.length(); ++i)
        cout << a4[i] << " ";
    return 0;
}


   

