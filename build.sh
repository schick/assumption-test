cd candy
git submodule init
git submodule update

cd candy-kingdom
git submodule init
git submodule update

cd ..
cmake -S . -B build
cmake --build build --target assumptionTest

cd ../glucose
wget https://www.labri.fr/perso/lsimon/downloads/softwares/glucose-syrup-4.1.tgz
tar -xf glucose-syrup-4.1.tgz
rm glucose-syrup-4.1.tgz
find . -type f -name '._*' -delete
