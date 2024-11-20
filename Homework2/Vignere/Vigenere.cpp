#include<iostream>
#include<vector>

using namespace std;

int main()
{
	//string Msg = "lift is full of surprises";	//題目字串
	//string key_word = "HEALTH";					//題目關鍵字

	string Msg = "she is listening";
	string key_word = "PASCAL";

	vector<string>Message;	//儲存分割後的字串

	while (1) {//以空格" "，來分割字串
		Message.push_back(Msg.substr(0, Msg.find(" ")));	//第一個空白分割出左側子字串放入vector
		Msg = Msg.substr(Msg.find(" ") + 1, Msg.length());	//第一個空白分割出右側子字串設為Mag

		if (Msg.find(" ") == -1) {	// 取得最後一個字。最後一個字找不到空白了
			Message.push_back(Msg);	//將分割的字串放入vector
			break;
		}
	}

	int Length = key_word.size();
	int* key_num;
	key_num = new int[Length];
	for (int x = 0; x < Length; x++) {
		key_num[x] = key_word[x] - 65;
	}

	string cipher;//密文
	vector<string>Message_cipher;//以空格分開儲存密文，用於後面解密加入空格還原明文
	int num = 0;
	for (int i = 0; i < Message.size(); i++) {	//加密
		cipher.clear();
		for (int j = 0; j < Message[i].size(); j++) {
			if (num == Length) num = 0;
			cipher += ((Message[i][j] - 97) + key_num[num]) % 26 + 65;
			num++;
		}
		Message_cipher.push_back(cipher);//將空格分開儲存的密文放入vector
	}
	cout << "加密後，密文 : ";
	for (int x = 0; x < Message_cipher.size(); x++)
		cout << Message_cipher[x];//輸出密文

	cout << endl;

	string plain;//明文
	num = 0;
	for (int i = 0; i < Message_cipher.size(); i++) {	//解密
		for (int j = 0; j < Message_cipher[i].size(); j++) {

			if (num == Length) num = 0;

			if (((Message_cipher[i][j] - 65) - key_num[num]) < 0){
				plain += ((Message_cipher[i][j] - 65) - key_num[num]) % 26 + 26 + 97;//密文解密
				num++;
			}
			else {
				plain += ((Message_cipher[i][j] - 65) - key_num[num]) % 26 + 97;//密文解密
				num++;
			}
		}
		plain += " ";//加入空格還原明文
	}
	cout << "解密後，明文 : ";
	cout << plain << endl;//輸出明文

}
