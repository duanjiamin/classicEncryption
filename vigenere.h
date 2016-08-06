#ifndef vigenere_
#define vigenere_
#include<string>

class vigenere
{
public:
	std::string key;
	std::string cipher;
	std::string plain;

public:	
	//classic(){};
	//~classic(){};
    void makekey(std::string temp_key);
	void encrypt(std::string plaintext);
	void decrypt(std::string ciphertext);
};
#endif
