#include <iostream>

using namespace std;

class Diophantine {
//線性 Diophantine 方程式
//對雙變數 ax + bx + c 的方程式求解
private:
    int q;
    int a,b,c;//ax+by=c的線性方程式
    int d;//儲存最大公因數
    int r,r1,r2;
    int s,s1=1,s2=0;
    int t,t1=0,t2=1;
    int x0,y0;  //特解
    int x,y;    //通解
public:
    void Input();
    void algorithm();
    void Output();
};

void Diophantine::Input(){
    cin>>a>>b>>c;//三輸入
    r1=a;   r2=b;
}

void Diophantine::algorithm(){
    while(r2>0){//歐幾里?延伸演算法
        q=r1/r2;//q:商
        r=r1-q*r2;//r餘數
        r1=r2;  r2=r;
        s=s1-q*s2;
        s1=s2;  s2=s;
        t=t1-q*t2;
        t1=t2;  t2=t;
    }
    d=r1;s=s1;t=t1;//取得最大公因數、s、t
}


void Diophantine::Output(){
    if(c%d==0){
        cout<<"有無限多解"<<endl;
        a/=d;   b/=d;   c/=d;//方程式約分
        x0=c*s; y0=c*t;
        x=x0;   y=y0;
        cout<<"特解:x0="<<x0<<",y0="<<y0<<endl;
        cout<<"通解:x="<<x<<"+"<<b<<"k,"<<"y="<<y<<"-"<<a<<"k   (k is constant)"<<endl;
    }
    else {
        cout<<"無解"<<endl;
    }
}

int main() {
    Diophantine D;//建立物件
    D.Input();//輸入
    D.algorithm();//歐幾里德延伸演算法
    D.Output();//輸出
}
