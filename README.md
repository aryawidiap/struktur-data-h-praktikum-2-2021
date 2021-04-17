# struktur-data-h-praktikum-2-2021
## Penomoran Garasi Saha
### Verdict
AC saat praktikum
#### Bukti
![verdict_pgs](/img/verdict_pgs.jpg)
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

![pgs1](/img/si_pgs1.jpg)

Stack kosong, `push` 5 ke `myStack`

![pgs2](/img/si_pgs2.jpg)

4 kurang dari `stack_top`, `push` 4 ke `myStack`

![pgs3a](/img/si_pgs3a.jpg)
![pgs3b](/img/si_pgs3b.jpg)

7 lebih dari `stack_top`, `pop` terus `myStack` hingga `stack_top` >= 7 atau `stack_isEmpty`

![pgs4](/img/si_pgs4.jpg)

2 kurang dari `stack_top`, `push` 2 ke `myStack`

![pgs5](/img/si_pgs5.jpg)

1 kurang dari `stack_top`, `push` 1 ke `myStack`

![pgs6](/img/si_pgs6.jpg)

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
![verdict_rsm](/img/verdict_rsm.jpg)
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

![rsm1](/img/si_rsm1.jpg)

Stack kosong, `push` 5 ke `myStack`

![rsm2](/img/si_rsm2.jpg)

4 kurang dari `stack_top`, `push` 4 ke `myStack`

![rsm3a](/img/si_rsm3a.jpg)
![rsm3b](/img/si_rsm3b.jpg)

7 lebih dari `stack_top`, `pop` terus `myStack` hingga `stack_top` >= 7 atau `stack_isEmpty`

![rsm4](/img/si_rsm4.jpg)

2 kurang dari `stack_top`, `push` 2 ke `myStack`

![rsm5](/img/si_rsm5.jpg)

1 kurang dari `stack_top`, `push` 1 ke `myStack`

![rsm6](/img/si_rsm6.jpg)

Salin nilai elemen stack ke array `arr` secara terbalik.
Kemudian, print anggota arr

Output:
```
Susunan blok yang disusun Nadut dan Cayo adalah : 7 2 1
```

## MALUR TERHUBUNG
### Verdict
AC saat revisi
#### Bukti
![verdict_mt](/img/verdict_mt.jpg)
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

![mt1](/img/si_mt1.jpg)

Stack kosong, `push` 5 ke `myStack`

![mt2](/img/si_mt2.jpg)

4 kurang dari `stack_top`, `push` 4 ke `myStack`

![mt3a](/img/si_mt3a.jpg)
![mt3b](/img/si_mt3b.jpg)

7 lebih dari `stack_top`, `pop` terus `myStack` hingga `stack_top` >= 7 atau `stack_isEmpty`

![mt4](/img/si_mt4.jpg)

2 kurang dari `stack_top`, `push` 2 ke `myStack`

![mt5](/img/si_mt5.jpg)

1 kurang dari `stack_top`, `push` 1 ke `myStack`

![mt6](/img/si_mt6.jpg)

Salin nilai elemen stack ke array `arr` secara terbalik.
Kemudian, print anggota arr

Output:
```
Susunan blok yang disusun Nadut dan Cayo adalah : 7 2 1
```

## Nadut Gabut
### Verdict
AC saat revisi
#### Bukti
![verdict_ng](/img/verdict_ng.jpg)
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

![ng1](/img/si_ng1.jpg)

Stack kosong, `push` 5 ke `myStack`

![ng2](/img/si_ng2.jpg)

4 kurang dari `stack_top`, `push` 4 ke `myStack`

![ng3a](/img/si_ng3a.jpg)
![ng3b](/img/si_ng3b.jpg)

7 lebih dari `stack_top`, `pop` terus `myStack` hingga `stack_top` >= 7 atau `stack_isEmpty`

![ng4](/img/si_ng4.jpg)

2 kurang dari `stack_top`, `push` 2 ke `myStack`

![ng5](/img/si_ng5.jpg)

1 kurang dari `stack_top`, `push` 1 ke `myStack`

![ng6](/img/si_ng6.jpg)

Salin nilai elemen stack ke array `arr` secara terbalik.
Kemudian, print anggota arr

Output:
```
Susunan blok yang disusun Nadut dan Cayo adalah : 7 2 1
```

## Genjil Ganap V2
### Verdict
AC saat revisi
#### Bukti
![verdict_ggv2](/img/verdict_ggv2.jpg)
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

![ggv2_1](/img/si_ggv2_1.jpg)

Stack kosong, `push` 5 ke `myStack`

![ggv2_2](/img/si_ggv2_2.jpg)

4 kurang dari `stack_top`, `push` 4 ke `myStack`

![ggv2_3a](/img/si_ggv2_3a.jpg)
![ggv2_3b](/img/si_ggv2_3b.jpg)

7 lebih dari `stack_top`, `pop` terus `myStack` hingga `stack_top` >= 7 atau `stack_isEmpty`

![ggv2_4](/img/si_ggv2_4.jpg)

2 kurang dari `stack_top`, `push` 2 ke `myStack`

![ggv2_5](/img/si_ggv2_5.jpg)

1 kurang dari `stack_top`, `push` 1 ke `myStack`

![ggv2_6](/img/si_ggv2_6.jpg)

Salin nilai elemen stack ke array `arr` secara terbalik.
Kemudian, print anggota arr

Output:
```
Susunan blok yang disusun Nadut dan Cayo adalah : 7 2 1
```