#include"Vigenere.h"
#include<iostream>

using namespace std;

int main(){

    string Message="life is full of surprises";
    string key="HEALTH";

    vigenere V;
    V.getkey(key);//get金鑰
    V.getplain(Message);//get訊息
    V.trans_key();//將字元key轉成數字key
    V.encryption();//加密
    V.decryption();//解密
}
