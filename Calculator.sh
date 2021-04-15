n=0
while [ $n -ne -1 ]
do
echo "MENU\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\nEnter any one option"
read op
case "$op" in
	1) echo "Enter first number"
	   read num1
	   echo "Enter second number"
	   read num2	 
	   res=`expr $num1 + $num2`
	   echo "Addition is" $res 
	   ;;
	2) echo "Enter first number"
	   read num1
	   echo "Enter second number"
	   read num2
	   res=`expr $num1 - $num2` 
	   echo "Difference is" $res 
	   ;;
	3) echo "Enter first number"
	   read num1
	   echo "Enter second number"
	   read num2
	   res=`expr $num1 \* $num2`
	   echo "Product is" $res 
	   ;;
	4) echo "Enter first number"
	   read num1
	   echo "Enter second number"
	   read num2
	   res=`expr $num1 / $num2`
	   res1=`expr $num1 % $num2`
	   echo "Quotient is" $res
	   echo "Remainder is" $res1 
	   ;;
	5) n=-1
	   ;;
esac
echo "\n"
done