#include<iostream>
#include<string>
#include<vector>

//乘法加密法

using namespace std;

int multi_inverse(int k) {//歐幾里德延伸演算法求金鑰的乘法反元素
	///乘法加密法的金鑰只有12個:1,3,5,7,9,11,15,17,19,21,23
	int r1 = 26, r2 = k;
	int t1 = 0, t2 = 1;
	while (r2 > 0) {
		int q = r1 / r2;//q 因數
		int r = r1 - q * r2;//r 餘數
		r1 = r2;	r2 = r;

		int t = t1 - q * t2;
		t1 = t2;	t2 = t;
	}
	if (r1 == 1) {//若金鑰與模數26的最大公因數為1，則有乘法反元素 = t1
		if (t1 < 0) {//若t1求出為負，則需加上模數26，變為非負整數
			t1 = t1 % 26 + 26;
		}
		else 
			t1 = t1 % 26;
	}
	return t1;
}

int main() 
{
	string Msg= "this is an exercise";//題目字串

	vector<string>Message;//儲存分割後的字串

	while (1) {//以空格" "，來分割字串
		Message.push_back(Msg.substr(0, Msg.find(" ")));//第一個空白分割出左側子字串放入vector
		Msg = Msg.substr(Msg.find(" ") + 1, Msg.length());//第一個空白分割出右側子字串設為Mag

		if (Msg.find(" ") == -1) { // 取得最後一個字。最後一個字找不到空白了
			Message.push_back(Msg);//將分割的字串放入vector
			break;
		}
	}

	int key = 15;//金鑰=15
	string cipher;//密文
	vector<string>Message_cipher;//以空格分開儲存密文，用於後面解密加入空格還原明文
	for (int i = 0; i < Message.size(); i++) {	//加密
		cipher.clear();
		for (int j = 0; j < Message[i].size(); j++) {
			cipher += ((Message[i][j] - 97) * key) % 26 + 65;
		}
		Message_cipher.push_back(cipher);//將空格分開儲存的密文放入vector
	}
	cout << "加密後，密文 : ";
	for (int x = 0; x < Message_cipher.size(); x++) 
		cout << Message_cipher[x];//輸出密文

	cout << endl;

	string plain;//明文
	int key_inverse = multi_inverse(key);//求出key在模數26中的乘法反元素

	for (int i = 0; i < Message_cipher.size(); i++) {	//解密
		for (int j = 0; j < Message_cipher[i].size(); j++) {
			plain += ((Message_cipher[i][j] - 65) * key_inverse) % 26 + 97;//密文解密
		}
		plain += " ";//加入空格還原明文
	}
	cout << "解密後，明文 : ";
	cout << plain << endl;//輸出明文

}
