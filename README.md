# Đồ án NachOS
## Các thành viên trong nhóm:
- 20120081 - Nguyễn Mậu Trọng Hiếu
- 20120504 - Nhan Gia Khâm
- 20120599 - Phù Thị Kim Trang

## Sơ lược về đồ án
- Cài đặt thêm các Exception vào trong file exception.c (Những Exception cần đc cài đủ để tránh TH user đánh sập OS)
- Cài đặt một số file check để kiếm tra các hàm đã được cài đặt thêm đó.

## Các chạy chương trình (Giả sử đang trong thư mục NachOS-4.0)
- Đầu tiên, mỗi lần thay đổi trong file exception.c thì phải vào trong thư muc `code/build.linux/` và rồi gõ lệnh `make`.
- Sau khi ra được file thực thi `nachos` xong, chúng ta có thể vào trong thư mục `code/test/` để gõ lệnh `make` và chạy các file thực thi theo lệnh `../build.linux/nachos -x <tên file thực thi muốn chạy>`.

