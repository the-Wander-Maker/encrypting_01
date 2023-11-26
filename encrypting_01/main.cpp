#include <iostream>
#include "Encryption.h"
#include <fstream>
#include <windows.h>
#pragma execution_character_set( "utf-8" )



int main(){

	SetConsoleOutputCP(65001);
	std::cout << "///////////////////////////////////Encrypting_Beta_0.1///////////////////////////////////////\n\n"
			  << "The program takes an input message, encrypts it with a unique key, and then resets it." << std::endl;
	std::cout << "It can manage software on the fly:\n"
			  << "		1. Covered at the bottom of the application.\n"
			  << "		2. Scanned from a file and the result sent there." << std::endl << std::endl;;
	std::cout << "_____________________________________________________________________________________________\n" <<std::endl;
	std::cout << "Choose one of the menu items below: \n"
			  << "		A: Use of typed text from keyboard................B: Use text readed from a file.\n"
			  << "Press A or B, then enter." << std::endl;
	

	char menupont;
	
	std::string inputtemp;
	std::cin >> menupont;
	getline(std::cin, inputtemp); //it takes out the new line and the input "a", which causes it to get stuck if it's not there.
	std::cout << std::endl;

	if (menupont == 'A' || menupont == 'a'){
		EncryptionHandler encrypting01(std::cin,true);

		encrypting01.inputtext();
		encrypting01.encryption_process();
		encrypting01.decryption_process();
	}
	else {
		const std::string filename = "input.txt";
		std::ifstream inputFile(filename);
		if (!inputFile.is_open()) {
			throw std::runtime_error("Error: input.txt file cannot be opened");
		}
		EncryptionHandler encrypting01(inputFile, false);

		encrypting01.inputtext();
		inputFile.close();
		encrypting01.encryption_process();
		encrypting01.decryption_process();
		
		std::string isPrintOut;
		std::cout << "Want to extract the encrypted text to encrypted_output.txt? Yes/I...No/N" << std::endl;
		std::cin >> isPrintOut;

		if (isPrintOut == "Yes" || isPrintOut == "Y" || isPrintOut == "yes" || isPrintOut == "y"){
			std::ofstream file("encrypted_output.txt");
			encrypting01.printToFile(file);
			file.close();
		}
	}
	system("pause");
}