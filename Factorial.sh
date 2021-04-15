fact=1
echo "Enter any number to get it's factorial"
read num
res=1
while [ $num -ne 1 ]
do
	res=`expr $res \* $num`
	num=`expr $num - 1`
done
echo "Factorial is" $res