#include <iostream>
#include <stdlib.h>
#include <bitset>
#define n 5
using namespace std;
int main()
{
	//��l��n�쪺�G�i��A��l��(1110)
	bitset<n>bint(14);
	string s1,s2;//�x�s��X
    int j = bint[1] ^ bint[0];//XOR
    bint[n - 1] = j;
	cout << "Initial state :"<<bint.to_string() << endl;
	s1 = bint.to_string();
	s2.push_back(s1[4]);//b[0](���_��y��)�ȩ�Js2�x�s
	bint.operator>>=(1);//�V�k��1��
	//�ͦ�LFSR�����A�ܤ�
    int i=1;
	while(true)
	{
        if(i>20)break;
		int j = bint[1] ^ bint[0];
		bint[n - 1] = j;
		cout <<i<<":"<< bint.to_string() << endl;
		//bint->string��Js1
		s1 = bint.to_string();
		s2.push_back(s1[4]);//b[0](���_��y��)�ȩ�Js2�x�s
        bint.operator>>=(1);//�V�k��1��
        i++; 
	}
    cout<<"output sequence:";
	for(int i=0;i<20;i++){
        cout<<s2[i];
    }
	cout<<endl;
	system("pause");
	return 0;
}
