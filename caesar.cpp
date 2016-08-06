#include<string>
#include"caesar.h"
using namespace std;

void caesar::encrypt(string plaintext)
{
	string newcipher="";
    for(int i=0;i<plaintext.length();i++)
	{
        newcipher+=(plaintext[i]-'a'+key)%26+'a';
	}
	cipher=newcipher;
}
void caesar::decrypt(string ciphertext)
{
	string newptext="";
	for(int i=0;i<ciphertext.length();i++)
	{
        newptext+=(ciphertext[i]-'a'-key)%26+'a';
	}
	plain=newptext;
}
