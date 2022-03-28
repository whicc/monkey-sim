#include<thread>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

void monkey(int kp, std::vector<std::string> words, int mn, int spec, char* letters) {

	std::string output = "";
	char input;
	char timestr[26];
	std::ofstream logfile;
	//std::vector<std::string> matchedWords;
	//int longestWord = 0;
	//int avg = 0;
	std::string lfname = std::to_string(mn) + ".mnklog";

	logfile.open(lfname);

	//char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};

	srand(mn);

	if (kp > 0) {

		//std::cout << "Typing " << kp << " characters." << std::endl;

		for (int i = 0; i < kp; i++) {

			logfile << "T" << std::to_string(i + 1) << std::endl;

			input = letters[(rand() % 27)];
			//input = letters[3];

			logfile << input << std::endl;

			if (input == ' ') {

				if (output != "") {

					if (mn == spec) std::cout << output << std::endl;

					for (int x = 0; x < words.size(); x++) {

						if (output == words[x]) {

							std::cout << std::endl << "MATCH FOUND!" << std::endl << "Monkey number " << mn << " typed " << output << std::endl << std::endl;
							//std::cout << "Monkey number " << mn << " typed " << output << std::endl << std::endl;

							logfile << "w: " << output << std::endl;
							//matchedWords.push_back(output);
							//logfile << "Words found so far: " << matchedWords.size() << std::endl;

							//if (output.size() > matchedWords[longestWord].size()) longestWord = (matchedWords.size() - 1);

							//for (int y = 0; y < matchedWords.size(); y++) avg += matchedWords[y].size();
							//avg /= matchedWords.size();

							//logfile << "Longest word found so far: " << matchedWords[longestWord] << std::endl;
							//logfile << "Average word length: " << avg << std::endl;
							//avg = 0;
						}
					}

					output = "";
				}
			}
			else {

				output += input;
			}
		}
	}
	else {

		//std::cout << "Typing indefinitely." << std::endl;

		int tics = 0;

		while (true) {

			logfile << "T" << std::to_string(tics) << std::endl;

			input = letters[(rand() % 27)];
			//input = letters[3];

			logfile << input << std::endl;

			if (input == ' ') {

				if (output != "") {

					if (mn == spec) std::cout << output << std::endl;

					for (int x = 0; x < words.size(); x++) {

						if (output == words[x]) {

							std::cout << std::endl << "MATCH FOUND!" << std::endl << "Monkey number " << mn << " typed " << output << std::endl << std::endl;
							//std::cout << "Monkey number " << mn << " typed " << output << std::endl << std::endl;

							logfile << "w: " << output << std::endl;
							//matchedWords.push_back(output);
							//logfile << "Words found so far: " << matchedWords.size() << std::endl;

							//if (output.size() > matchedWords[longestWord].size()) longestWord = (matchedWords.size() - 1);

							//for (int y = 0; y < matchedWords.size(); y++) avg += matchedWords[y].size();
							//avg /= matchedWords.size();

							//logfile << "Longest word found so far: " << matchedWords[longestWord] << std::endl;
							//logfile << "Average word length: " << avg << std::endl;
							//avg = 0;
						}
					}

					output = "";
				}
			}
			else {

				output += input;
			}
		}
	}

	logfile.close();
}

int main() {

	int kp;
	int spec;
	std::ifstream wordsfile;
	std::vector<std::string> words;
	std::string line;
	char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ' };

	wordsfile.open("./words.txt");

	while (wordsfile) {

		std::getline(wordsfile, line);
		words.push_back(line);
	}

	std::cout << words.size() << " words loaded." << std::endl;
	std::cout << "Enter amount of keypresses per monkey (Enter 0 to continue until told to stop): ";
	std::cin >> kp;
	std::cout << "What monkey do you spectate (0 to not spectate): ";
	std::cin >> spec;
	std::cout << "Simulating monkeys..." << std::endl;

	std::thread monkey1(monkey, kp, words, 1, spec, letters);
	std::thread monkey2(monkey, kp, words, 2, spec, letters);
	std::thread monkey3(monkey, kp, words, 3, spec, letters);
	std::thread monkey4(monkey, kp, words, 4, spec, letters);

	monkey1.join();
	monkey2.join();
	monkey3.join();
	monkey4.join();

	std::cout << "Done!" << std::endl;

	system("PAUSE");

	return 0;
}