#ifndef ENCRYPTING_01_STRING_HEADER
#define ENCRYPTING_01_STRING_HEADER

#include <vector>
#include <string>
#include <istream>
#include <ostream>

/*
The class contains the member variables and functions required for encryption.

	EncryptionHandler(std::istream&, const bool);			Constructor of the class.

	std::string encrypt(const std::string& input);			Does the encryption itself. Shift the input letters +5 chars away from the original.
	
	void inputtext();										Read the input and also stores in in textinputs vector.
	
	void encryption_process();								Calls the encrypt() function on the whole text stored in the textinputs vector.
	
	void decryption_process();								Reverse the process and gives back the original text.
	
	void printToFile(std::ofstream& outStream);				Simply write the encrypted data into a file.

	std::vector<std::string> textinputs;					Vector for storeing the input text.

	std::vector<std::string> encrypteddata;					The encrypted data storage.

	std::vector<std::string> decryptedtext;					The decrypted data storage.

	std::istream& inputstream;								Used for read in the data.

	bool readable;											Used to check if the data is corrupted or not.
*/

class EncryptionHandler{
public:
	EncryptionHandler(std::istream&, const bool);

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