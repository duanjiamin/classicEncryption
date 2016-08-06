#include<string>
#include<iostream>
#include"vigenere.h"
using namespace std;


void vigenere::makekey(string temp_key)
{
    key=temp_key;
}
void vigenere::encrypt(string plaintext)
{
	string ciphertext="";
	for(int i=0;i<plaintext.length();i++)
	{
		if(plaintext[i]>='A'&&plaintext[i]<='Z')
			plaintext[i]=plaintext[i]-'A'+'a';	
	}
	for(int i=0;i<plaintext.length();i++)
	{
		int index;
		if(i>=key.length())
		  index=(i%key.length());
		else index=i;
		int num=key[index]-'a';
		num=(plaintext[i]-'a'+num)%26;
		ciphertext+=char(97+num);	
	}
	cipher=ciphertext;
}
void vigenere::decrypt(string ciphertext)
{
	string plaintext="";
	for(int i=0;i<ciphertext.length();i++)
	{
		int index;
		if(i>=key.length())
		  index=(i%key.length());
		else index=i;
		int num=key[index]-'a';
		num=(ciphertext[i]-'a'-num)%26;
        while(num<0)num+=26;
		plaintext+=char(97+num);
	}
	plain=plaintext;
}
