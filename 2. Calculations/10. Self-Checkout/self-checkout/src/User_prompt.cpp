#include "User_prompt.h"

std::stringstream& UserInput::promptUser(std::string prompt) {
	outputStream << prompt;
	getValidatedUserInput();
	return validatedInput;
}

void UserInput::getValidatedUserInput() {
	std::string strInput = "";
	do {
		std::getline(inputStream, strInput);
		try {
			inputValidator.ValidateInput(strInput);
			break;
		}
		catch (std::runtime_error& err) {
			outputStream << err.what();
		}
		break;
	} while (true);
	validatedInput << strInput;
};