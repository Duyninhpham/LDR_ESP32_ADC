# LDR_ESP32_ADC
# Đo Độ Sáng Bằng ESP32 và LDR

## Mô Tả Dự Án
Dự án này sử dụng ESP32 kết hợp với một quang trở (LDR) để đo độ sáng và hiển thị giá trị đọc được qua cổng UART. Giá trị độ sáng được đọc từ chân ADC (Analog to Digital Converter) của ESP32 và hiển thị dưới dạng số nguyên trong khoảng từ 0 đến 4095. Dữ liệu độ sáng cũng được vẽ đồ thị theo thời gian thực bằng công cụ Teleplot.

## Thành Phần
- **ESP32**: Bảng mạch phát triển ESP32.
- **Quang trở (LDR)**: Cảm biến độ sáng.
- **Mạch điện**: Kết nối LDR với chân ADC của ESP32.

## Cài Đặt Môi Trường
1. **Cài đặt PlatformIO** hoặc **Arduino IDE**.
2. **Cài đặt thư viện** cần thiết.
3. **Kết nối ESP32** với máy tính thông qua cổng USB Type-C.

## Cách Sử Dụng
1. **Tải mã nguồn** từ repository này về máy của bạn.
2. **Mở mã nguồn** trong PlatformIO hoặc Arduino IDE.
3. **Chọn cổng COM** tương ứng với ESP32.
4. **Upload mã** lên ESP32.

