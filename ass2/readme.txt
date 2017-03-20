Some tests for assignment 1
---------------------------
There are 3 input files: input, input2 & input3.

The following are the commands used to generate the output files
under Linux.  (It assumes that the program can be invoked as ./trans)

# both sets of the same size (-e should have no effect)
./trans abc xyz < input > my-out01
./trans ab bc < input > my-out02
./trans abaca vwxyz < input > my-out03
./trans -e abaca vwxyz < input > my-out04

# 2nd set is larger (-e should have no effect)
./trans aei vwxyz < input > my-out05
./trans -e aei vwxyz < input > my-out06

# 1st set is larger
./trans abcdef xyz < input > my-out07
./trans abacaba vwxyz < input > my-out08
./trans -e abcdef xyz < input > my-out09
./trans -e abacaba vwxyz < input > my-out10

# with escape characters:
./trans '\n' x < input > my-out11
./trans 'a\nc' xyz < input > my-out12
./trans 'a\t\nc' wxyz < input > my-out13
./trans '\\n' ab < input2 > my-out14
./trans ei 'x\n' < input2 > my-out15
./trans '\tu' 'x\n' < input2 > my-out16

# with ranges:
./trans a-z A-Z < input > my-out17
./trans A-Z a-z < input > my-out18
./trans a-e xyz < input > my-out19
./trans -e a-e xyz < input > my-out20

Notes:
- All input & output files are in Unix format
- The single quotes around arguments that use escape characters may or may
  not be necessary in cygwin
- The given tests are not exhaustive.  In particular, there are no tests
  that use both escape characters & ranges.
- You may be able to use the runtests script to run the tests.  This has
  only been tested on Linux but may work in the cygwin bash shell as well.
  You need to name your executable trans.exe (in cygwin) or trans (in Linux) &
  put it in the same directory as the runtests script (with the input & output 
  files) & type: ./runtests

aw
