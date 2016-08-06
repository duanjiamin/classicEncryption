#include<iostream>
#include<string>
#include"playfair.h"
using namespace std;

void playfair::makekey(string temp_key)
{
    //string temp_key;
    //cout<<"input the key"<<endl;
    //cin>>temp_key;
	int length=temp_key.length();
	string keystr="";
	for(int i=0;i<length;i++)
	{
		int flag=0;
		for(int j=0;j<keystr.length();j++)
		{
			if(temp_key[i]==keystr[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)keystr+=temp_key[i];
	}
	char key_array[5][5];
	string str="abcdefghijklmnopqrstuvwxyz";
	length=keystr.length();
	for(int i=0;i<length;i++)
	{
		
		for(int j=0;j<str.length();j++)
			{
				if(str[j]==keystr[i])
				{
					for(int k=j;k<str.length();k++)
						str[k]=str[k+1];
					break;
				}
			}
	}
	string newkey=keystr+str.substr(0,26-keystr.length()-1);  //-1去掉Z
	int count=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		key_array[i][j]=newkey[count++];
	}
	//cout<<"密码表为:"<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			key[i][j]=key_array[i][j]; 
		//cout<<endl;
	}
	//key=key_array;
}

void playfair::encrypt(string plaintext)
{
    string temp="";
        string::iterator it;
        for(it=plaintext.begin();it<plaintext.end()-1;it++)
        {
            if(*it==*(it+1)) temp=temp+*it+'x';
                //str.insert(it+1,'x');
            else temp+=*it;
        }
        temp+=*it;
        plaintext=temp;
    /*for(string::iterator it=plaintext.begin();it<plaintext.end();it++)
	{
		if(*it==*(it+1))
			plaintext.insert(it+1,'x');
    }*/
	if(plaintext.length()%2==1)
		plaintext+='x';
	int length=plaintext.length();
	string ciphertext="";
	for(int i=0;i<length-1;i+=2)
	{
		int row1,row2,col1,col2;
		char chr1=plaintext[i];
		char chr2=plaintext[i+1];
		for(int j=0;j<5;j++)
			for(int k=0;k<5;k++)
			{
				if(key[j][k]==chr1)
				{
					row1=j;
					col1=k;
				}
				else if(key[j][k]==chr2)
				{
					row2=j;
					col2=k;
				}

			}
		//cout<<row1<<col1<<row2<<col2<<endl;
		if(row1==row2)
		{
			//string temp=key_array[row1][(col1+1)%5]+key_array[row1][(col2+1)%5];
			ciphertext+=key[row1][(col1+1)%5];
			ciphertext+=key[row1][(col2+1)%5];
		}
		else if(col1==col2)
		{
			//string temp=key_array[(row1+1)%5][col1]+key_array[(row1+1)%5][col1];
			ciphertext+=key[(row1+1)%5][col1];				
			ciphertext+=key[(row2+1)%5][col1];		
		}
		else
		{
			//string temp=key_array[row1][col2]+key_array[row2][col1];
			ciphertext+=key[row1][col2];
			ciphertext+=key[row2][col1];
		}

	}
	//cout<<"密文为："<<endl;
	//cout<<ciphertext<<endl;
	cipher=ciphertext;
}

void playfair::decrypt(string ciphertext)
{
	string newptext="";
	int length=ciphertext.length();
	for(int i=0;i<length-1;i+=2)
	{
		int row1,row2,col1,col2;
		char chr1=ciphertext[i];
		char chr2=ciphertext[i+1];
		for(int j=0;j<5;j++)
			for(int k=0;k<5;k++)
			{
				if(key[j][k]==chr1)
				{
					row1=j;
					col1=k;
				}
				else if(key[j][k]==chr2)
				{
					row2=j;
					col2=k;
				}

			}
		//cout<<row1<<col1<<row2<<col2<<endl;
		if(row1==row2)
		{
			//string temp=key_array[row1][(col1+1)%5]+key_array[row1][(col2+1)%5];
            newptext+=key[row1][(col1+4)%5];
            newptext+=key[row1][(col2+4)%5];
		}
		else if(col1==col2)
		{
			//string temp=key_array[(row1+1)%5][col1]+key_array[(row1+1)%5][col1];
            newptext+=key[(row1+4)%5][col1];
            newptext+=key[(row2+4)%5][col1];
		}
		else
		{
			//string temp=key_array[row1][col2]+key_array[row2][col1];
			newptext+=key[row1][col2];
			newptext+=key[row2][col1];
		}

	}
	//cout<<"解密结果为："<<endl;
	//cout<<newptext<<endl;
	plain=newptext;
}





