#include <iostream>

using namespace std;

//�Q�μڴX���o�����t��k��X���k�Ϥ���
class Inverse {

private:
    int q;
    int a,b;//a:�Ҽ�
            //b:��Xb�b�Ҽ�a�����k�Ϥ���
    int d;//�x�s�̤j���]��
    int r,r1,r2;
    int s,s1=1,s2=0;
    int t,t1=0,t2=1;
    int Inverse;//���k�Ϥ���
public:
    void Input();
    void algorithm();
    void Output();
};

void Inverse::Input(){
    cin>>a>>b;//���J
    r1=a;   r2=b;
}

void Inverse::algorithm(){
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

void Inverse::Output(){
    //�䭼�k�Ϥ����L��s
    if(d==1){
        cout<<b<<"�����k�Ϥ����s�b"<<endl;
        if(t<0){//�l�ƥ����D�t���
            Inverse=t%a+a;
            cout<<b<<"�����k�Ϥ���="<<Inverse<<endl;
        
        //�Yb�MInverse�b�Ҽ�a���������k�Ϥ���
        //�hb*Inverse%a=1
        //cout<<b*Inverse%a<<endl;
        }
        else{
        Inverse=t%a;
        cout<<b<<"�����k�Ϥ���="<<Inverse<<endl;
        
        //�Yb�MInverse�b�Ҽ�a���������k�Ϥ���
        //�hb*Inverse%a=1
        //cout<<b*Inverse%a<<endl;
        }
    }
    else cout<<"���k�Ϥ������s�b"<<endl;
    
}

int main() {
    Inverse D;//�إߪ���
    D.Input();//��J
    D.algorithm();//�ڴX���w�����t��k
    D.Output();//��X
}
