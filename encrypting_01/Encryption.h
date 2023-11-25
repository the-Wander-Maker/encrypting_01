#ifndef ENCRYPTING_01_STRING_HEADER
#define ENCRYPTING_01_STRING_HEADER

#include <vector>
#include <string>
#include <istream>
#include <ostream>

/*
The class contains the member variables and functions required for encryption.

	StringIn(std::istream&, const bool);			It

	std::string encrypt(const std::string& input);
	void inputtext();
	void encryptionprocess();
	void decryptionprocess();
	void printToFile(std::ofstream& outStream);

	std::vector<std::string> textinputs;
	std::vector<std::string> encrypteddata;
	std::vector<std::string> decryptedtext;
	std::istream& inputstream;
	bool readable;
};

*/
class StringIn{
public:
	StringIn(std::istream&, const bool);

	std::string encrypt(const std::string& input);
	void inputtext();
	void encryption_process();
	void decryption_process();
	void printToFile(std::ofstream& outStream);
private:
	std::vector<std::string> textinputs;
	std::vector<std::string> encrypteddata;
	std::vector<std::string> decryptedtext;
	std::istream& inputstream;
	bool readable;
};

#endif