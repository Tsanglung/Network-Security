#include<iostream>
#include<vector>

using namespace std;

//��g�[�K
//���k���_�� Z26*����(i mod 12)�Ӥ���
//�[�k���_�� Z26����(i mod 26)�Ӥ���
//�[�K�T�� "cryptography is fun"

int main() {
	string Msg = "cryptography is fun";						//�D�ئr��
	int Multi_key[] = { 1,3,5,7,9,11,15,17,19,21,23,25 };	//���k���_
	int k1,k2;////k1���k���_,k2�[�k���_

	vector<string>Message;//�x�s���Ϋ᪺�r��

	while (1) {//�H�Ů�" "�A�Ӥ��Φr��
		Message.push_back(Msg.substr(0, Msg.find(" ")));//�Ĥ@�Ӫťդ��ΥX�����l�r���Jvector
		Msg = Msg.substr(Msg.find(" ") + 1, Msg.length());//�Ĥ@�Ӫťդ��ΥX�k���l�r��]��Mag

		if (Msg.find(" ") == -1) { // ���o�̫�@�Ӧr�C�̫�@�Ӧr�䤣��ťդF
			Message.push_back(Msg);//�N���Ϊ��r���Jvector
			break;
		}
	}

	string plain;//����
	for (int i = 0; i < Message.size(); i++) {
		for (int j = 0; j < Message[i].size(); j++) {
			plain += Message[i][j];
		}
	}

	string cipher;//�K��
	vector<string>Message_cipher;
	k1 = 0; k2 = 0;
	for (int i = 0; i < Message.size(); i++) {	//�[�K
		cipher.clear();
		
		for (int j = 0; j < Message[i].size(); j++) {
			cipher += ((Message[i][j] - 97) * Multi_key[k1] + (k2 % 26)) % 26 + 65;
			k1++;
			k2++;
		}
		Message_cipher.push_back(cipher);//�N�Ů���}�x�s���K���Jvector
	}
	cout << "�[�K��A�K�� : ";
	for (int x = 0; x < Message_cipher.size(); x++)
		cout << Message_cipher[x];//��X�K��
}
