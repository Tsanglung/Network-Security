#include<iostream>
#include<vector>

using namespace std;

int main()
{
	//string Msg = "lift is full of surprises";	//�D�ئr��
	//string key_word = "HEALTH";					//�D������r

	string Msg = "she is listening";
	string key_word = "PASCAL";

	vector<string>Message;	//�x�s���Ϋ᪺�r��

	while (1) {//�H�Ů�" "�A�Ӥ��Φr��
		Message.push_back(Msg.substr(0, Msg.find(" ")));	//�Ĥ@�Ӫťդ��ΥX�����l�r���Jvector
		Msg = Msg.substr(Msg.find(" ") + 1, Msg.length());	//�Ĥ@�Ӫťդ��ΥX�k���l�r��]��Mag

		if (Msg.find(" ") == -1) {	// ���o�̫�@�Ӧr�C�̫�@�Ӧr�䤣��ťդF
			Message.push_back(Msg);	//�N���Ϊ��r���Jvector
			break;
		}
	}

	int Length = key_word.size();
	int* key_num;
	key_num = new int[Length];
	for (int x = 0; x < Length; x++) {
		key_num[x] = key_word[x] - 65;
	}

	string cipher;//�K��
	vector<string>Message_cipher;//�H�Ů���}�x�s�K��A�Ω�᭱�ѱK�[�J�Ů��٭����
	int num = 0;
	for (int i = 0; i < Message.size(); i++) {	//�[�K
		cipher.clear();
		for (int j = 0; j < Message[i].size(); j++) {
			if (num == Length) num = 0;
			cipher += ((Message[i][j] - 97) + key_num[num]) % 26 + 65;
			num++;
		}
		Message_cipher.push_back(cipher);//�N�Ů���}�x�s���K���Jvector
	}
	cout << "�[�K��A�K�� : ";
	for (int x = 0; x < Message_cipher.size(); x++)
		cout << Message_cipher[x];//��X�K��

	cout << endl;

	string plain;//����
	num = 0;
	for (int i = 0; i < Message_cipher.size(); i++) {	//�ѱK
		for (int j = 0; j < Message_cipher[i].size(); j++) {

			if (num == Length) num = 0;

			if (((Message_cipher[i][j] - 65) - key_num[num]) < 0){
				plain += ((Message_cipher[i][j] - 65) - key_num[num]) % 26 + 26 + 97;//�K��ѱK
				num++;
			}
			else {
				plain += ((Message_cipher[i][j] - 65) - key_num[num]) % 26 + 97;//�K��ѱK
				num++;
			}
		}
		plain += " ";//�[�J�Ů��٭����
	}
	cout << "�ѱK��A���� : ";
	cout << plain << endl;//��X����

}
