#include"Mul_Cipher.h"
#include"Add_Cipher.h"
#include"aff_Cipher.h"
#include<iostream>

using namespace std;

int main() 
{
	string Msg = "this is an exercise";//題目字串
	//string Msg="hello ";
	int key;
	cout<<"輸入金鑰:";
	cin>>key;

	M_Cipher Mul;
	Mul.getKey(key);
	Mul.getPlain(Msg);
	Mul.Mul_encryption();//乘法加密
	Mul.Mul_decryption();//乘法解密

	cout<<"輸入金鑰:";
	cin>>key;
	A_Cipher Add;
	Add.getKey(key);
	Add.getPlain(Msg);
	Add.Add_encryption();//加法加密
	Add.Add_decryption();//加法解密

	int M_key,A_key;
	cout<<"輸入乘法、加法金鑰:";
	cin>>M_key>>A_key;
	affine_Cipher aff;
	aff.getKey(M_key,A_key);
	aff.getPlain(Msg);
	aff.aff_encryption();//仿射加密
	aff.aff_decryption();
}