#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 50

void toLowerCase(char plain[], int ps) // 糶锣糶
{
    int i;
    for (i = 0; i < ps; i++) {
        if (plain[i] > 64 && plain[i] < 91)
            plain[i] += 32;
    }
}

int removeSpaces(char* plain, int ps) // 簿埃
{
    int i, count = 0;
    for (i = 0; i < ps; i++)
        if (plain[i] != ' ')
            plain[count++] = plain[i];
    plain[count] = '\0';
    return count;
}

void generateKeyTable(char key[], int ks, char keyT[5][5]) // ネΘ5*5痻皚
{
    int i, j, k, flag = 0;
   
    int dicty[26] = { 0 };  // 家计26
                            // 纗ダ璸计
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

void search(char keyT[5][5], char a, char b, int arr[]) //芲痻皚い穓じ肚ウ竚
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

int mod5(int a) { return (a % 5); } // 5*5痻皚(mod 5)

int prepare(char str[], int ptrs) // 琵ゅじ计案计
{
    if (ptrs % 2 != 0) {
        str[ptrs++] = 'z';//ダ丁安ダ跋筳ㄏゅ计案计
        str[ptrs] = '\0';
    }
    return ptrs;
}

void encrypt(char str[], char keyT[5][5], int ps) // 盞
{
    int i, a[4];

    for (i = 0; i < ps; i += 2) {

        search(keyT, str[i], str[i + 1], a); //芲痻皚い穓じ肚ウ竚

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
    ks = removeSpaces(key, ks);//簿埃
    toLowerCase(key, ks);//糶锣糶

    //ゅ
    ps = strlen(str);//﹃
    toLowerCase(str, ps);//糶锣糶
    ps = removeSpaces(str, ps);//簿埃

    ps = prepare(str, ps);//ㄏ计案计

    generateKeyTable(key, ks, keyT);//5*5痻皚

    encrypt(str, keyT, ps);//盞
}

int main()
{
    char str[SIZE] = "the key is hidden under the door pad";//肈ヘ﹃
    char key[SIZE] = "GUIDANCE";//肈ヘkey

    cout << "Key : " << key << endl;
    cout << "ゅ : " << str << endl;

    //Playfair Cipher
    encryptByPlayfairCipher(str, key);
    cout << "盞ゅ : " << str << "\n";

    return 0;
}