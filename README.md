# struktur-data-h-praktikum-1-2021
## Penomoran Garasi Saha
### Verdict
AC saat praktikum
#### Bukti
![verdict_naca](/img/verdict_naca.jpg)
### Penjelasan Soal
Diberikan beberapa angka yang dianggap sebagai blok angka yang ditumpuk, di mana jika blok yang baru dimasukkan lebih besar dari blok yang sudah ada, maka blok lama dikeluarkan dari tumpukan. Diminta mengeluarkan tumpukan akhir.
### Penjelasan Solusi
Pertama, program menerima banyak testcase yang disimpan dalam variabel `T`. Lalu, dilakukan loop sebanyak `T`. Di dalam `loop`, program menerima banyak blok angka yang akan disusun dan disimpan dalam variabel `P`. Lalu, program akan menerima angka-angka pada blok yang disimpan dalam array `Q`. Kemudian, nilai-nilai dari index dari array `Q` akan dievaluasi dengan bantuan stack `myStack`di dalam loop sebanyak P :
1. Jika nilai `Q[index] <= stack_top(&myStack)`(kurang dari elemen teratas stack) atau `stack_isEmpty(&myStack)` (stack kosong) maka `Q[index]` akan dimasukkan ke dalam stack (`stack_push`).
2. Jika nilai `Q[index]` lebih dari elemen teratas (`Q[j]>stack_top(&myStack)`), maka elemen teratas akan dikeluarkan 
`stack_pop(&myStack)`. Hal ini akan dilakukan terus menerus sampai elemen teratas lebih dari nilai `Q[index]` atau stack kosong (`myStack._top==NULL`).
Apabila sudah dilakukan loop sebanyak `P`, elemen dari stack akan disimpan ke dalam array baru `arr`. Elemen dimasukkan secara terbalik, dengan cara mengassign index dari `size-1` sampai `0` dan melalukan pop pada stack.
Terakhir, keluarkan `Susunan blok yang disusun Nadut dan Cayo adalah : ` diikuti oleh nilai anggota `arr` berurutan dari `index 0` sampai terakhir.
Proses diulang sebanyak `T`.

### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan Nadut & Cayo, digunakan sample input berikut:

```
1
5
5 4 7 2 1
```

![nc1](/img/si_nc1.jpg)

Stack kosong, `push` 5 ke `myStack`

![nc2](/img/si_nc2.jpg)

4 kurang dari `stack_top`, `push` 4 ke `myStack`

![nc3a](/img/si_nc3a.jpg)
![nc3b](/img/si_nc3b.jpg)

7 lebih dari `stack_top`, `pop` terus `myStack` hingga `stack_top` >= 7 atau `stack_isEmpty`

![nc4](/img/si_nc4.jpg)

2 kurang dari `stack_top`, `push` 2 ke `myStack`

![nc5](/img/si_nc5.jpg)

1 kurang dari `stack_top`, `push` 1 ke `myStack`

![nc6](/img/si_nc6.jpg)

Salin nilai elemen stack ke array `arr` secara terbalik.
Kemudian, print anggota arr

Output:
```
Susunan blok yang disusun Nadut dan Cayo adalah : 7 2 1
```

## Roni Suka Merah
### Verdict
AC saat praktikum
#### Bukti
![verdict_naca](/img/verdict_naca.jpg)
### Penjelasan Soal
Diberikan beberapa angka yang dianggap sebagai blok angka yang ditumpuk, di mana jika blok yang baru dimasukkan lebih besar dari blok yang sudah ada, maka blok lama dikeluarkan dari tumpukan. Diminta mengeluarkan tumpukan akhir.
### Penjelasan Solusi
Pertama, program menerima banyak testcase yang disimpan dalam variabel `T`. Lalu, dilakukan loop sebanyak `T`. Di dalam `loop`, program menerima banyak blok angka yang akan disusun dan disimpan dalam variabel `P`. Lalu, program akan menerima angka-angka pada blok yang disimpan dalam array `Q`. Kemudian, nilai-nilai dari index dari array `Q` akan dievaluasi dengan bantuan stack `myStack`di dalam loop sebanyak P :
1. Jika nilai `Q[index] <= stack_top(&myStack)`(kurang dari elemen teratas stack) atau `stack_isEmpty(&myStack)` (stack kosong) maka `Q[index]` akan dimasukkan ke dalam stack (`stack_push`).
2. Jika nilai `Q[index]` lebih dari elemen teratas (`Q[j]>stack_top(&myStack)`), maka elemen teratas akan dikeluarkan 
`stack_pop(&myStack)`. Hal ini akan dilakukan terus menerus sampai elemen teratas lebih dari nilai `Q[index]` atau stack kosong (`myStack._top==NULL`).
Apabila sudah dilakukan loop sebanyak `P`, elemen dari stack akan disimpan ke dalam array baru `arr`. Elemen dimasukkan secara terbalik, dengan cara mengassign index dari `size-1` sampai `0` dan melalukan pop pada stack.
Terakhir, keluarkan `Susunan blok yang disusun Nadut dan Cayo adalah : ` diikuti oleh nilai anggota `arr` berurutan dari `index 0` sampai terakhir.
Proses diulang sebanyak `T`.

### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan Nadut & Cayo, digunakan sample input berikut:

```
1
5
5 4 7 2 1
```

![nc1](/img/si_nc1.jpg)

Stack kosong, `push` 5 ke `myStack`

![nc2](/img/si_nc2.jpg)

4 kurang dari `stack_top`, `push` 4 ke `myStack`

![nc3a](/img/si_nc3a.jpg)
![nc3b](/img/si_nc3b.jpg)

7 lebih dari `stack_top`, `pop` terus `myStack` hingga `stack_top` >= 7 atau `stack_isEmpty`

![nc4](/img/si_nc4.jpg)

2 kurang dari `stack_top`, `push` 2 ke `myStack`

![nc5](/img/si_nc5.jpg)

1 kurang dari `stack_top`, `push` 1 ke `myStack`

![nc6](/img/si_nc6.jpg)

Salin nilai elemen stack ke array `arr` secara terbalik.
Kemudian, print anggota arr

Output:
```
Susunan blok yang disusun Nadut dan Cayo adalah : 7 2 1
```