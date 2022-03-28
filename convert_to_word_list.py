import sys
import os

original_file = sys.argv[1]
new_file_name = sys.argv[2]

print("Working...")

of = open(original_file, "r")
nf = open(new_file_name, "w")

ofc = of.read()
ofs = []
index = 0
cw = ""

for x in ofc:
    if x != ' ' and x != '\n':
        if x.isalpha():
            cw = cw + x
    else:
        if cw != "":
            ofs.append(cw)
            cw = ""

print("Original file word count: " + str(len(ofs)))

nfs = []

for x in ofs:
    word = x.lower()
    if word not in nfs:
        nfs.append(word)

print("New file word count: " + str(len(nfs)))
print("Saving...")

nfs.sort(key = len)

stringtowrite = ""
for x in nfs:
    stringtowrite = stringtowrite + x + "\n"

nf.write(stringtowrite)

print("Done!")

of.close()
nf.close()
