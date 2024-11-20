#include<iostream>
#include<vector>
using namespace std;

class vigenere{
    private:
        string key;//關鍵字
        string Message;
        string cipher;
        string Message_plain;
		vector<string> plain;
        vector<string> Message_cipher;
        int *ikey;//數字key陣列
    public:
        void getkey(string k){key=k;}
        void trans_key();//將關鍵字轉int
        void getplain(string p){ Message=p;}
        void encryption();
        void decryption();
};

void vigenere::trans_key(){
    int n=key.size();//關鍵字數字陣列大小
    ikey=new int[n];
    for(int i=0;i<n;i++){
        ikey[i]=key[i]-65;//關鍵字轉數字(ASCII碼運算)
    }
}

void vigenere::encryption(){
    while (1) {//以空格" "，來分割字串
		plain.push_back(Message.substr(0, Message.find(" ")));	//第一個空白分割出左側子字串放入vector
		Message = Message.substr(Message.find(" ") + 1, Message.length());	//第一個空白分割出右側子字串設為Mag

		if (Message.find(" ") == -1) {	// 取得最後一個字。最後一個字找不到空白了
			plain.push_back(Message);	//將分割的字串放入vector
			break;
		}
	}

    int num = 0;//計數key，第i個數字
	for (int i = 0; i < plain.size(); i++) {	
		for (int j = 0; j < plain[i].size(); j++) {
			if (num == key.size()) num = 0;
			cipher += ((plain[i][j] - 97) + ikey[num]) % 26 + 65;//加密	
			num++;
		}
		Message_cipher.push_back(cipher);//空格分開儲存的密文放入vector
		cipher.clear();
	}
	cout << "加密後，密文 : ";
	for (int x = 0; x < Message_cipher.size(); x++)
		cipher+=Message_cipher[x];

	cout<<cipher<<endl;//輸出密文
}

void vigenere::decryption(){
    int num = 0;
	for (int i = 0; i < Message_cipher.size(); i++) {	//解密
		for (int j = 0; j < Message_cipher[i].size(); j++) {

			if (num == key.size()) num = 0;

			if (((Message_cipher[i][j] - 65) - ikey[num]) < 0){ //若運算為負，須轉為非負整數
				Message_plain += ((Message_cipher[i][j] - 65) - ikey[num]) % 26 + 26 + 97;//密文解密
				num++;
			}
			else {
				Message_plain += ((Message_cipher[i][j] - 65) - ikey[num]) % 26 + 97;//密文解密
				num++;
			}
		}
		Message_plain += " ";//加入空格還原明文
	}
	cout << "解密後，明文 : ";
	cout << Message_plain << endl;//輸出明文
}
