all=$1
i=1
for f in dataset/*/
do
	coffee -cb --no-header $f
	echo compiled $i / $all
	let "i=$i+1"
done
