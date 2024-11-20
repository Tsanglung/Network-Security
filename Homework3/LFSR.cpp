#include <iostream>
#include <stdlib.h>
#include <bitset>
#define n 5
using namespace std;
int main()
{
	//初始化n位的二進制，初始為(1110)
	bitset<n>bint(14);
	string s1,s2;//儲存輸出
    int j = bint[1] ^ bint[0];//XOR
    bint[n - 1] = j;
	cout << "Initial state :"<<bint.to_string() << endl;
	s1 = bint.to_string();
	s2.push_back(s1[4]);//b[0](金鑰串流值)值放入s2儲存
	bint.operator>>=(1);//向右移1位
	//生成LFSR的狀態變化
    int i=1;
	while(true)
	{
        if(i>20)break;
		int j = bint[1] ^ bint[0];
		bint[n - 1] = j;
		cout <<i<<":"<< bint.to_string() << endl;
		//bint->string放入s1
		s1 = bint.to_string();
		s2.push_back(s1[4]);//b[0](金鑰串流值)值放入s2儲存
        bint.operator>>=(1);//向右移1位
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
