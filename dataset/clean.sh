rm -rf dataset/*/
all=$1
i=1

until [ $i -gt  $all ]
do
	mkdir dataset/$i
	let "i=$i+1"
done
