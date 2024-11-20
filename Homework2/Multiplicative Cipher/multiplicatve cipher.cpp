#include<iostream>
#include<string>
#include<vector>

//���k�[�K�k

using namespace std;

int multi_inverse(int k) {//�ڴX���w�����t��k�D���_�����k�Ϥ���
	///���k�[�K�k�����_�u��12��:1,3,5,7,9,11,15,17,19,21,23
	int r1 = 26, r2 = k;
	int t1 = 0, t2 = 1;
	while (r2 > 0) {
		int q = r1 / r2;//q �]��
		int r = r1 - q * r2;//r �l��
		r1 = r2;	r2 = r;

		int t = t1 - q * t2;
		t1 = t2;	t2 = t;
	}
	if (r1 == 1) {//�Y���_�P�Ҽ�26���̤j���]�Ƭ�1�A�h�����k�Ϥ��� = t1
		if (t1 < 0) {//�Yt1�D�X���t�A�h�ݥ[�W�Ҽ�26�A�ܬ��D�t���
			t1 = t1 % 26 + 26;
		}
		else 
			t1 = t1 % 26;
	}
	return t1;
}

int main() 
{
	string Msg= "this is an exercise";//�D�ئr��

	vector<string>Message;//�x�s���Ϋ᪺�r��

	while (1) {//�H�Ů�" "�A�Ӥ��Φr��
		Message.push_back(Msg.substr(0, Msg.find(" ")));//�Ĥ@�Ӫťդ��ΥX�����l�r���Jvector
		Msg = Msg.substr(Msg.find(" ") + 1, Msg.length());//�Ĥ@�Ӫťդ��ΥX�k���l�r��]��Mag

		if (Msg.find(" ") == -1) { // ���o�̫�@�Ӧr�C�̫�@�Ӧr�䤣��ťդF
			Message.push_back(Msg);//�N���Ϊ��r���Jvector
			break;
		}
	}

	int key = 15;//���_=15
	string cipher;//�K��
	vector<string>Message_cipher;//�H�Ů���}�x�s�K��A�Ω�᭱�ѱK�[�J�Ů��٭����
	for (int i = 0; i < Message.size(); i++) {	//�[�K
		cipher.clear();
		for (int j = 0; j < Message[i].size(); j++) {
			cipher += ((Message[i][j] - 97) * key) % 26 + 65;
		}
		Message_cipher.push_back(cipher);//�N�Ů���}�x�s���K���Jvector
	}
	cout << "�[�K��A�K�� : ";
	for (int x = 0; x < Message_cipher.size(); x++) 
		cout << Message_cipher[x];//��X�K��

	cout << endl;

	string plain;//����
	int key_inverse = multi_inverse(key);//�D�Xkey�b�Ҽ�26�������k�Ϥ���

	for (int i = 0; i < Message_cipher.size(); i++) {	//�ѱK
		for (int j = 0; j < Message_cipher[i].size(); j++) {
			plain += ((Message_cipher[i][j] - 65) * key_inverse) % 26 + 97;//�K��ѱK
		}
		plain += " ";//�[�J�Ů��٭����
	}
	cout << "�ѱK��A���� : ";
	cout << plain << endl;//��X����

}
