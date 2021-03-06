train=${1:-1000}
val=${2:-0}
eval=${3:-100}
let "all=train+val+eval"
echo all $all
echo train $train val $val eval $eval
echo cleaning up
find dataset/ -name '*.coffee' -exec rm {} +
rm -f dataset/*.js
echo generating CoffeeScript
./generator/gen $all
echo compiling to JavaScript
./dataset/compileall.sh $all
echo merging scripts
rm -f processed/*.txt
./processed/merge $train $val $eval
echo finished
#find dataset/ -name '*.coffee' -exec rm {} +
#rm -f dataset/*.js
