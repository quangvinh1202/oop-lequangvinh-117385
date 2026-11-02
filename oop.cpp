#include<iostream>
using namespace std;
class phuong_tien{
	private:
		int ma_xe;
		string loai_xe;
		int gio_vao;
		int tg_do;
	public:
		phuong_tien();
		phuong_tien(int ma,string loai,int gio,int tg);
		
		int lay_ma_xe() const;
		string lay_loai_xe() const;
		double tinh_phi() const;
		void hien_thi() const;
		
};
phuong_tien::phuong_tien(){
	ma_xe=0;
	loai_xe="";
	gio_vao=0;
	tg_do=1;
}
phuong_tien::phuong_tien(int ma,string loai,int gio,int tg){
	ma_xe=ma;
	loai_xe=loai;
	gio_vao=gio
	tg_do=tg
}
void tinh_phi(){
    double dongia=0;     
    if(loaixe=="Car") dongia=6;
    if(loaixe=="Motorcycle") dongia=4;
    if(loaixe=="Bicycle") dongia=2;
    double phidoxe=0;
    for(int i=0;i<thoigiando;i++){
    int gio=(giovao+i)%24;
    if(i<2){
    if((gio>=6&&gio<10)||(gio>=15&&gio<19)) phidoxe += dongia*1.3;
    else phidoxe +=dongia*0.95;
         }
    }
}
class bai_xe{
	private:
		int ma_bai;
		char kich_thuoc;
		phuong_tien p1,p2,p3;
		bool co1,co2,co3;
	public:
		bai_xe();
		bai_xe(int ma,char kt);
		int lay_ma() const;
		bool them(phuong_tien v);
		bool xoa(int ma_xe) const;
		void hien_thi() const;
		bool co_loai(string loai, int& dem,double& tong) const;
};
bool bai_xe::them(phuong_tien v){
	int cap=(kich_thuoc=='S')?1:(kich_thuoc=='M')?2:3;
	if(cap>=1&&!co1){
		pt1=v;
		co1=true;
		return true;
	}
	if(cap>=2&&!co2){
		pt2=v;
		co2=true;
		return true;
	}
	if(cap>=3&&!co3){
		pt=v;
		co3=true;
		return true;
	}
	return false;
}
bool bai_xe::xoa(int ma_xe){
	if(co1&&pt.lay_ma_xe()==ma_xe){
		if(co2){
			pt1=pt2;
			if(co3){
				pt2=pt3;
				co3=false;
			}
			else co2=false;
		} else co1=false;
		return true;
	}
	if(co2&&pt2.lay_ma_xe()==ma_xe){
		if(co3){
			pt2=pt3;co3=false;
		}
		else co2=false;
		return true;
	}
	if(co3&&pt3.lay_ma_xe()==ma_xe){
		co3=false;
		return true;
	}
	return false;
}
bool bai_xe::chua(int ma_xe) const {
 if (co1 && pt1.lay_ma_xe() == ma_xe) return true;
 if (co2 && pt2.lay_ma_xe() == ma_xe) return true;
 if (co3 && pt3.lay_ma_xe() == ma_xe) return true;
 return false;
}

void bai_xe::hien_thi() const {
 int cap = (kich_thuoc == 'S') ? 1 : (kich_thuoc == 'M') ? 2 : 3;
 int so_xe = co1 + co2 + co3;
 cout << "Bai " << ma_bai << " [" << kich_thuoc << "] "
 << so_xe << "/" << cap << " xe\n";
 if (co1) pt1.hien_thi();
 if (co2) pt2.hien_thi();
 if (co3) pt3.hien_thi();
}

bool bai_xe::co_loai(string loai, int& dem, double& tong) const {
 dem = 0; tong = 0;
 if (co1 && pt1.lay_loai_xe() == loai) { ++dem; tong += pt1.tinh_phi(); }
 if (co2 && pt2.lay_loai_xe() == loai) { ++dem; tong += pt2.tinh_phi(); }
 if (co3 && pt3.lay_loai_xe() == loai) { ++dem; tong += pt3.tinh_phi(); }
 return dem > 0;
}
class SystemInterface{
	private:
		bai_xe bai1,bai2,bai3;
		bool co1,co2,co3;
		public:
			SystemInterface();
			void runMenu();
};
	
