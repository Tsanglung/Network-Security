#include<iostream>
#include<vector>

using namespace std;

void GetKeyMatrix(string key, int keymatrix[][2]) {
	int k = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			keymatrix[i][j] = (key[k]) % 65;
			//cout << keymatrix[i][j] << endl;
			k++;
		}
	}
}

void encrypt(int C_matrix[][2], int K_matrix[][2], int M_matrix[][2]) {

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 2; j++)
			C_matrix[i][j] = 0;

	
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				C_matrix[i][j] += M_matrix[i][k] * K_matrix[k][j];
			}
			//cout << C_matrix[i][j] << endl;
			C_matrix[i][j] %= 26;
			//cout << C_matrix[i][j] << endl;
		}
	}
}

void HillCipher(string Message, string key) {

	int key_matrix[2][2];
	GetKeyMatrix(key, key_matrix);

	int Message_matrix[12][2];

	int x = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 2; j++) {
			Message_matrix[i][j] = Message[x] % 97;
			x++;
			//cout << Message_matrix[i][j] << endl;
		}
	}

	int Cipher_matrix[12][2];

	encrypt(Cipher_matrix, key_matrix, Message_matrix);

	string Cipher_text;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 2; j++) {
			Cipher_text += Cipher_matrix[i][j] + 65;
		}
	}
	cout << Cipher_text << endl;
}

int main() {
	string Msg="we live in an insecure world";//23字元
	string Message_1;
	vector<string> Message;

	while (1) {//以空格" "，來分割字串
		Message.push_back(Msg.substr(0, Msg.find(" ")));	//第一個空白分割出左側子字串放入vector
		Msg = Msg.substr(Msg.find(" ") + 1, Msg.length());	//第一個空白分割出右側子字串設為Mag

		if (Msg.find(" ") == -1) {	// 取得最後一個字。最後一個字找不到空白了
			Message.push_back(Msg);	//將分割的字串放入vector
			break;
		}
	}

	for (int i = 0; i < Message.size(); i++) {
		for (int j = 0; j < Message[i].size(); j++) {
			Message_1 += Message[i][j];
		}
	}
	//cout << Message_1 << endl;

	string key="DCFH";//3 2 5 7

	if (Message_1.size() % 2 != 0)
		Message_1 += 'z';

	HillCipher(Message_1, key);
}
