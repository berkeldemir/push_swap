#!/bin/bash

# Kullanım: ./test_script.sh [test_sayısı] [rastgele_sayı_adedi]

# Parametreleri al
NUM_TESTS=${1:-20}   # Varsayılan değer: 20 test
NUMBERS_COUNT=${2:-499}  # Varsayılan değer: 499 sayı

# Push_swap programı ve checker için path'ler
PUSH_SWAP="./push_swap"
CHECKER="./checker"
CH="./ch"

# Rastgele sayılarla test etmek için fonksiyon
generate_random_input() {
    local NUMBERS=$(shuf -i 0-30000 -n "$NUMBERS_COUNT" | tr '\n' ' ')
    echo $NUMBERS
}

# Testleri çalıştıran fonksiyon
run_tests() {
    for ((i=0; i<NUM_TESTS; i++))
    do
        # Rastgele girdi oluştur
        A=$(generate_random_input)
        
        # Test adımlarını çalıştır
        echo "Running test $((i+1)) with $NUMBERS_COUNT numbers"
        $PUSH_SWAP $A | $CH $A #&& valgrind $PUSH_SWAP $A | grep 'All heap blocks were freed' && \
        #valgrind $PUSH_SWAP $A | grep 'ERROR SUMMARY:' && $PUSH_SWAP $A | $CHECKER $A && $PUSH_SWAP $A | wc -l
        echo "------------------------"
    done
}

# Script'i başlat
run_tests
