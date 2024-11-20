#include<iostream>
#include<string>
#include<vector>

using namespace std;

class A_Cipher{
	private:
		string plain;//明文
		string cipher;//密文
		vector<string>Message_plain;//儲存分割後的字串
		vector<string>Message_cipher;//以空格分開儲存密文，用於後面解密加入空格還原明文
		int key;
	public:
		void getKey(int k){	key=k; }
		void getPlain(string P){ plain=P; }
		void Add_encryption();
		void Add_decryption();	
};

void A_Cipher::Add_encryption(){
    while (1) {//以空格" "，來分割字串
		Message_plain.push_back(plain.substr(0, plain.find(" ")));//第一個空白分割出左側子字串放入vector
		plain = plain.substr(plain.find(" ") + 1, plain.length());//第一個空白分割出右側子字串設為Mag

		if (plain.find(" ") == -1) { // 取得最後一個字。最後一個字找不到空白了
			Message_plain.push_back(plain);//將分割的字串放入vector
			break;
		}
	}

	for (int i = 0; i < Message_plain.size(); i++) {	//加密
		for (int j = 0; j < Message_plain[i].size(); j++) {
			cipher += ((Message_plain[i][j] - 97) + key) % 26 + 65;
		}
		Message_cipher.push_back(cipher);//將空格分開儲存的密文放入vector
		cipher.clear();
	}
	cout << "加密後，密文 : ";
	for (int x = 0; x < Message_cipher.size(); x++) 
		cipher+=Message_cipher[x];//密文

	cout<<cipher<<endl;
}

void A_Cipher::Add_decryption(){
    plain.clear();
	for (int i = 0; i < Message_cipher.size(); i++) {	//解密
		for (int j = 0; j < Message_cipher[i].size(); j++) {
            if((Message_cipher[i][j] - 65) - key<0)
			    plain += ((Message_cipher[i][j] - 65) - key) % 26 + 26 + 97;//密文解密
            else 
                plain += ((Message_cipher[i][j] - 65) - key) % 26 + 97;//密文解密
		}
		plain += " ";//加入空格還原明文
	}
	cout << "解密後，明文 : ";
	cout << plain << endl;//輸出明文
}