# Sudoku Oluşturucu ve Çözücü

Bu program, kullanıcıdan bir zorluk seviyesi ister, verilen seviyeyi kullanarak bir sudoku tahtası oluşturur ve oluşturulan tahtayı çözer.

Diğer birçok sudoku çözücü programı gibi benimki de 'Geri İzleme' sürecini kullanıyor ve bu süreç oldukça derin yinelemeli çağrılardan oluşuyor, bu nedenle sürecin zihinde görselleştirilmesi kolay değil.

Nesil kısmı ayrıca çözücü kısmını da kullanır. İşte oluşturma adımları:

1. Çapraz 3 alt ızgarayı uygun şekilde rastgele rakamlarla doldurun (aynı rakamı iki kez kullanmadan).
2. Yarısı oluşturulmuş panoyu çözün.
3. Rastgele sayıları kaldırmaya çalışın ve ortaya çıkan kartın kaldırılan numarayla değişmediğinden emin olun.

Çözme adımları:

1. Verilen satır ve sütunun boş olup olmadığını kontrol edin, öyleyse bir rakam deneyin.
2. Bir değer verilen satır ve sütuna ayarlanmışsa, aynı satırdaki sonraki sayıya gidin. Satır bittiyse, sonraki satıra git.
3. İlk ile başlayan her satır için 1. ve 2. yapmaya çalışın.
4. Son satır ve sütuna ulaştığınızda, panoyu doldurmuşsunuz demektir.
5. Yukarıdaki adımlardaki herhangi bir sorun, daha önce denenen numaralardan birinin sorunlu olduğu anlamına gelir. Öyleyse buna geri dönün, başka bir şeyle değiştirin ve aynı adımları tekrar deneyin.

## Örnek Çıktı

<p align = "center">
<img src = "https://i.hizliresim.com/7VWOny.png">
</p>

* Program, kullanıcının panoyu çözmeye çalışmasına izin vermez. Bu özellik bir arayüzden sonra gelebilir.

---------------

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

## Example Output

<p align="center">
<img src="https://i.hizliresim.com/7VWOny.png">
</p>

* Program does not allow user to try to solve the board. This feature might come after an interface.
