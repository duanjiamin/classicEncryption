#ifndef hill_
#define hill_
#include<string>
class hill
{
public:
	int key[2][2];
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
