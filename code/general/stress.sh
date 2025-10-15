g++ -std=c++17 -O2 -o sol sol.cpp
g++ -std=c++17 -O2 -o brute brute.cpp
g++ -std=c++17 -O2 -o gen gen.cpp

for ((i = 1; ; i++)); do
    ./gen $i > in.txt
    ./sol < in.txt > out1.txt
    ./brute < in.txt > out2.txt

    if ! diff -q out1.txt out2.txt > /dev/null; then
        echo "Mismatch found on test $i"
        cat in.txt
        echo "Your output:"
        cat out1.txt
        echo "Brute output:"
        cat out2.txt
        break
    fi
    echo "Test $i passed"
done
