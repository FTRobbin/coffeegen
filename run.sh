rm dataset/*.coffee
rm dataset/*.js
./generator/gen 9
./dataset/compileall.sh
