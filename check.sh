flag_diff=$1
cd cmake-build-debug/ || exit
make
./ft_printf_git2.0 > 0.txt
./one_to_two 0.txt 1.txt 2.txt
clear
printf "\n==================================================================================================\n"
printf "\t   Original\t\t  ||||||||||||||||||||||||||||||\t\tMy"
printf "\n==================================================================================================\n\n"
#diff -y 2.txt 1.txt
diff $flag_diff 2.txt 1.txt
printf "\n\n"