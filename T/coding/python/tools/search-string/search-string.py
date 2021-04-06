from sys import argv
import os

print ("Script Name        : ", argv[0])
print ("File to be splitted: ", argv[1])

# Store all keywords.
keywords = []
reverse_match = False
for i in range(2, len(argv)):
    if argv[i] == '-r':
        reverse_match = True
    else:
        keywords.append(argv[i])

for i in range(0, len(keywords)):
    print ("keyword %s          :  %s" %(i+1, keywords[i]))

# Genarate output file name by 'input_filename' and 'keywords'.
input_filename = argv[1]
output_filename = argv[1]
for i in range(0, len(keywords)):
    output_filename = output_filename + "-" + keywords[i].replace(':','')

print ("output filename %s" %output_filename)

def matchLine(line):
    if reverse_match:
        for keyword in keywords:
            if keyword in line:
                return False
        return True
    else:
        for keyword in keywords:
            if keyword in line:
                return True
        return False

# Search file.
def searchFile(inputFile, outputFile):
    with open(inputFile) as input_content:
        for line in input_content:
            if matchLine(line):
                print (line)
                outputFile.write(line)

def main():
    output_fp = open(output_filename, 'w')

    if os.path.isfile(input_filename):
        searchFile(input_filename,output_fp)
    elif os.path.isdir(input_filename):
        for filename in os.listdir(input_filename):
            f = os.path.join(input_filename, filename)
            searchFile(f,output_fp)

    output_fp.close()

main()
