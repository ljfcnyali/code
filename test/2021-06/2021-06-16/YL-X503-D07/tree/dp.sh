i=0
while true; do
	./gen
	./tree
	./bf
    i=$(($i+1))
	if diff tree.out tree1.out ;then
		echo $i "AC ~ HAHAHA ~"
	else
		echo $i "WA ~ WA ~"
		exit 0
	fi
done
