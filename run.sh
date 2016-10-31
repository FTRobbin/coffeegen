rm dataset/*.coffee
rm dataset/*.js
./generator/gen 10
./dataset/compileall.sh
./processed/merge 7 1 2
