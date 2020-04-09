cd candy
git submodule init
git submodule update

cd candy-kingdom
git submodule init
git submodule update

cd ..
cmake -S . -B build
cmake --build build --target assumptionTest
