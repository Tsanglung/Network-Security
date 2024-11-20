#include <iostream>

using namespace std;
//求 GCD
class Euclidean {
//歐幾里德演算法
private:
    int r1,r2;

public:
    void Input();
    int algorithm();
};

void Euclidean::Input(){
    cin>>r1>>r2;//輸入
}

int Euclidean::algorithm(){
    while(r2>0){//演算法
        int q=r1/r2;
        int r=r1-q*r2;
        r1=r2;  r2=r;
    }
    return r1;//回傳最大公因數
}

int main() {
    Euclidean E;//建立物件
    E.Input();//輸入
    //88,220
    //300,42
    //24,320
    //401,700
    cout<<E.algorithm()<<endl;//輸出最大公因數
}
