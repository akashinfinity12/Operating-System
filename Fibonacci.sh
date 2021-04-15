echo "Enter the number of terms you want to display in fibonacci series"
read n
a=0
b=1
while [ $n -ne 0 ]
do
	echo $a
	c=`expr $a + $b`
	a=`expr $b + 0`
	b=`expr $c + 0`
	n=`expr $n - 1`
done