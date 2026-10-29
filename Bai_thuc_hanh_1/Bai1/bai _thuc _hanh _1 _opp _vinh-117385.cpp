
#include <iostream>
#include<string>
using namespace std;

class Xe{
private:
	int maXe;
	string loaiXe;
	int gioVao;
	int thoiGianDo;
	double phiDoXe;
	bool dangChiemCho;
public:
	Xe() {
		maXe = 0;
		loaiXe = "";
		gioVao = 0;
		thoiGianDo = 1;
		phiDoXe = 0;
		dangChiemCho = false;
	}
	Xe(
	int ma,
	const string&loai,
	int gio,
	int thoiLuong
	);
	int layMaXe() const 
	{ 
		return maXe;
	};
	string layLoaiXe() const 
	{
		return loaiXe;
	};
	int layGioVao() const
	{
		return gioVao;
	};
	int layThoiGianDo() const
	{
		return thoiGianDo;
	};
	double layPhiDoXe() const
	{
		return phiDoXe;
	};
	bool layDangChiemCho() const
	{
		return dangChiemCho;
	};


	void ganMaXe(int ma) 
	{
		
		maXe = ma;
	};
	void ganLoaiXe(const string& loai)
	{
		if (laLoaiXeHopLe (loai)) {
			loaiXe=chuanHoaLoaiXe(loai);
		}
	}
	void ganGioVao(int gio) 
	{
		if (gio >= 0 && gio <= 23) {
			gioVao = gio;
		}
	}
	void ganThoiLuongDo(int thoiLuong)
	{
		if (thoiLuong >= 1 && thoiLuong <= 23) {
			thoiGianDo = thoiLuong;
		}
	}
	void ganPhiDoXe(double phi)
	{
		phiDoXe = phi;
	}
	void ganDangChiemCho(bool trangThai) {
		dangChiemCho=trangThai;
	}
	static string chuanHoaLoaiXe(string loai)
	{
		string s = loai;
		for (int i = 0; i < s.length(); i++) {
			s[i] = tolower(s[i]);
		}
		if (s == "car")return "Car";
		if (s == "motorcycle") return "Motorcycle";
		if (s == "bicycle") return "Bicycle";
		return "";
	};
	static bool laLoaiXeHopLe(const string& loai)
	{
		return chuanHoaLoaiXe(loai) != "";
	}
	void tinhPhiDoXe() 
	{
		double donGia = 0;
		if (loaiXe == "Car") donGia = 6.0;
		else if (loaiXe == "Mortorcycle") donGia = 4.0;
		else if (loaiXe == "Bicycle") donGia = 2.0;
		bool gioCaoDiem = false;
		if ((gioVao >= 6 && gioVao <= 9) ||
			(gioVao >= 15 && gioVao <= 18))
		{
			gioCaoDiem = true;
		}
		double haiGioDau;
		if (gioCaoDiem == true) {
			haiGioDau = 1.30;
		}
		else {
			haiGioDau = 0.95;
		}
		int gioDau;
		int gioSau;
		if (thoiGianDo <= 2) {
			gioDau = thoiGianDo;
			gioSau = 0;
		}
		else {
			gioDau = 2;
			gioSau = thoiGianDo - 2;
		}
		double phiGioDau = gioDau * donGia*haiGioDau;
		double phiGioSau = gioSau * donGia*0.90;
		phiDoXe = phiGioDau + phiGioSau;


	}
	void hienThi() const 
	{
		cout << "Ma xe: " << maXe << "\n"
			<< "Loai xe: " << loaiXe << "\n"
			<< "Gio vao: " << gioVao << "\n"
			<< "Thoi gian do: " << thoiGianDo << "\n"
			<< "Phi: " << phiDoXe << "\n" << endl;
	}
	

};
Xe::Xe(int ma, const string& loai, int gio, int thoiLuong) {
	maXe = ma;
	loaiXe = "";
	gioVao = 0;
	thoiGianDo = 1;
	phiDoXe = 0;
	dangChiemCho = true;
	ganLoaiXe(loai);
	ganGioVao(gio);
	ganThoiLuongDo(thoiLuong);
	tinhPhiDoXe();
}

int main()
{
	int ma, gio, thoiLuong;
	string loai;

	cout << "Nhap ma xe: ";
	cin >> ma;

	cout << "Nhap loai xe (Car/Motorcycle/Bicycle): ";
	cin >> loai;
	while (!Xe::laLoaiXeHopLe(loai)) {
		cout << "Loai xe khong hop le, nhap lai: ";
		cin >> loai;
	}

	cout << "Nhap gio vao: ";
	cin >> gio;
	while (gio < 0 || gio > 23) {
		cout << "Gio vao khong hop le ";
		cin >> gio;
	}

	cout << "Nhap thoi gian do";
	cin >> thoiLuong;
	while (thoiLuong < 1 || thoiLuong > 23) {
		cout << "Thoi gian do khong hop le ";
		cin >> thoiLuong;
	}

	Xe xe(ma, loai, gio, thoiLuong);
	xe.hienThi();

	return 0;
}

