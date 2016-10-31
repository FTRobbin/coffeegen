coffee -cb --no-header .
: '
all=$1
i=1
for f in dataset/*.coffee
do
	coffee -cb --no-header $f
	let "r = $i % 100"
	if [ "$r" -eq 0 ]
	then
		echo compiled $i / $all
	fi
	let "i=$i+1"
done
'
