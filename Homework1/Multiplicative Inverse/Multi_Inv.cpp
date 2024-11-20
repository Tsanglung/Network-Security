#include <iostream>

using namespace std;

//ノ稼碭ń眔┑簍衡猭т猭はじ
class Inverse {

private:
    int q;
    int a,b;//a:家计
            //b:тb家计a猭はじ
    int d;//纗程そ计
    int r,r1,r2;
    int s,s1=1,s2=0;
    int t,t1=0,t2=1;
    int Inverse;//猭はじ
public:
    void Input();
    void algorithm();
    void Output();
};

void Inverse::Input(){
    cin>>a>>b;//ㄢ块
    r1=a;   r2=b;
}

void Inverse::algorithm(){
    while(r2>0){//稼碭ń?┑簍衡猭
        q=r1/r2;//q:坝
        r=r1-q*r2;//r緇计
        r1=r2;  r2=r;
        s=s1-q*s2;
        s1=s2;  s2=s;
        t=t1-q*t2;
        t1=t2;  t2=t;
    }
    d=r1;s=s1;t=t1;//眔程そ计st
}

void Inverse::Output(){
    //т猭はじ礚斗s
    if(d==1){
        cout<<b<<"猭はじ"<<endl;
        if(t<0){//緇计ゲ獶璽俱计
            Inverse=t%a+a;
            cout<<b<<"猭はじ="<<Inverse<<endl;
        
        //璝b㎝Inverse家计aいが猭はじ
        //玥b*Inverse%a=1
        //cout<<b*Inverse%a<<endl;
        }
        else{
        Inverse=t%a;
        cout<<b<<"猭はじ="<<Inverse<<endl;
        
        //璝b㎝Inverse家计aいが猭はじ
        //玥b*Inverse%a=1
        //cout<<b*Inverse%a<<endl;
        }
    }
    else cout<<"猭はじぃ"<<endl;
    
}

int main() {
    Inverse D;//ミン
    D.Input();//块
    D.algorithm();//稼碭ń紈┑簍衡猭
    D.Output();//块
}
