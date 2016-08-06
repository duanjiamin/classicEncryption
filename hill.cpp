#include<string>
#include<iostream>
#include"hill.h"

using namespace std;

void hill::makekey(string temp_key)
{
    //string temp_key="";
    //cout<<"输入四位字母作为秘钥:"<<endl;//dgch等
    //cin>>temp_key;
	int count=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		{
			if(temp_key[count]>'A'&&temp_key[count]<'Z')
				key[i][j]=temp_key[count]-'A';
			else key[i][j]=temp_key[count]-'a';
			count++;
		}
	//if(key[0][0]*key[1][1]-key[0][1]*key[1][0])
}

void hill::encrypt(string plaintext)
{
	if(plaintext.length()%2==1)
		plaintext+='x';
	string ciphertext="";
	string temp="";
	for(int i=0;i<plaintext.length()-1;i+=2)
	{
		int chr1=plaintext[i]-'a';//cout<<chr1<<endl;
		int chr2=plaintext[i+1]-'a';//cout<<chr2<<endl;
		//string temp;		
		temp=char((chr1*key[0][0]+chr2*key[0][1])%26+'a');//cout<<chr1<<key[0][0]<<chr2<<key[0][1]<<endl;
		ciphertext+=temp;
		temp=char((chr1*key[1][0]+chr2*key[1][1])%26+'a');//cout<<chr1<<key[1][0]<<chr2<<key[1][1]<<endl;
		ciphertext+=temp;
	}
	cipher=ciphertext;
}

void hill::decrypt(string ciphertext)
{
	int nkey[2][2];
	nkey[0][0]=key[1][1];
	nkey[0][1]=0-key[0][1];
	nkey[1][0]=0-key[1][0];
	nkey[1][1]=key[0][0];
	
	int temp_det=key[0][0]*key[1][1]-key[0][1]*key[1][0];
	int det=1;
	for(;det<26;det++)
	{
		if((temp_det*det-1)%26==0)
			break;
	}
	//cout<<det<<endl;
	for(int i=0;i<2;i++)
	{	
		for(int j=0;j<2;j++)
		{
			nkey[i][j]=(nkey[i][j]*det)%26;
	//		cout<<nkey[i][j];
		}
	//cout<<endl;	
	}
	for(int i=0;i<2;i++)
	{	
		for(int j=0;j<2;j++)
		{
			while(nkey[i][j]<0)
				nkey[i][j]+=26;
	//		cout<<nkey[i][j];
		}
	//cout<<endl;	
	}
	string plaintext="";
	string temp="";
	for(int i=0;i<ciphertext.length()-1;i+=2)
	{
		int chr1=ciphertext[i]-'a';
		int chr2=ciphertext[i+1]-'a';
		//string temp;		
		temp=char((chr1*nkey[0][0]+chr2*nkey[0][1])%26+'a');
		plaintext+=temp;
		temp=char((chr1*nkey[1][0]+chr2*nkey[1][1])%26+'a');
		plaintext+=temp;
	}
	plain=plaintext;
}












