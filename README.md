# Bai1_Antoanbaomatthongtin
## Bài 1 An toàn bảo mật thông tin

### TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN

Caesar

Affine

Hoán vị

Vigenère

Playfair

### Với mỗi phương pháp, hãy tìm hiểu:

Tên gọi

Thuật toán mã hoá, thuật toán giải mã

Không gian khóa

Cách phá mã (mà không cần khoá)

Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript

# Bài làm
## Caesar
### Tên gọi
 Caesar cipher (mã dịch).
### Thuật toán mã hoá, thuật toán giải mã
Thuật toán mã hoá:

Với bảng chữ cái 26 chữ (A..Z), khoá là số nguyên k (0 ≤ k ≤ 25).

Mã hoá ký tự: C = (P + k) mod 26

P là chỉ số chữ (A=0..Z=25), C là chỉ số chữ mã hoá.

Thuật toán giải mã:

P = (C - k) mod 26 (hoặc P = (C + 26 - k) mod 26).
### Không gian khóa
Không gian khoá: 26 khả năng (thực tế 25 hữu ích, k=0 là không mã hoá).
### Cách phá mã (mà không cần khoá)
Brute-force thử 25 khả năng; chọn bản dịch có nghĩa.

Phân tích tần suất: nếu văn bản dài, tần suất chữ cái lớn nhất thường là E (tiếng Anh) hoặc A/E/T (tiếng Việt khác).

Dùng chỉ số tương đồng / xác suất ngôn ngữ.
### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/77c1577c-dea7-464c-8bdb-c48d46a79152" />

#### Html 
<img width="1549" height="879" alt="image" src="https://github.com/user-attachments/assets/af55eb44-e328-4596-95ee-bd0b906cce45" />

## Affine
### Tên gọi
Affine cipher (mã tuyến tính affine mod 26)
### Thuật toán mã hoá, thuật toán giải mã
Thuật toán mã hóa:

Khóa là cặp (a, b) với gcd(a,26)=1 (a phải có nghịch đảo modulo 26), b ∈ {0..25}.

Mã: C = (a·P + b) mod 26.
Thuật toán giải mã:

Tính a⁻¹ (nghịch đảo modulo 26).

P = a⁻¹ · (C − b) mod 26.
### Không gian khóa
Giá trị a có φ(26)=12 khả năng (a ∈ {1,3,5,7,9,11,15,17,19,21,23,25}), b có 26 → tổng 12×26 = 312 khóa.
### Cách phá mã (mà không cần khoá)
Brute-force toàn bộ 312 khả năng; kiểm tra bản rõ hợp lệ bằng từ vựng/tần suất.

Phân tích tần suất: affine là sự kết hợp scale+shift, nên vẫn có thể dùng tần suất để suy a và b nếu có đủ dữ liệu.
### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++
<img width="1854" height="859" alt="image" src="https://github.com/user-attachments/assets/b0ebac31-4417-451f-8112-3fa8a081c427" />

#### Html 
<img width="1546" height="905" alt="image" src="https://github.com/user-attachments/assets/6695ee4e-a3bf-4662-98aa-a9f76a6cb135" />

## Hoán vị
### Tên gọi
Permutation cipher, Transposition cipher — ví dụ phổ biến: Columnar transposition (hoán vị cột), hoặc block permutation.
### Thuật toán mã hoá, thuật toán giải mã
Thuật toán mã hóa (ví dụ columnar):

Chọn khóa: một từ/hoán vị xác định thứ tự các cột (hoặc một hoán vị số 1..n).

Viết plaintext theo hàng xuống một ma trận có số cột = độ dài khóa; đọc cipher theo thứ tự các cột được sắp xếp theo khóa.

Với block-permutation: chia plaintext thành block size = n, rồi hoán vị các vị trí trong mỗi block theo hoán vị key.
Thuật toán giải mã:

Dùng khóa (hoán vị) để đảo ngược thao tác: xác định chiều dài hàng/cột, phân chia ciphertext thành cột/khối theo kích thước rồi đọc lại theo hàng (hoặc áp dụng nghịch đảo hoán vị).
### Không gian khóa
Nếu khóa là hoán vị của n phần tử → n! khả năng (rất lớn khi n tăng).

Ví dụ: n=5 → 120, n=10 → ≈3.6M.
### Cách phá mã (mà không cần khoá)
Brute-force thử mọi hoán vị chỉ khả thi khi n nhỏ (n ≤ 7–8).

Heuristics / hill-climbing / simulated annealing: dùng hàm điểm dựa trên n-gram (log probability) để tìm hoán vị tốt nhất.

Phân tích n-gram / cấu trúc từ: tìm các cột/các vị trí làm xuất hiện các từ hợp lý.

Đôi khi kết hợp với crib (một phần plaintext biết trước) để hạn chế không gian tìm kiếm.
### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++
<img width="1811" height="865" alt="image" src="https://github.com/user-attachments/assets/7adf81b8-58ed-44aa-a5b9-5d1b39744982" />

#### Html 
<img width="1544" height="954" alt="Ảnh chụp màn hình 2025-09-27 212849" src="https://github.com/user-attachments/assets/b266c6c9-ecf6-4390-bbc0-d081c182b388" />

## Vigenère
### Tên gọi
Vigenère Cipher (mã hóa đa bảng thay thế theo khóa lặp).
### Thuật toán mã hoá, thuật toán giải mã
Thuật toán mã hóa:

Khóa: chuỗi ký tự K = k₀...k_{m−1} (độ dài m).

Mã: C_i = (P_i + K_{i mod m}) mod 26 (với P_i, K_j là chỉ số chữ cái 0..25).

Thực tế: lặp khóa trên toàn văn.
Thuật toán giải mã:

P_i = (C_i − K_{i mod m} + 26) mod 26.
                  
### Không gian khóa
Nếu độ dài khóa là m cố định → 26^m khả năng. Nếu m không giới hạn thì không gian rất lớn.
### Cách phá mã (mà không cần khoá)
Kasiski examination: tìm các n-gram (thường 3 ký tự) lặp trong ciphertext, khoảng cách giữa các lần lặp thường chia hết cho độ dài khóa → dùng GCD các khoảng để đoán m.

Index of Coincidence (IC): tính IC của ciphertext; so sánh IC giả định cho các phân đoạn để ước lượng m.

Sau khi đoán được m: chia ciphertext thành m chuỗi (các chữ ở cùng vị trí modulo m). Mỗi chuỗi là Caesar cipher → dùng phân tích tần suất để tìm shift của từng chuỗi, ghép lại thành khóa.

Brute-force trên m nhỏ: thử mọi m ≤ M tối đa, với mỗi m dùng phương pháp tần suất.

Mã hoá tiên tiến: nếu plaintext ngắn, có thể dùng các phương pháp thống kê/dictionary scoring để chọn khóa tốt nhất.
### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++
<img width="1755" height="908" alt="image" src="https://github.com/user-attachments/assets/ac392b7d-19c3-4722-a148-16e3f38aa37f" />

#### Html 
<img width="1544" height="950" alt="Ảnh chụp màn hình 2025-09-27 215217" src="https://github.com/user-attachments/assets/49e48681-6dc3-4a7f-92fb-09afe4a5694e" />
## Playfair 
### Tên gọi
Playfair cipher
### Thuật toán mã hoá, thuật toán giải mã
Thuật toán mã hóa:

Tạo ma trận 5×5 từ khóa (ghép I/J lại thành một ô).

Chuẩn hóa plaintext: bỏ ký tự không chữ, thay J → I, chia thành digraph (cặp). Nếu hai chữ trong một cặp giống nhau, chèn 'X' giữa; nếu lẻ, thêm 'X' cuối.

Với mỗi digraph (A,B):

Nếu A và B cùng hàng: thay bằng chữ bên phải của mỗi chữ (vòng).

Nếu cùng cột: thay bằng chữ bên dưới của mỗi chữ (vòng).

Nếu khác hàng & cột: thay bằng hai chữ ở góc còn lại của hình chữ nhật (giữ hàng, đổi cột).
Thuật toán giải mã:

Quy tắc ngược: hàng → dịch trái, cột → dịch lên, rectangle → tương tự (đổi cột theo hai chữ).
### Không gian khóa
Không gian khóa:

Về lý thuyết rất lớn (~25! hoán vị của 25 chữ) ≈ 1.55×10^25 (rất lớn).
### Cách phá mã (mà không cần khoá)
Phân tích digraph: Playfair làm biến dạng tần suất đơn ký tự nhưng digraph tần suất vẫn có mẫu → dùng tần suất 2-gram để so sánh với ngôn ngữ mục tiêu.

Heuristic search (hill-climbing / simulated annealing / genetic): tìm bảng 5×5 tốt nhất bằng cách tối ưu hàm điểm (dựa trên log-probability n-gram, thường 3-gram/4-gram). Đây là phương pháp thành công nhất để phá Playfair.

Cribbing: nếu biết một đoạn plaintext (crib), có thể dùng để thử tập con các hoán vị bảng.

Brute-force toàn bộ không khả thi.
### Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
#### C++
<img width="1689" height="879" alt="image" src="https://github.com/user-attachments/assets/1250e97e-659b-46ad-b613-fe131da04bde" />
#### Html 
<img width="1005" height="600" alt="image" src="https://github.com/user-attachments/assets/131ff940-643c-4c50-90d6-814ce5fae85f" />
