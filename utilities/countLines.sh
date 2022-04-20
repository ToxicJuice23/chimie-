cd /home/runner/Chimie-CLI
cat chimie.cpp > /home/runner/Chimie-CLI/utilities/totalcode.txt
cd chimie
cat define.cpp >> /home/runner/Chimie-CLI/utilities/totalcode.txt
cat define.h >> /home/runner/Chimie-CLI/utilities/totalcode.txt
cat /home/runner/Chimie-CLI/utilities/countLines.sh >> /home/runner/Chimie-CLI/utilities/totalcode.txt
cd ..
cd utilities
cat totalcode.txt | wc -l 