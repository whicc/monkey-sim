# monkey sim

This is a very simple take on the infinite monkeys theorem.

The two python scripts are for working with data before running the simulation, and after. 

convert_to_word_list.py takes two arguments, so it would be run like:
python convert_to_word_list.py (the txt file of the words to search for) (the txt file you want to export the list to)
Once run it will make a list of every unique word in the first file, the put that list into the second file.

monkey_visualizer.py also takes in two arguments, so it would be run like:
python monkey_visualizer.py (the log to visualize) (the name you want it to be saved as)
Once run it will search through the log file for key information, then make it into a form more understandable by humans. Right now it is somewhat limited, but is a work in progress.
