#ifndef caesar_
#define caesar_
#include<string>
class caesar
{
public:
	int key;
	std::string cipher;
	std::string plain;

public:	
	//classic(){};
	//~classic(){};
	//void makekey(std::string temp_key);
	void encrypt(std::string plaintext);
	void decrypt(std::string ciphertext);
};

#endif

