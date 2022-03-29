#include<thread>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

void monkey(int kp, std::vector<std::string> words, int mn, char* letters) {

	std::string output = "";
	std::string lfname = std::to_string(mn) + ".mnklog";

	char input;
	char timestr[26];

	std::ofstream logfile;

	logfile.open(lfname);

	srand(mn); // TODO: This is not random.

	for (int i = 0; i < kp; i++) {

		logfile << "T" << std::to_string(i + 1) << '-';

		input = letters[(rand() % 27)]; // Grabs one of the letters from the letters list

		logfile << input << '-';

		if (input == ' ') { // Start word check

			if (output != "") { // Arranging the if statements like this means a word will never start with a space

				//if (mn == spec) std::cout << output << std::endl; // Output the word if monkey is spectated

				for (int x = 0; x < words.size(); x++) 
					if (output == words[x])
						logfile << "w:" << output << '-'; // A match has been found in the word list and this will be sent to the log
				
				output = ""; // Clear the monkeys current word
			}
		}
		else { // The monkey has not tried to start a new word, so add the letter to it's current word

			output += input;
		}
	}
	
	logfile.close(); // Excecution complete, close log file.
}

int main() {

	int kp;
	int spec;

	std::ifstream wordsfile;

	std::vector<std::string> words;

	std::string line;

	char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ' };

	wordsfile.open("./words.txt"); // Any file named this in the working directory will be used as the word list

	while (wordsfile) {

		std::getline(wordsfile, line);
		words.push_back(line);
	}

	wordsfile.close();

	std::cout << words.size() << " words loaded." << std::endl;
	std::cout << "Enter amount of keypresses per monkey: ";
	std::cin >> kp;
	//std::cout << "What monkey do you spectate (0 to not spectate): ";
	//std::cin >> spec;
	std::cout << "Simulating monkeys..." << std::endl;

	std::thread monkey1(monkey, kp, words, 1, letters); // Start a thread for each monkey
	std::thread monkey2(monkey, kp, words, 2, letters);
	std::thread monkey3(monkey, kp, words, 3, letters);
	std::thread monkey4(monkey, kp, words, 4, letters);
	std::thread monkey5(monkey, kp, words, 5, letters);

	monkey1.join(); // The threads have finished, close them
	monkey2.join();
	monkey3.join();
	monkey4.join();
	monkey5.join();

	std::cout << "Done!" << std::endl;

	system("PAUSE"); // This is so the window doesn't close the instant execution is complete

	return 0;
}