# run this from the root directory of the project
cat chimie.cpp > utilities/totalcode.txt
cd chimie
cat define.cpp >> ../utilities/totalcode.txt
cat define.h >> ../utilities/totalcode.txt
cat ../utilities/countLines.sh >> ../utilities/totalcode.txt
cd ..
cd encoder
cat encoder.cpp >> ../utilities/totalcode.txt
cat encoder.h >> ../utilities/totalcode.txt
cd ..
cd utilities
cat totalcode.txt | wc -l 