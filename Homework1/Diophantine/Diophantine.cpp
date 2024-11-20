#include <iostream>

using namespace std;

class Diophantine {
//�u�� Diophantine ��{��
//�����ܼ� ax + bx + c ����{���D��
private:
    int q;
    int a,b,c;//ax+by=c���u�ʤ�{��
    int d;//�x�s�̤j���]��
    int r,r1,r2;
    int s,s1=1,s2=0;
    int t,t1=0,t2=1;
    int x0,y0;  //�S��
    int x,y;    //�q��
public:
    void Input();
    void algorithm();
    void Output();
};

void Diophantine::Input(){
    cin>>a>>b>>c;//�T��J
    r1=a;   r2=b;
}

void Diophantine::algorithm(){
    while(r2>0){//�ڴX��?�����t��k
        q=r1/r2;//q:��
        r=r1-q*r2;//r�l��
        r1=r2;  r2=r;
        s=s1-q*s2;
        s1=s2;  s2=s;
        t=t1-q*t2;
        t1=t2;  t2=t;
    }
    d=r1;s=s1;t=t1;//���o�̤j���]�ơBs�Bt
}


void Diophantine::Output(){
    if(c%d==0){
        cout<<"���L���h��"<<endl;
        a/=d;   b/=d;   c/=d;//��{������
        x0=c*s; y0=c*t;
        x=x0;   y=y0;
        cout<<"�S��:x0="<<x0<<",y0="<<y0<<endl;
        cout<<"�q��:x="<<x<<"+"<<b<<"k,"<<"y="<<y<<"-"<<a<<"k   (k is constant)"<<endl;
    }
    else {
        cout<<"�L��"<<endl;
    }
}

int main() {
    Diophantine D;//�إߪ���
    D.Input();//��J
    D.algorithm();//�ڴX���w�����t��k
    D.Output();//��X
}
