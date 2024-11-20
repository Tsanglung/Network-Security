#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 50

void toLowerCase(char plain[], int ps) // �j�g��p�g
{
    int i;
    for (i = 0; i < ps; i++) {
        if (plain[i] > 64 && plain[i] < 91)
            plain[i] += 32;
    }
}

int removeSpaces(char* plain, int ps) // �����Ů�
{
    int i, count = 0;
    for (i = 0; i < ps; i++)
        if (plain[i] != ' ')
            plain[count++] = plain[i];
    plain[count] = '\0';
    return count;
}

void generateKeyTable(char key[], int ks, char keyT[5][5]) // �ͦ�5*5�x�}
{
    int i, j, k, flag = 0;
   
    int dicty[26] = { 0 };  // �Ҽ�26
                            // �x�s�r���p��
    for (i = 0; i < ks; i++) {
        if (key[i] != 'j')  //I=J
            dicty[key[i] - 97] = 2;
    }

    dicty['j' - 97] = 1;
    i = 0;
    j = 0;

    for (k = 0; k < ks; k++) {
        if (dicty[key[k] - 97] == 2) {
            dicty[key[k] - 97] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }

    for (k = 0; k < 26; k++) {
        if (dicty[k] == 0) {
            keyT[i][j] = (char)(k + 97);
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
}

void search(char keyT[5][5], char a, char b, int arr[]) //�b���_�x�}���j���r���æ^�ǥ��̪���m
{
    int i, j;
    if (a == 'j')
        a = 'i';
    else if (b == 'j')
        b = 'i';

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (keyT[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyT[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int mod5(int a) { return (a % 5); } // 5*5�x�}(mod 5)

int prepare(char str[], int ptrs) // ������r���Ƭ�����
{
    if (ptrs % 2 != 0) {
        str[ptrs++] = 'z';//�b�ۦP�r�����[�J���r���Ϲj�A�ϩ���r�Ƭ�����
        str[ptrs] = '\0';
    }
    return ptrs;
}

void encrypt(char str[], char keyT[5][5], int ps) // �[�K
{
    int i, a[4];

    for (i = 0; i < ps; i += 2) {

        search(keyT, str[i], str[i + 1], a); //�b���_�x�}���j���r���æ^�ǥ��̪���m

        if (a[0] == a[2]) {
            str[i] = keyT[a[0]][mod5(a[1] + 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
        }
        else if (a[1] == a[3]) {
            str[i] = keyT[mod5(a[0] + 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
        }
        else {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void encryptByPlayfairCipher(char str[], char key[]) //Playfair Cipher
{
    char ps, ks, keyT[5][5];

    // Key
    ks = strlen(key);
    ks = removeSpaces(key, ks);//�����Ů�
    toLowerCase(key, ks);//�j�g��p�g

    //����
    ps = strlen(str);//�r�����
    toLowerCase(str, ps);//�j�g��p�g
    ps = removeSpaces(str, ps);//�����Ů�

    ps = prepare(str, ps);//�Ϧr�Ƭ�����

    generateKeyTable(key, ks, keyT);//5*5�x�}

    encrypt(str, keyT, ps);//�[�K
}

int main()
{
    char str[SIZE] = "the key is hidden under the door pad";//�D�ئr��
    char key[SIZE] = "GUIDANCE";//�D��key

    cout << "Key : " << key << endl;
    cout << "���� : " << str << endl;

    //Playfair Cipher
    encryptByPlayfairCipher(str, key);
    cout << "�K�� : " << str << "\n";

    return 0;
}