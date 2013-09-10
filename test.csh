#!/bin/tcsh
gcc -I. -g -DDEBUG main.c -o divide.o || exit 1
rm test.log
rm test.dif > /dev/null
foreach x ( pruebas/* )
echo "======= BEGIN $x ========" >> test.log
./divide.o < $x >> test.log
echo "======= FINISH $x ========" >> test.log
end
diff test.log test.cmp > test.dif

