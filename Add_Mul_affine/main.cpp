#include"Mul_Cipher.h"
#include"Add_Cipher.h"
#include"aff_Cipher.h"
#include<iostream>

using namespace std;

int main() 
{
	string Msg = "this is an exercise";//�D�ئr��
	//string Msg="hello ";
	int key;
	cout<<"��J���_:";
	cin>>key;

	M_Cipher Mul;
	Mul.getKey(key);
	Mul.getPlain(Msg);
	Mul.Mul_encryption();//���k�[�K
	Mul.Mul_decryption();//���k�ѱK

	cout<<"��J���_:";
	cin>>key;
	A_Cipher Add;
	Add.getKey(key);
	Add.getPlain(Msg);
	Add.Add_encryption();//�[�k�[�K
	Add.Add_decryption();//�[�k�ѱK

	int M_key,A_key;
	cout<<"��J���k�B�[�k���_:";
	cin>>M_key>>A_key;
	affine_Cipher aff;
	aff.getKey(M_key,A_key);
	aff.getPlain(Msg);
	aff.aff_encryption();//��g�[�K
	aff.aff_decryption();
}