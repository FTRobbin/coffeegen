train=${1:-10}
val=${2:-0}
eval=${3:-1}
let "all=train+val+eval"
echo all $all
echo train $train val $val eval $eval
echo cleaning up
./dataset/clean.sh $all
echo generating CoffeeScript
./generator/massgen $all
echo compiling to JavaScript
./dataset/masscompileall.sh $all
echo merging scripts
rm -f processed/*.txt
./processed/massmerge $train $val $eval
echo finished
#find dataset/ -name '*.coffee' -exec rm {} +
#rm -f dataset/*.js
