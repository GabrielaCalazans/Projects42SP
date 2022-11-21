# on your ft_printf folder:
# cd .. && cd ft_printf
cd ../../

# Tripouille/printfTester
git clone https://github.com/Tripouille/printfTester.git
cd printfTester
make a
# make m for mandatory tests only
# make b for bonus tests only
# make [category] = launch associated category ex: make s
# make [category] [test number] = launch associated test in category ex: make s 42

# paulo-santana/ft_printf_tester
cd ..
git clone https://github.com/paulo-santana/ft_printf_tester.git
cd ft_printf_tester
sh test
#sh test m: mandatory tests
#sh test b1: first bonus tests ('-0.' and widths)
#sh test b2: second bonus tests ('# +')
#sh test d: run only the mandatory tests related to the %d specifier. Currently, only the cspdiuxX% specifiers are supported
#sh test b1 c: run the b1 tests related to the %c specifier.
#sh test b2 X: run the b2 tests related to the %X specifier.
#sh test b1 b2: run all the bonus tests
#sh test 1088: run only the 1088th test
