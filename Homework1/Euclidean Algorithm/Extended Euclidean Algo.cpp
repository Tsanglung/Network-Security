#include <iostream>

using namespace std;
//求 GCD
class Euclidean {

private:
    int q;
    int a,b;
    int r,r1,r2;
    int s,s1=1,s2=0;
    int t,t1=0,t2=1;
public:
    void Input();
    void algorithm();
    void Output();
};

void Euclidean::Input(){
    cin>>a>>b;//兩輸入
    r1=a;   r2=b;
}

void Euclidean::algorithm(){
    while(r2>0){//歐幾里徳延伸演算法
        q=r1/r2;    //商
        r=r1-q*r2;
        r1=r2;  r2=r;
        s=s1-q*s2;
        s1=s2;  s2=s;
        t=t1-q*t2;
        t1=t2;  t2=t;
    }
}

void Euclidean::Output(){
    cout<<"gcd("<<a<<","<<b<<")="<<r1<<endl;
    cout<<"s="<<s1<<endl;
    cout<<"t="<<t1<<endl;
}

int main() {
    Euclidean E;//建立物件
    E.Input();//輸入
    E.algorithm();//歐幾里德延伸演算法
    E.Output();//輸出
}
