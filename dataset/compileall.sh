for f in dataset/*.coffee
do
	#echo $f
	coffee -cb --no-header $f
done
