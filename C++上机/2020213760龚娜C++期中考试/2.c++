//定义一个Clock类，
//其中包含小时，分，秒及时区(int类型，如8表示+8)。
//根据要求，补充完善Clock类和主函数的功能，实现Clock数组的排序

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Clock {
    public:
        int h;
        int m;
        int s;
        int zone; 
        // 范围[-12, 12] 例如 中国为+8
    public:   
        Clock();
        ~Clock();
};
Clock::Clock(){
    //要取得 [a,b) 的随机整数，使用 (rand() % (b-a))+ a;
    h=(rand() %(24-0))+0;
    m=(rand()%(59-0))+0;
    s=(rand()%(59-0))+0;
    //要取得 [a,b] 的随机整数，(rand() % (b-a+1))+ a;
    zone=(rand() % (12-(-12)+1))+ (-12);
}
Clock::~Clock(){

}


void swap(Clock* xp,Clock *yp){
    Clock temp;
    temp=*xp;
    *xp=*yp;
    *yp=temp;
}

void BubbleSort(Clock arr[],int size){
    int  swapped;
    for(int i=0;i<size-1;i++){
        swapped=false;
        for(int j=0;j<size-i-1;j++){
            if(arr[j].h>arr[j+1].h){
                swapped = true;
                swap(&arr[j],&arr[j+1]);
            }
            if(arr[j].h==arr[j+1].h){
                if(arr[j].m>arr[j+1].m){
                    swapped = true;
                    swap(&arr[j],&arr[j+1]);
                }
                if(arr[j].m==arr[j+1].m){
                    if(arr[j].s>arr[j+1].s){
                        swapped = true;
                        swap(&arr[j],&arr[j+1]);
                    }
                }
            }

        }
        if(swapped==false){
            break;
        }
    }
}
void PrintArray(Clock arr[],int size){
    int i;
    printf("After BubbleSort the result is:\n");
    for(i=0;i<size;i++){

        printf("arr[%d]:%d:%d:%d   zone=%d\n",i, arr[i].h, arr[i].m, arr[i].s ,arr[i].zone);
    }
    

}

int main() {
    // 初始化随机种子
    srand((unsigned)time(NULL));
    int count = 20;
    // 定义 count 个Clock对象，其h, m, s, zone均由随机生成
    Clock ClockArray[20];

    
    // rand()函数 随机生成 0 到无穷  之间的一个整数
    Clock * cs;

    // 对 count个Clock按格林威治标准时间按升序排序
    BubbleSort(ClockArray,count);

    // 显示排序后的结果
    PrintArray(ClockArray,count);
     

   

    
}