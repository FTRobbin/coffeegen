train=${1:-900}
val=${2:-0}
eval=${3:-100}
let "all=train+val+eval"
echo all $all
echo train $train val $val eval $eval
echo cleaning up
rm -f dataset/*.coffee
rm -f dataset/*.js
echo generating CoffeeScript
./generator/gen $all
echo compiling to JavaScript
./dataset/compileall.sh $all
echo merging scripts
./processed/merge $train $val $eval
echo finished
