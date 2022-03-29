#from PIL import Image, ImageDraw, ImageFont
import os
import os.path
import sys

print("Importing file...")
log_file = open(sys.argv[1], 'r')
log_file_data = log_file.read()
#print(log_file_data)
log_file.close()
print("Done.")

print("Parsing data...")
current_string = ""
ticstring = ""
parsed_data = {}
reading_mode = 0
for i in range(0, len(log_file_data)):
    #print(ticstring)
    #print(str(log_file_data[i]) + " " + str(reading_mode))

    if reading_mode == 0:
        if log_file_data[i] == 'T':
            #print("Tic label found")
            ticstring = ""
            reading_mode = 1
            continue

        if log_file_data[i] == ':' or log_file_data[i] == '-':
            if log_file_data[i] == ':':
                current_string = ""
                reading_mode = 2
                continue
            current_string = ""
            continue

        current_string += log_file_data[i]
    elif reading_mode == 1:
        current_string = ""
        if log_file_data[i] != '-':
            ticstring += log_file_data[i]
        else:
            reading_mode = 0
            continue
    elif reading_mode == 2:
        if log_file_data[i] == '-':
            parsed_data[ticstring] = current_string
            current_string = ""
            reading_mode = 0
            continue
        current_string += log_file_data[i]

    #print(str(log_file_data[i]) + " " + str(reading_mode) + " " + current_string)

print("Done.")

print("Generating summary...")

p = "./monkeylogs" + sys.argv[2]
direxists = os.path.isdir(p)
longestword = ""
favoriteword = ""
avg = 0
wordcounts = {}

if direxists == False:
    os.mkdir(p)

for i in parsed_data:
    if longestword == "":
        longestword = i
    if len(parsed_data[i]) > len(parsed_data[longestword]):
        longestword = i

    avg += len(parsed_data[i])
    if parsed_data[i] in wordcounts:
        wordcounts[parsed_data[i]] += 1
    else:
        wordcounts[parsed_data[i]] = 1

for i in wordcounts:
    if favoriteword == "":
        favoriteword = i
    if wordcounts[favoriteword] > wordcounts[i]:
        favoriteword = i

avg = avg / len(parsed_data)

summary_file = open(p + "/summary.txt", 'w')

summary_file.write("Total words typed: " + str(len(parsed_data)) + "\nLongest word found: " + parsed_data[longestword] + " at "  + str(len(parsed_data[longestword])) + " characters long.\nFavorite word was: " + favoriteword + " and was typed " + str(wordcounts[favoriteword]) + " times.\nAverage word length was: " + str(avg) + " characters long.")
summary_file.close()
print("Done.")
print("Once I get Pillow working or something graph generating happens here.")
