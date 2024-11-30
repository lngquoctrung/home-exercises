Dàn bài đề xuất:
1. Giới thiệu
Tổng quan về bài toán nhận dạng cảm xúc
Tầm quan trọng và ứng dụng thực tế
Mục tiêu nghiên cứu
2. Cơ sở lý thuyết
Deep Learning trong nhận dạng cảm xúc
Mô hình VGG19 và Transfer Learning
Các phương pháp xử lý ảnh và phát hiện khuôn mặt
3. Phương pháp thực hiện
3.1 Dữ liệu
Nguồn dữ liệu (FER2013 dataset)
Phân tích và tiền xử lý dữ liệu
Phân chia tập train/validation
3.2 Kiến trúc mô hình
Mô hình VGG19 pretrained
Fine-tuning và điều chỉnh mô hình
Các tham số huấn luyện
3.3 Quá trình huấn luyện
Data augmentation
Các callback và chiến lược huấn luyện
Theo dõi quá trình huấn luyện
4. Kết quả và đánh giá
4.1 Độ chính xác và mất mát
Biểu đồ accuracy và loss
Phân tích convergence
4.2 Ma trận nhầm lẫn
Phân tích chi tiết từng lớp cảm xúc
Điểm mạnh và điểm yếu của mô hình
4.3 Ứng dụng thực tế
Nhận dạng cảm xúc qua webcam
Nhận dạng cảm xúc qua ảnh
5. Kết luận và hướng phát triển
Tóm tắt kết quả đạt được:
Hiệu suất mô hình:
Độ chính xác tổng thể trên tập validation: 68%
F1-score trung bình: 0.67
Số lượng dự đoán sai trên tập validation: 1,164 mẫu
Phân tích theo từng cảm xúc:
Hiệu suất tốt nhất: Cảm xúc "Happy" (F1-score: 0.86)
Hiệu suất trung bình: "Surprise" (F1-score: 0.77)
Hiệu suất thấp nhất: "Fear" (F1-score: 0.46) và "Disgust" (F1-score: 0.50)
Quá trình huấn luyện:
Mô hình hội tụ sau khoảng 30 epochs
Validation accuracy tăng dần và ổn định
Không có dấu hiệu overfitting đáng kể
Điểm nổi bật:
Sử dụng transfer learning với VGG19 pretrained
Áp dụng data augmentation để tăng cường dữ liệu
Triển khai được ứng dụng thực tế (webcam và ảnh)
Hạn chế và thách thức:
Khó khăn trong nhận dạng một số cảm xúc (fear, disgust)
Sự mất cân bằng trong dữ liệu training
Thời gian huấn luyện tương đối dài