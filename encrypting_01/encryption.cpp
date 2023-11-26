#include "Encryption.h"
#include <iostream>
#include <string>
#include <fstream>



EncryptionHandler::EncryptionHandler(std::istream& in, const bool ifreadable) : inputstream(in), readable(ifreadable) {

}


std::string EncryptionHandler::encrypt(const std::string& input) {
	std::string encoded;
	for (const char input_chr : input) {
		encoded.push_back(input_chr + 5);
	}
	return encoded;
}


void EncryptionHandler::encryption_process(){
	std::cout << "The encrypted text: " << std::endl;

	for (const std::string& input_line : textinputs){
		encrypteddata.push_back(encrypt(input_line));
	}
	for (auto encrypted_output : encrypteddata){
		std::cout << encrypted_output << " " << std::endl;
	}
	std::cout << std::endl;
}


void EncryptionHandler::decryption_process(){
	std::cout << "The decrypted text: " << std::endl;

	for (const std::string& input_line : encrypteddata){
		std::string decrypted_line;
		for (const char output_chr : input_line) {
			decrypted_line.push_back(output_chr - 5);
		}
		decryptedtext.push_back(decrypted_line);
	}
	for (auto decrypted_output : decryptedtext){
		std::cout << decrypted_output << std::endl;
	}
	std::cout << std::endl;
}


void EncryptionHandler::inputtext(){
	if (readable){
		std::cout << "Enter the text you want to manage.\nPress /enter-key/ to enter the text.";
		std::cout << "\nIf you have uploaded all the nodes, please press /enter-key/ again to begin the encryption process: " << std::endl;
	}
	std::string inputtemp;
	getline(inputstream, inputtemp);
	while (!inputtemp.empty()){
		textinputs.push_back(inputtemp);
		getline(inputstream, inputtemp);
	}
	std::cout << std::endl;
}


void EncryptionHandler::printToFile(std::ofstream& outStream){
	for (std::string& line : encrypteddata) {
		outStream << line;
	}
}