# GIỚI THIỆU SƠ LƯỢC YÊU CẦU CÁC BÀI CODE ĐÃ LÀM
## Sinh viên thực hiện: Vương Kim Hoàng
## Giáo viên hướng dẫn: ThS.Nguyễn Đức Tiến

# **Tuần 1**
1. Cộng trừ nhân chia 2 số nguyên. 
2. Truy vấn cơ bản trên mảng. Các câu truy vấn bao gồm: Tìm max, min, tính tổng các số trong mảng và tìm max trong đoạn từ chỉ số i đến j.
3. Chuyển các kí tự trong văn bản sang chữ in hoa.
4. Chuyển thời gian dạng hh:mm:ss thành giây.
5. Đếm số số chẵn và số lẻ trong mảng.
6. Đếm số từ trong đoạn văn.
7. Tách riêng ngày, tháng, năm từ xâu đầu vào có dạng YYYY-MM-DD.
8. Cho số nguyên n, liệt kê các số nguyên từ 1 đến n và các số chính phương. 
9. Cho số nguyên n, liệt kê các số nguyên gồm 3 chữ số chia hết cho n.
10. So sánh chênh lệch giá điện theo đề xuất mới của EVN.
11. Giải phương trình bậc 2.
12. Tổng các số trong mảng.
13. Cho văn bản T và 2 mẫu P1, P2 đều là các xâu ký tự (không chứa ký tự xuống dòng, độ dài không vượt quá 1000). Hãy thay thế các xâu P1 trong T bằng xâu P2.
14. Cho dãy số gồm n phần tử và một số nguyên k. Hãy đếm số dãy con gồm k phần tử liên tiếp và tổng của chúng là số lẻ.
    
# **Tuần 2**
1. Viết chương trình sinh ra các chuỗi bit nhị phân có độ dài n theo thứ tự từ điển.
2. Viết chương trình sinh ra các chuỗi bit nhị phân không có 2 bits 1 liên tiếp có độ dài n theo thứ tự từ điển.
3. Tính tổ hợp chập k của n.
4. Đếm số lời giải của bài toán sudoku bằng cách điền các số từ 1 đến 9 trong bảng 9x9 sao cho các số trong từng hàng, từng cột và từng ô vuông 3x3 là khác nhau.
5. Tìm số thứ n trong dãy fibonacci.
6. Viết chương trình sinh ra các hoán vị của các số từ 1 đến n theo thứ tự từ điển.
   
# **Tuần 3**
1. Chèn một nút vào cây nhị phân và thực hiện phép duyệt cây theo thứ tự trước (Gốc -> Con trái -> Con phải).
2. Kiểm tra dãy ngoặc đúng.
3. Cho một cây phả hệ được biểu thị bằng quan hệ con-cha mẹ (c,p) trong đó c là con của p. Thực hiện các truy vấn về cây gia phả. Hậu duệ \<name>: trả về số hậu duệ của <name> đã cho; thế hệ \<name>: trả về số thế hệ con cháu của <name> đã cho.
4. Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy gồm n phần tử, sau đó thực hiện các thao tác trên danh sách bao gồm: thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách.
5. Thực hiện một chuỗi các thao tác trên một hàng đợi bao gồm PUSH v, POP.
6. Thực hiện một chuỗi các thao tác trên một ngăn xếp bao gồm PUSH v, POP.
7. Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau). Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
    - MakeRoot u: Tạo ra nút gốc u của cây
    - Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
    - PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
    - InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
    - PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau.
8. Có hai bình, bình a lít và bình b lít. Có một máy bơm với nước không giới hạn. Cho số nguyên dương c, làm thế nào để có được chính xác c lít.

# **Tuần 4**
1. Cho một chuỗi s[1…k] là một chuỗi các ký tự được lấy từ {'a', . . ., ‘z’}. Cho số nguyên dương m, mã băm của s được xác định theo công thức: H(s) = (s[1]*256^(k-1) + s[2]*256^(k-2) + . . . + s[k]*256^0 ) mod m.Cho dãy các chuỗi k1, k2, …, kn, tính mã băm tương ứng.
2. Cho dãy số nguyên A[1], A[2], . . . , A[n] với mỗi số nguyên A[i] kiểm tra xem có số A[j] nào bằng A[i] hay không với i>j.
3. Cơ sở dữ liệu chứa một chuỗi khóa k1, k2, ..., kn là các chuỗi (1<=n<=100000). Thực hiện một chuỗi hành động gồm hai loại:
    - find k: tìm và trả về 1 nếu k tồn tại trong cơ sở dữ liệu, và trả về 0, nếu không.
    - Insert k: chèn khóa k vào cơ sở dữ liệu và trả về 1 nếu chèn thành công (k không tồn tại trong cơ sở dữ liệu) và trả về 0 nếu chèn thất bại (k tồn tại trong cơ sở dữ liệu).
4. Cho dãy a[1], a[2], ..., a[n] trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và a[i] + a[j] = M.

# **Tuần 5**
1. Cho đồ thị vô hướng G = (V,E). Viết chương trình kiểm tra xem G có phải là đồ thị Hamilton hay không.
2. Cho đồ thị vô hướng G = (V,E) trong đó V = {1,2,..,n} là tập hợp các nút và E là tập hợp m cạnh. Viết chương trình truy cập các nút của G bằng thuật toán DFS (xem xét thứ tự từ điển của các nút).
3. Cho đồ thị liên thông vô hướng G = (V,E) trong đó V={1,…,N}. Mỗi cạnh (u,v )∈ E(u,v)∈ E có trọng số w(u,v). Tính cây khung nhỏ nhất của G.
4. Cho đồ thị vô hướng G = (V,E) trong đó V = {1, 2, ..., n} là tập hợp các nút và E là tập hợp m cạnh. Viết chương trình tính toán chuỗi các nút được truy cập bằng thuật toán BFS (các nút .được xem xét theo thứ tự từ điển).
   
# **Tuần 6**
1. Cho đồ thị có hướng G = (V, E) trong đó V = {1, 2, ..., n} là tập hợp các nút và w(u,v) là trọng số (độ dài) của cung (u ,v). Tính d(u,v) là độ dài đường đi ngắn nhất từ u đến v trong G với mọi u,v trong V.
2. Cho mạng G = (V, E) là đồ thị có trọng số có hướng. Nút s là nguồn và nút t là đích. c(u,v) là dung lượng của cung (u,v). Tìm luồng cực đại trên G.
3. Cho đồ thị có hướng G = (V,E) trong đó V = {1,2,...,n} là tập hợp các nút. Mỗi cung (u,v) có trọng số không âm w(u,v). Cho hai nút s và t của G. Tìm đường đi ngắn nhất từ s đến t trên G.

# **Tuần 7**
1. Dữ liệu về doanh số bán hàng của một công ty thương mại điện tử (công ty thương mại điện tử có nhiều cửa hàng) gồm một dãy các dòng, mỗi dòng (đại diện cho một đơn hàng) có các thông tin sau: ID khách hàng, ID sản phẩm, Giá, ID cửa hàng, thời gian.
Thực hiện một chuỗi các truy vấn thuộc các loại sau:
    - ?total_number_orders: trả về tổng số đơn hàng
    - ?total_revenue: trả về tổng doanh thu mà công ty thương mại điện tử nhận được
    - ?revenue_of_shop (ShopID): trả lại tổng doanh thu mà shop (ShopID) nhận được
    - ?total_consume_of_customer_shop (CustomerID) (ShopID): trả về tổng doanh thu shop (ShopID) bán sản phẩm cho khách hàng (CustomerID)
    - ?total_revenue_in_ Period (from_time) (to_time): trả về tổng doanh thu mà thương mại điện tử nhận được trong khoảng thời gian từ (from_time) đến (to_time).
2. Dữ liệu về giao dịch ngân hàng bao gồm một chuỗi các giao dịch: thông tin của từng giao dịch có định dạng sau: \<from_account>\<to_account>\<money>\<time_point>\<atm>. Một chu kỳ giao dịch có độ dài k bắt đầu từ tài khoản a1 được xác định là một chuỗi các tài khoản riêng biệt a1, a2, …, ak trong đó có các giao dịch từ tài khoản a1 đến a2, từ a2 đến a3, …, từ ak đến a1.
Viết chương trình xử lý các truy vấn sau:
    - ?number_transactions: tính tổng số giao dịch của dữ liệu
    - ?total_money_transaction: tính tổng số tiền giao dịch
    - ?list_sorted_accounts: tính toán trình tự tài khoản ngân hàng (bao gồm tài khoản gửi và tài khoản nhận) xuất hiện trong giao dịch (sắp xếp theo thứ tự tăng dần theo bảng chữ cái)
    - ?total_money_transaction_from <tài khoản>: tính tổng số tiền được chuyển từ tài khoản <tài khoản>
    - ?inspect_cycle \<account> k : trả về 1 nếu có chu kỳ giao dịch có độ dài k bắt đầu từ \<account>, ngược lại trả về 0.

# **Tuần 8**
1. Dữ liệu gửi dự thi lập trình bao gồm một dãy các dòng, mỗi dòng có các thông tin sau: \<UserID>\<ProblemID>\<TimePoint>\<Status>\<Point> trong đó người dùng \<UserID> gửi mã của mình để giải quyết vấn đề \<ProblemID> tại thời điểm \<TimePoint> và nhận trạng thái \<Status> và điểm \<Point>. Người dùng có thể gửi mã để giải quyết từng vấn đề nhiều lần. Điểm mà người dùng nhận được cho một bài toán là điểm tối đa trong số các bài gửi cho bài toán đó. 
Thực hiện một chuỗi các truy vấn thuộc các loại sau:
    - ?total_number_submissions: trả về số lượng bài dự thi
    - ?number_error_submision: trả về số lượng bài gửi có trạng thái ERR
    - ?number_error_submision_of_user \<UserID>: trả về số lần gửi có trạng thái ERR của người dùng \<UserID>
    - ?total_point_of_user \<UserID>: trả về tổng điểm của người dùng \<UserID>
    - ?number_submission_ Period \<from_time_point>\<to_time_point>: trả về số lần gửi trong khoảng thời gian từ <from_time_point> đến <to_time_point>.

2. Cho một DataBase về công dân, thực hiện các truy vấn trên DataBase này. DataBase về công dân gồm các dòng, mỗi dòng là thông tin về một người và có dạng: \<code> <date_of_birth> <father_code> <mother_code> <is_alive> <mã vùng> trong đó
    - \<code>: mã định danh
    - <date_of_birth>: ngày sinh của người đó 
    - <father_code> và <mother_code>: mã của bố và mẹ là những chuỗi có độ dài 7 nếu mã là 0000000 thì người hiện tại không có thông tin về bố hoặc mẹ
    - <is_alive>: ‘Y’ nghĩa là người đó vẫn còn sống và ‘N’ nghĩa là người hiện tại đã chết
    - <zone_code>: mã vùng nơi người đó sinh sống. 
Danh sách các truy vấn bao gồm các lệnh sau:
    - NUMBER_PEOPLE: trả về số lượng người 
    - NUMBER_PEOPLE_BORN_AT \<date>: trả về số người có ngày sinh bằng \<date>
    - MOST_ALIVE_ANCESTOR \<code>: tìm tổ tiên cao nhất (xa nhất về khoảng cách thế hệ) của người \<code> nhất định. Trả về khoảng cách thế hệ giữa tổ tiên được tìm thấy và người đã cho
    - NUMBER_PEOPLE_BORN_BETWEEN <from_date> <to_date>: tính số người có ngày sinh trong khoảng từ <from_date> đến <to_date>
    - MAX_UNRELATED_PEOPLE: tìm một tập con gồm những người trong đó có hai người bất kỳ trong tập con đó không có cha/mẹ-con và kích thước của tập con đó là lớn nhất. Trả về kích thước của tập hợp con được tìm thấy.



    
   
 