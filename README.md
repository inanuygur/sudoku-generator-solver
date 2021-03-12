# Sudoku Generator & Solver

This program asks the user for a difficulty level, generates a sudoku board using given level and solves the generated board.

Like many other sudoku solver programs, mine does use 'Backtracking' process too and this process consist quite deep recursive calls, so visualization of the process in the mind is not easy. 

Generation part also utilizes solver part. Here is the generation steps:
1. Fill the diagonal 3 subgrids with random digits accordingly (without using same digit twice).
2. Solve the half created board.
3. Try to remove random numbers and make sure the resulting board doesn't change with removed number.

Solving steps: 
1. Check if given row and column is empty, if so, try a digit. 
2. If a value is set to given row and column, go next number in the same row. If row is ended, go next row.
3. Try to do 1. and 2. for every row beginning with first.
4. Once you acheive last row and column, it means you filled the board. 
5. Any problem in above steps means that one of the previously tried numbers are problematic. So go back to that, change it to something else and try same steps again.

### Example Output
<p align="center">
<img src="https://i.hizliresim.com/7VWOny.png">
</p>

---------------
* Program does not allow user to try to solve the board. This feature might come after an interface.
