# struktur-data-h-praktikum-2-2021
## Penomoran Garasi Saha
### Verdict
AC saat praktikum
#### Bukti
![verdict_pgs](/img/verdict_pgs.jpg)
### Penjelasan Soal
Diberikan beberapa bilangan yang merupakan nomor ruangan dari garasi saha. Bilangan-bilangan tersebut disusun menjadi `Binary Search Tree`. Kemudian, diminta untuk mengeluarkan bilangan dari level terbawah sampai teratas, dengan ketentuan: level paling bawah dikeluarkan bilangan yang paling rendah (minimal), level di atasnya bilangan dengan nilai maksimal, level di atasnya lagi nilai minimal lagi dan seterusnya.
### Penjelasan Solusi
Permasalahan Penomoran Garasi Saha dapat diselesaikan dengan menggunakan `BST` dan traversal `level order`/`BFS` yang telah dimodifikasi (`__bst__levelorder`) serta struktur data `Queue` yang menyimpan data dalam bentuk `BSTNode` dan ditambahkan data tentang `level` node tersebut dalam tree. Adapun hal yang dilakukan dalam fungsi `__bst__levelorder` adalah menginisialisasi 2 struktur data `queue`. Queue `myQ` digunakan untuk melakukan `BFS` seperti biasanya, sedangkan `nuQ` berfungsi untuk menyimpan data dari queue `myQ`. Hal ini dilakukan karena untuk melakukan proses traversal, __harus__ dilakukan pop pada `myQ`, sehingga pada akhirnya `myQ` akan kosong.
Pertama, `myQ` akan diisi dulu dengan nilai root dari tree (`queue_push(&myQ, *root, 1)`, 1 merupakan level dari node root tree). Lalu, dibuat variabel `level` yang diinisialisai nilainya `0`. Variabel `level` di sini berfungsi untuk menyimpan berapa banyak level dalam tree, sehingga dapat dikirimkan ke fungsi `printLevel`. 

Kemudian, dilakukan perulangan `while` selama `myQ` tidak kosong. Isi dari perulangan tersebut adalah mempush front dari `myQ` ke `nuQ`. Lalu, dilakukan traversal, yaitu `push` `left` dan `right` dari node yang disimpan dalam front `myQ`, dan levelnya ditambah 1 (`(myQ._front->depth)+1`), dan variabel `level` ditambah 1. Kemudian, `myQ` di`pop`.

Di dalam fungsi `printLevel`, yang dilakukan adalah membuat suatu array yang berukuran `level`. Array ini berfungsi untuk menyimpan nilai max/min dari masing-masing level tree. Lalu, array tersebut diinisialisasi dengan dua anggota pertama dari `queue` (karena root tidak memiliki "saudara" dan untuk mempermudah perbandingan untuk level 2). Kemudian, dijalankan perulangan selama `queue` tidak kosong. `if(depth == p->depth)` berfungsi untuk memeriksa apakah `front` dari `queue` satu `level` dengan anggota array sehingga perlu dibandingkan. 
- Jika iya, terdapat `if-else` yang berfungsi memeriksa apakah diambil nilai yang terkecil antara kedua nilai atau terbesar. Karena polanya adalah min-max-min dari level terbawah, maka jika level terbawah ganjil, tiap level ganjil akan mengambil nilai minimum, yang genap akan mengambil nilai maksimum dan sebaliknya. Hal ini diuji dengan `depth%2 == level%2`. Kemudian, di dalam `if-else` tersebut berisi `if` yang memeriksa apakah anggota array perlu diganti atau tidak.

- Jika tidak, tidak dibandingkan, dan pemeriksaan dilanjutkan pada level selanjutnya. Dalam kode ini ditunjukkan sebagai
```
depth++;
arr[depth-1] = p->data.key;
```
Kemudian, dilakukan `pop` pada `queue` sehingga dapat memeriksa anggota `queue` selanjutnya.
Terakhir, keluarkan nilai array dari index terbesar ke 0.

Dalam fungsi main, dilakukan penerimaan input dan pemanggilan fungsi yang telah dijabarkan. Pertama, akan diterima input banyak anggota tree yang disimpan dalam variabel `n`. Kedua, ada loop `for` untuk memasukkan anggota tree sesuai input. Ketika loop berakhir, tree `myTree` dikirimkan ke fungsi `bst_levelorder` yang akan mengirim nilai rootnya ke `__bst__levelorder`.

### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan Penomoran Garasi Saha, digunakan sample input berikut:

```
7
500
250
750
125
375
625
875
```

Setelah nilai-nilai tersebut dimasukkan dalam tree, maka akan terjadi operasi seperti berikut.

![pgs1](/img/si_pgs1.gif)

Melakukan operasi `BFS` dengan bantuan queue `myQ`, dan menyimpan data dalam `nuQ`

![pgs2](/img/si_pgs2.jpg)

Membuat array sebesar `level`

![pgs3](/img/si_pgs3.jpg)

Mengisi index pertama dengan nilai `root`.

![pgs4a](/img/si_pgs4a.jpg)
![pgs4b](/img/si_pgs4b.jpg)

Mengisi index kedua dengan nilai `root->left`, kemudian membandingkannya dengan anggota tree yang se`level`. Karena banyak `level` 3, dan level yang dibandingkan adalah `level` 2, diambil nilai yang terbesar (`750`).

![pgs5a](/img/si_pgs5a.jpg)

Karena `front` dari `queue` sekarang berbeda `level` dengan anggota array pada index sekarang, index selanjutnya diisi dengan nilai `front` tersebut

![pgs5b](/img/si_pgs5b.gif)

Kemudian, anggota `queue` dibandingkan dengan anggota array pada index sekarang. Karena yang diminta pada `level` ini adalah nilai minimun, tidak terjadi perubahan pada array. 

![pgs6](/img/si_pgs6.jpg)

Keluarkan (`printf`) anggota `arr` dari index terbesar sampai 0.

Output:
```
125 750 500
```

## Roni Suka Merah
### Verdict
AC saat praktikum
#### Bukti
![verdict_rsm](/img/verdict_rsm.jpg)
### Penjelasan Soal
Diberikan beberapa bilangan yang lalu disusun dalam sebuah tree. Kemudian, diminta untuk mengeluarkan anggota tree sesuai dengan contoh output dan clue yang diberikan
### Penjelasan Solusi
Dari input-output yang dihasilkan pada soal (Input: `6 1 8 12 3 7`, Output: `1 3 6 7 8 12`) dan clue, disimpulkan bahwa output merupakan hasil traversal inorder dengan operasi print.

Dalam fungsi main:

Dibuat suatu `binary search tree` yang bernama `set`, berfungsi untuk menyimpan data dan variabel `N` untuk menyimpan berapa banyak anggota dari `tree` yang akan dibuat. Lalu, program meminta input untuk disimpan dalam N. Selanjutnya, dilakukan loop `for` sebanyak `N` kali. Dalam loop, nilai yang diinput dimasukkan ke dalam `tree` (`bst_insert`) dibantu oleh variabel `num`. Setelah loop selesai, `set` akan dikirim ke fungsi `bst_inorder`. Fungsi tersebut akan mengirim `root` dari `set` ke `__bst__inorder`. Fungsi ini akan melakukan operasi yang akan mengeluarkan nilai anggota-anggota dari sebelah kiri node yang dikirimkan ke fungsi, lalu nilai node itu sendiri, lalu nilai anggota-anggota yang berada di sebelah kanan node tersebut. Lebih jelasnya dapat dilihat di "Visualisasi Solusi".

### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan Roni Suka Merah, digunakan sample input berikut:

```
6
6
1
8
12
3
7
```

![rsm1](/img/si_rsm1.jpg)

Membuat `tree` dari input-input yang diberikan.

![rsm2](/img/si_rsm2.jpg)

Memulai dari node `root`, yaitu 6. 

![rsm3](/img/si_rsm3.jpg)

Karena ada node disebelah kiri node 6, fungsi `inorder` untuk node kiri akan dijalankan terlebih dahulu.

![rsm4](/img/si_rsm4.jpg)

Tidak ada node di kiri node 1, sehingga keluarkan 1.

![rsm5](/img/si_rsm5.jpg)

`inorder` dilakukan pada node sebelah kanan dari node 1, yaitu node 3. Karena disebelah kiri dan kanan dari node 3 tidak ada, maka di `print` 3 saja.

![rsm6](/img/si_rsm6.jpg)

Karena operasi `inorder` pada node-node di sebelah kiri node 6 sudah selesai, print 6.

![rsm6](/img/si_rsm7.jpg)

Kemudian, lanjut ke node sebelah kanan dari node 6, yaitu node 8.

![rsm6](/img/si_rsm8.jpg)

Karena di kiri node 8 ada node 7, dan node 7 tidak memiliki `child`/`kiri`-`kanan`, print 7.

![rsm6](/img/si_rsm9.jpg)

Lalu, print 8.

![rsm6](/img/si_rsm10.jpg)

Lanjut ke kanan node 8,, yaitu node 12. Karena node 12 juga tidak ada kiri kanannya, print 12.

Traversal `inorder` selesai.

Output:
```
1 3 6 7 8 12 
```

## MALUR TERHUBUNG
### Verdict
AC saat revisi
#### Bukti
![verdict_mt](/img/verdict_mt.jpg)
### Penjelasan Soal
Diberikan beberapa bilangan yang dibentuk menjadi `Binary Search Tree`. Lalu, diberikan 2 bilangan. Kemudian, diminta mengeluarkan hasil penjumlahan dari subtree yang menghubungkan kedua bilangan tersebut.
### Penjelasan Solusi


### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan MALUR TERHUBUNG, digunakan sample input berikut:

```
8 2
8 3 10 1 6 14 4 7 
1 4  
4 9
```
__Untuk input `1 4`__
![mt1](/img/si_mt1.jpg)

Dibuat tree berdasarkan input.

![mt2](/img/si_mt2.jpg)

Cari 1 dan 4 dahulu. Jika ditemukan, lanjut ke fungsi `find_path`

![mt3](/img/si_mt3.jpg)

Mulai pointer p dari `root`, yaitu node dengan nilai 8. Karena nilainya lebih besar dari kedua nilai yang dicari, pindahkan pointer ke node kirinya (node 3).

![mt4](/img/si_mt4.jpg)

Karena 3 lebih dari 1 dan kurang dari 4, node 3 adalah `root` yang sama yang terdekat, sehingga node 3 dikirim ke fungsi `addInorder`.

![mt5](/img/si_mt5.jpg)

Fungsi `addInorder` akan menjumlahkan semua anggota subtree dibawah node 3, disimpan pada variabel `*sum` (dalam `find_path` dibuat variabel `sum` dan dikirimkan alamatnya ke `addInorder`)

![mt6](/img/si_mt6.jpg)

Kemudian, keluarkan nilai `sum`, yaitu `21`. 

__Untuk input `4 9`__

![mt7](/img/si_mt7.jpg)

9 tidak ditemukan dalam `tree`, sehingga keluarkan `-1`.

Output:
```
21
-1
```

## Nadut Gabut
### Verdict
AC saat revisi
#### Bukti
![verdict_ng](/img/verdict_ng.jpg)
### Penjelasan Soal
Diberikan beberapa bilangan yang disusun menjadi Binary Search Tree. Lalu, diberikan bilangan. Diminta untuk mencari apakah bilangan tersebut dapat dihasilkan dari penjumlahan 3 anggota tree yang bertetangga, dan mengeluarkan output seperti yang dicontohkan dalam soal.
### Penjelasan Solusi
Pertama, program menerima banyak testcase yang disimpan dalam variabel `T`. Lalu, dilakukan loop sebanyak `T`. Di dalam `loop`, program menerima banyak blok angka yang akan disusun dan disimpan dalam variabel `P`. Lalu, program akan menerima angka-angka pada blok yang disimpan dalam array `Q`. Kemudian, nilai-nilai dari index dari array `Q` akan dievaluasi dengan bantuan stack `myStack`di dalam loop sebanyak P :
1. Jika nilai `Q[index] <= stack_top(&myStack)`(kurang dari elemen teratas stack) atau `stack_isEmpty(&myStack)` (stack kosong) maka `Q[index]` akan dimasukkan ke dalam stack (`stack_push`).
2. Jika nilai `Q[index]` lebih dari elemen teratas (`Q[j]>stack_top(&myStack)`), maka elemen teratas akan dikeluarkan 
`stack_pop(&myStack)`. Hal ini akan dilakukan terus menerus sampai elemen teratas lebih dari nilai `Q[index]` atau stack kosong (`myStack._top==NULL`).
Apabila sudah dilakukan loop sebanyak `P`, elemen dari stack akan disimpan ke dalam array baru `arr`. Elemen dimasukkan secara terbalik, dengan cara mengassign index dari `size-1` sampai `0` dan melalukan pop pada stack.
Terakhir, keluarkan `Susunan blok yang disusun Nadut dan Cayo adalah : ` diikuti oleh nilai anggota `arr` berurutan dari `index 0` sampai terakhir.
Proses diulang sebanyak `T`.

### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan Nadut Gabut, digunakan sample input berikut:

```
10
73 66 91 53 72 77 98 74 78 79
266
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
Penjumlahan angka di tree yang menghasilkan 266 ditemukan
```

## Genjil Ganap V2
### Verdict
AC saat revisi
#### Bukti
![verdict_ggv2](/img/verdict_ggv2.jpg)
### Penjelasan Soal
Diminta untuk membuat tree yang hanya berisi bilangan genap dari input yang diberikan, dengan ketentuan jika ada input bilangan ganjil, bilangan genap yang diinput sebelumnya akan dihapus dari tree.
### Penjelasan Solusi
Masalah Genjil Ganap V2 diselesaikan dengan struktur data `binary search tree` dan `array`. BST digunakan sebagai ADT utama untuk menyimpan data, sedangkan array digunakan untuk mengingat urutan masuknya data sehingga dapat digunakan sebagai referensi untuk menghapus bilangan genap yang terakhir dimasukkan.
Jika tree kosong (`bst_isEmpty(&set)`), dikeluarkan `Tree Kosong!`.Jika tidak, dikeluarkan anggota tree dengan traversal `inorder`.

### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan Genjil Ganap V2, digunakan sample input berikut:

```
7
6
4
5
8
7
12
10
```

![ggv2_1](/img/si_ggv2_1.jpg)

txt

![ggv2_2a](/img/si_ggv2_2a.jpg)
![ggv2_2b](/img/si_ggv2_2b.jpg)

txt

![ggv2_3](/img/si_ggv2_3.jpg)

txt

![ggv2_4](/img/si_ggv2_4.jpg)

txt

![ggv2_5](/img/si_ggv2_5.jpg)

txt

![ggv2_6a](/img/si_ggv2_6a.jpg)
![ggv2_6b](/img/si_ggv2_6b.jpg)

txt

![ggv2_7](/img/si_ggv2_7.gif)

Agar anggota tree dikeluarkan secara terurut dari nilai terendah ke tertinggi, gunakan traversal `inorder` dengan fungsi `printf`.

Output:
```
6 10 12 
```