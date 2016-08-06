#ifndef playfair_
#define playfair_
#include<string>

class playfair
{
public:
	char key[5][5];
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
