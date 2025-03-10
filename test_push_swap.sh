#!/bin/bash

# Test sayısı, istediğiniz kadar test yapmak için bu değeri değiştirebilirsiniz
NUM_TESTS=10

# Push_swap programı ve checker için path'ler (ihtiyaç duyulursa değiştirebilirsiniz)
PUSH_SWAP="./push_swap"
CHECKER="./checker"
CH="./ch"

# Rastgele sayılarla test etmek için bir fonksiyon
generate_random_input() {
    # Burada istediğiniz sayıda rastgele sayı oluşturabilirsiniz. Örneğin 10 adet rastgele sayı:
    local NUMBERS=$(shuf -i 0-30000 -n 500 | tr '\n' ' ')  # Burada 1-100 arası 10 rastgele sayı oluşturuluyor
    #local NUMBERS="26 -25 -45 20 -4 25 44 9 38 -31 -17 41 -39 40 31 48 10 -33 -32 -40 -36 -22 19 -23 23 29 12 -20 -46 -13 7 6 -27 -50 -49 -41 30 46 -34 28 -16 50 -7 3 -11 8 1 -8 -3 5 -35 -24 36 22 14 -19 21 15 -18 11 -21 17 35 45 -10 39 47 -14 27 43 32 -12 -1 -9 -15 -42 42 -48 -37 -47 2 49 24 -26 34 -5 -29 -44 18 13 16 0 4 -2 -43 -30 -38 -28 -6 33"
    echo $NUMBERS
}

# Testleri başlatan fonksiyon
run_tests() {
    for ((i=0; i<NUM_TESTS; i++))
    do
        # Rastgele girdi oluştur
        A=$(generate_random_input)
        
        # Test adımlarını çalıştır
        echo "Running test $((i+1))"
        $PUSH_SWAP $A  | $CH $A && $PUSH_SWAP $A | wc -l
        echo "---------------------------------------------------"
    done
}

# Script'i başlat
run_tests
