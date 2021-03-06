# ???? Sudoku Olu??turucu ve ??繹z羹c羹

## Sudoku Olu??turucu ve ??繹z羹c羹

Bu program, kullan覺c覺dan bir zorluk seviyesi ister, verilen seviyeyi kullanarak bir sudoku tahtas覺 olu??turur ve olu??turulan tahtay覺 癟繹zer.

Di??er bir癟ok sudoku 癟繹z羹c羹 program覺 gibi benimki de 'Geri 襤zleme' s羹recini kullan覺yor ve bu s羹re癟 olduk癟a derin yinelemeli 癟a??r覺lardan olu??uyor, bu nedenle s羹recin zihinde g繹rselle??tirilmesi kolay de??il.

Nesil k覺sm覺 ayr覺ca 癟繹z羹c羹 k覺sm覺n覺 da kullan覺r. 襤??te olu??turma ad覺mlar覺:

1. ??apraz 3 alt 覺zgaray覺 uygun ??ekilde rastgele rakamlarla doldurun \(ayn覺 rakam覺 iki kez kullanmadan\).
2. Yar覺s覺 olu??turulmu?? panoyu 癟繹z羹n.
3. Rastgele say覺lar覺 kald覺rmaya 癟al覺??覺n ve ortaya 癟覺kan kart覺n kald覺r覺lan numarayla de??i??medi??inden emin olun.

??繹zme ad覺mlar覺:

1. Verilen sat覺r ve s羹tunun bo?? olup olmad覺??覺n覺 kontrol edin, 繹yleyse bir rakam deneyin.
2. Bir de??er verilen sat覺r ve s羹tuna ayarlanm覺??sa, ayn覺 sat覺rdaki sonraki say覺ya gidin. Sat覺r bittiyse, sonraki sat覺ra git.
3. 襤lk ile ba??layan her sat覺r i癟in 1. ve 2. yapmaya 癟al覺??覺n.
4. Son sat覺r ve s羹tuna ula??t覺??覺n覺zda, panoyu doldurmu??sunuz demektir.
5. Yukar覺daki ad覺mlardaki herhangi bir sorun, daha 繹nce denenen numaralardan birinin sorunlu oldu??u anlam覺na gelir. ??yleyse buna geri d繹n羹n, ba??ka bir ??eyle de??i??tirin ve ayn覺 ad覺mlar覺 tekrar deneyin.

### ??rnek ??覺kt覺

<p align="center">
  <img src="https://user-images.githubusercontent.com/51864516/116006777-655c3d80-a615-11eb-9eb1-a59b271c2a70.png">
</p>

* Program, kullan覺c覺n覺n panoyu 癟繹zmeye 癟al覺??mas覺na izin vermez. Bu 繹zellik bir aray羹zden sonra gelebilir.

## Sudoku Generator & Solver

This program asks the user for a difficulty level, generates a sudoku board using given level and solves the generated board.

Like many other sudoku solver programs, mine does use 'Backtracking' process too and this process consist quite deep recursive calls, so visualization of the process in the mind is not easy.

Generation part also utilizes solver part. Here is the generation steps:

1. Fill the diagonal 3 subgrids with random digits accordingly \(without using same digit twice\).
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
  <img src="https://user-images.githubusercontent.com/51864516/116006777-655c3d80-a615-11eb-9eb1-a59b271c2a70.png">
</p>

* Program does not allow user to try to solve the board. This feature might come after an interface.

