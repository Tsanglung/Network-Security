#include<iostream>
#include<vector>

using namespace std;

//仿射加密
//乘法金鑰為 Z26*中第(i mod 12)個元素
//加法金鑰為 Z26中第(i mod 26)個元素
//加密訊息 "cryptography is fun"

int main() {
	string Msg = "cryptography is fun";						//題目字串
	int Multi_key[] = { 1,3,5,7,9,11,15,17,19,21,23,25 };	//乘法金鑰
	int k1,k2;////k1乘法金鑰,k2加法金鑰

	vector<string>Message;//儲存分割後的字串

	while (1) {//以空格" "，來分割字串
		Message.push_back(Msg.substr(0, Msg.find(" ")));//第一個空白分割出左側子字串放入vector
		Msg = Msg.substr(Msg.find(" ") + 1, Msg.length());//第一個空白分割出右側子字串設為Mag

		if (Msg.find(" ") == -1) { // 取得最後一個字。最後一個字找不到空白了
			Message.push_back(Msg);//將分割的字串放入vector
			break;
		}
	}

	string plain;//明文
	for (int i = 0; i < Message.size(); i++) {
		for (int j = 0; j < Message[i].size(); j++) {
			plain += Message[i][j];
		}
	}

	string cipher;//密文
	vector<string>Message_cipher;
	k1 = 0; k2 = 0;
	for (int i = 0; i < Message.size(); i++) {	//加密
		cipher.clear();
		
		for (int j = 0; j < Message[i].size(); j++) {
			cipher += ((Message[i][j] - 97) * Multi_key[k1] + (k2 % 26)) % 26 + 65;
			k1++;
			k2++;
		}
		Message_cipher.push_back(cipher);//將空格分開儲存的密文放入vector
	}
	cout << "加密後，密文 : ";
	for (int x = 0; x < Message_cipher.size(); x++)
		cout << Message_cipher[x];//輸出密文
}
