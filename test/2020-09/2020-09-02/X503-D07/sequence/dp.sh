i=0
while true; do
	./gen
	./sequence
	./bf
    i=$(($i+1))
	if diff sequence.out sequence1.out ;then
		echo $i "AC ~ HAHAHA ~"
	else
		echo $i "WA ~ WA ~"
		exit 0
	fi
done
