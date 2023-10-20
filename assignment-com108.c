#include<stdio.h>
#include<math.h>
#include<string.h>
    // kiem tra so hay chu
int kiemTra(){
    if (getchar() != '\n') {
       // fflush(stdin);
       while(getchar()!='\n');
        return 1;
    }
    return 0;
}
int chon(){
    fflush(stdin);
    printf("\nBam bat ki de thoat. Bam Enter de tiep tuc. ");
    if (getchar() == '\n') return 1;
    return 0;
}
void thongTin(){
    printf("\nBai ASSIGNMENT mon COM108-LAP TRINH CO BAN\n");
    printf("Ho va ten: DOAN DUY VAN\n");
    printf("MSSV: PS37009\n");
}
void menu(){

    printf("\n***************************MENU*****************************\n");
    printf("  Chuc nang 1: KIEM TRA SO NGUYEN.\n");
    printf("  Chuc nang 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO.\n");
    printf("  Chuc nang 3: TINH TIEN CHO QUAN KARAOKE.\n");
    printf("  Chuc nang 4: TINH TIEN DIEN.\n");
    printf("  Chuc nang 5: DOI TIEN.\n");
    printf("  Chuc nang 6: TINH LAI SUAT NGAN HANG VAY TRA GOP.\n");
    printf("  Chuc nang 7: VAY TIEN MUA XE.\n");
    printf("  Chuc nang 8: SAP XEP THONG TIN SINH VIEN.\n");
    printf("  Chuc nang 9: GAME FPOLY-LOTT(2/15).\n");
    printf("  Chuc nang 10: TINH PHAN SO.\n");
    printf("  Chuc nang 11: LOG IN.\n");
    printf("  Chuc nang 12: DANG KI.\n");
    printf("  Chuc nang 13: DANG XUAT.\n");
    printf("  CLEAR: Bam 14 de clear.\n");
    printf("  EXIT: BAM 0 DE THOAT.\n");
    printf("************************************************************\n");
}
int nguyenTo(float x){
	int i;
    if (x != (int)x || (int)x == 1) return 0;
	else {
        for (i = 2; i < x; i++) {
            if ((int)x % i == 0) return 0;
        }
        return 1;
    }
}
int chinhPhuong(float x){
	float y;
    if (x != (int)x) return 0;
	else {
        y = sqrt(x);
        if (y == (int)y) return 1;
		else return 0;
    }
}
int ucln(int a, int b){
	int x = a > b ? a : b;
	int y = a < b ? a : b;
	int temp;
    while (1) {
        if (x % y == 0) return y;
        else {
            temp = y;
            y = x % y;
            x = temp;
        }
    }
}
int bcnn(int a, int b){
	int x = a * b / ucln(a, b);
    return x;
}
float bai3(float a, float b){
	float dongia = 150.000;
	float tiengio = b - a;
	float thanhtoan;
    if (tiengio <= 3) {
        thanhtoan = tiengio * dongia;
        if ((int)a >= 14 && (int)a < 18) {
            thanhtoan *= 0.9;
            return thanhtoan;
        }else return thanhtoan;
    } else {
        thanhtoan = 3 * dongia + (tiengio - 3) * dongia * 0.7;
        if ((int)a >= 14 && (int)a < 18) {
            thanhtoan *= 0.9;
            return thanhtoan;
        }else return thanhtoan;
    }
}
float bai4(int a){
	float thanhtoan = 0;
	float bac1 = 50 * 1.678;
	float bac2 = 50 * 1.734;
	float bac3 = 100 * 2.014;
	float bac4 = 100 * 2.536;
	float bac5 = 100 * 2.834;
    if (a <= 50) thanhtoan = a * 1.678;
    else if (a <= 100) thanhtoan = bac1 + ((a - 50) * 1.734);
    else if (a <= 200) thanhtoan = bac1 + bac2 + ((a - 100) * 2.014);
    else if (a <= 300) thanhtoan = bac1 + bac2 + bac3 + ((a - 200) * 2.536);
    else if (a <= 400) thanhtoan = bac1 + bac2 + bac3 + bac4 + ((a - 300) * 2.834);
    else thanhtoan = bac1 + bac2 + bac3 + bac4 + bac5 + ((a - 400) * 2.927);
    return thanhtoan;
}
void bai6(int x){
	int tg = x / 12, tl, tt;
	int i;
    printf("ky han	lai phai tra	goc phai tra	so tien 	con lai\n");
    for (i = 1; i <= 12; i++) {
        tl = x * 0.05;
        tt = tg + tl;
        x -= tg;
        printf("  %d	%d		%d		%d		%d \n", i, tl, tg, tt, x);
    }
}
struct sinhVien{
	char hoten[30];
	float diem;
};
typedef struct sinhVien dSv;
struct PhanSo{
	int t, m;
};
typedef struct PhanSo PhanSo;
int num(){
	int n;
    scanf("%d",& n);
    return n;
}
void nhap(dSv a[], int n){
	int i;
    for (i = 0; i < n; i++) {
        getchar();
        printf("Nhap Ho Ten: ");
        gets(a[i].hoten);
        printf("Nhap diem: ");
        scanf("%f",& a[i].diem);
    }
}
void xuat(dSv a[], int n){
	int i;
    for (i = 0; i < n; i++) {
        printf("\n");
        if (a[i].diem <= 10 && a[i].diem >= 9)
            printf("Ten SV la: %s. Diem: %.1f. Hoc luc xuat sac", a[i].hoten, a[i].diem);
        else if (a[i].diem <= 10 && a[i].diem >= 8)
            printf("Ten SV la: %s. Diem: %.1f. Hoc luc gioi", a[i].hoten, a[i].diem);
        else if (a[i].diem <= 10 && a[i].diem >= 6.5)
            printf("Ten SV la: %s. Diem: %.1f. Hoc luc kha", a[i].hoten, a[i].diem);
        else if (a[i].diem <= 10 && a[i].diem >= 5)
            printf("Ten SV la: %s. Diem: %.1f. Hoc luc trung binh", a[i].hoten, a[i].diem);
        else if (a[i].diem <= 5 && a[i].diem >= 0)
            printf("Ten SV la: %s. Diem: %.1f. Hoc luc yeu", a[i].hoten, a[i].diem);
        else printf("Ten SV la: %s. Diem: %.1f. Ban la SuperMan", a[i].hoten, a[i].diem);
        printf("\n");
    }
}
void sortsv(dSv a[], int n){
	int i, j, max;
	dSv temp;
    for (i = 0; i < n; i++) {
        max = i;
        for (j = i + 1; j < n; j++) {
            if (a[j].diem > a[max].diem) max = j;
        }
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;

    }
}
void nhapPhanSo(PhanSo * a){

    printf("Nhap phan so (a/b): ");
    scanf("%d/%d",& a -> t,& a -> m);


}
void xuatPhanSo(PhanSo a){
    printf("%d/%d", a.t, a.m);
}
PhanSo tong2PhanSo(PhanSo a, PhanSo b){
	PhanSo tong;
    if (a.m == b.m) {
        tong.t = a.t + b.t;
        tong.m = a.m;
        return tong;
    } else {
        tong.m = a.m * b.m;
        tong.t = a.t * b.m + b.t * a.m;
        return tong;
    }
}
PhanSo hieu2PhanSo(PhanSo a, PhanSo b){
	PhanSo hieu;
    if (a.m == b.m) {
        hieu.t = a.t - b.t;
        hieu.m = a.m;
        return hieu;
    } else {
        hieu.m = a.m * b.m;
        hieu.t = a.t * b.m - b.t * a.m;
        return hieu;
    }
}
PhanSo tich2PhanSo(PhanSo a, PhanSo b){
	PhanSo tich;
    tich.t = a.t * b.t;
    tich.m = a.m * b.m;
    return tich;
}
PhanSo thuong2PhanSo(PhanSo a, PhanSo b){
	PhanSo thuong;
    thuong.t = a.t * b.m;
    thuong.m = a.m * b.t;
    return thuong;
}
PhanSo rutGon(PhanSo a){
	PhanSo rutGon;
	int uc = ucln(a.t, a.m);
    rutGon.t = a.t / uc;
    rutGon.m = a.m / uc;
    return rutGon;
}
struct user{
	char tk[50];
	char mk[50];
};
typedef struct user user;
int logIn(user people[50]){
	int i;
	user temp;
    printf("Dang nhap.\n");
    printf("Nhap tai khoan: ");
    gets(temp.tk);
    printf("Nhap mat khau: ");
    gets(temp.mk);
    for (i = 0; i < 50; i++) {
        if (strcmp(temp.tk, people[i].tk) == 0) {
            if (strcmp(temp.mk, people[i].mk) == 0) {
                printf("\nDang nhap thanh cong!\n");
                return 1;
            }
        }
    }
    printf("\nSai toan khoan hoac mat khau!\n");
    return 0;
}
void dangKi(user people[50], int * sl){
	int	numuser =* sl, i;
	user temp;
    printf("Dang ki tai khoan.\n");
    printf("Tai khoan: ");
    gets(temp.tk);
    printf("Mat khau: ");
    gets(temp.mk);
    for (i = 0; i < 50; i++) {
        if (strcmp(temp.tk, people[i].tk) == 0) {
            printf("\nTai khoan da ton tai!\n");
            return;
        }
    }
    strcpy(people[numuser + 1].tk, temp.tk);
    strcpy(people[numuser + 1].mk, temp.mk);
    (* sl)++;
    printf("\nDang ki thanh cong!\n");
}
// main---------------------------------------------------------------------------

int main(){
	int z;
	int io = 0, sl = 0;
	int x, a, b, n;
	float x1, a1, b1;
	user people[50];
    strcpy(people[0].tk, "admin");
    strcpy(people[0].mk, "123");
    // menu chuong trinh
    thongTin();
    do {
        menu();
        do {
            printf("Moi ban chon chuc nang: ");
            scanf("%d",& z);
        } while (kiemTra() || !(z >= 0 && z < 15));
        printf("\n");
        switch (z) {
            case 14: {
            	// chuc nang clean danh cho windows
                system("cls");
                thongTin();
                break;
            }
            case 0: {
                break;
            }
            // bai 1:
            case 1: {
                //1
                if (io == 0) {
                    printf("Vui long dang nhap!\n");
                    break;
                }
                printf("1. Kiem tra so nguyen.\n");
                do {
                    printf("nhap X: ");
                    scanf("%f",& x1);
                } while (kiemTra());
                if (x1 != (int)x1) printf("Day khong phai la so nguyen.\n");
		    else {
                    if (x1 < 0) printf("Day la so nguyen am.\n");
                    else printf("Day la so nguyen duong.\n");
                }
                if (nguyenTo(x1) == 1) printf("Day la so nguyen to.\n");
                else printf("Day khong phai la so nguyen to.\n");
                if (chinhPhuong(x1) == 1) printf("Day la so chinh phuong.\n");
                else printf("Day khong phai la so chinh phuong.\n");
                z = chon();
                //1
                break;
            }
            // bai 2:
            case 2: {
                //2
                if (io == 0) {
                    printf("Vui long dang nhap!\n");
                    break;
                }
                printf("2. Tim uoc chung lon nhat cua hai so.\n");
                do {
                    printf("Nhap A: ");
                    scanf("%d",& a);
                } while (kiemTra() || a <= 0);
                do {
                    printf("Nhap B: ");
                    scanf("%d",& b);
                } while (kiemTra() || b <= 0);
                printf("\n");
                printf("\bUCLN cua %d va %d la: %d\n", a, b, ucln(a, b));
                printf("\bBCNN cua %d va %d la: %d\n", a, b, bcnn(a, b));
                z = chon();
                //2
                break;
            }
            // bai3:
            case 3: {
                //3
                if (io == 0) {
                    printf("Vui long dang nhap!\n");
                    break;
                }
                printf("3. Tinh tien cho quan Karaoke.\n");
                do {
                    printf("Gio vao: ");
                    scanf("%d",& a);
                } while (kiemTra() || !(a >= 12 && a < 23));
                do {
                    printf("Gio ra: ");
                    scanf("%d",& b);
                } while (kiemTra() || !(b > a && b <= 23));
                printf("\nSo tien phai thanh toan la: %.3f VND.", bai3(a, b));
                z = chon();
                //3
                break;
            }
            //bai4:
            case 4: {
                //4
                if (io == 0) {
                    printf("Vui long dang nhap!\n");
                    break;
                }
                printf("4. Tinh tien dien.\n");
                do {
                    printf("So dien su dung (kWh): ");
                    scanf("%d",& x);
                } while (kiemTra() || x < 0);
                printf("So tien phai thanh toan la: %.3f VND.", bai4(x));
                printf("\n");
                z = chon();
                //4
                break;
            }
            // bai5:	
            case 5: {
                if (io == 0) {
                    printf("Vui long dang nhap!\n");
                    break;
                }
                printf("5. Chuc nang tam khoa. vui long chon chuc nang khac!\n");
                z = chon();
                break;
            }
            // bai6:
            case 6: {
                //6
                if (io == 0) {
                    printf("Vui long dang nhap!\n");
                    break;
                }
                printf("6. Tinh lai suat ngan hang.\n");
                do {
                    printf("Nhap so tien ban muon vay: ");
                    scanf("%d",& x);
                } while (kiemTra() || !x > 0);
                bai6(x);
                z = chon();
                //6
                break;
            }
            case 7: {
                if (io == 0) {
                    printf("Vui long dang nhap!\n");
                    break;
                }
                printf("7. Chuc nang tam khoa. vui long chon chuc nang khac!\n");
                z = chon();
                break;
            }
            case 8: {
                // 8
                if (io == 0) {
                    printf("Vui long dang nhap!\n");
                    break;
                }
                printf("8. Thong tin sinh vien.\n"); printf("\n");
                printf("Nhap so luong sinh vien: ");
                n = num();
                dSv sv[n];
                printf("\n");
                nhap(sv, n);
                sortsv(sv, n);
                xuat(sv, n);
                z = chon();
                // 8
                break;
            }
            case 9: {
                if (io == 0) {
                    printf("Vui long dang nhap!\n");
                    break;
                }
                printf("9. Chuc nang tam khoa. vui long chon chuc nang khac!\n");
                z = chon();
                break;
            }
            case 10: {
                if (io == 0) {
                    printf("Vui long dang nhap!\n");
                    break;
                }
            PhanSo a, b;
                nhapPhanSo(& a);
                nhapPhanSo(& b);
                printf("\n");
                xuatPhanSo(a); printf(" + "); xuatPhanSo(b); printf(" = "); xuatPhanSo(tong2PhanSo(a, b)); printf(" => "); xuatPhanSo(rutGon(tong2PhanSo(a, b)));
                printf("\n");
                xuatPhanSo(a); printf(" - "); xuatPhanSo(b); printf(" = "); xuatPhanSo(hieu2PhanSo(a, b)); printf(" => "); xuatPhanSo(rutGon(hieu2PhanSo(a, b)));
                printf("\n");
                xuatPhanSo(a); printf(" * "); xuatPhanSo(b); printf(" = "); xuatPhanSo(tich2PhanSo(a, b)); printf(" => "); xuatPhanSo(rutGon(tich2PhanSo(a, b)));
                printf("\n");
                xuatPhanSo(a); printf(" / "); xuatPhanSo(b); printf(" = "); xuatPhanSo(thuong2PhanSo(a, b)); printf(" => "); xuatPhanSo(rutGon(thuong2PhanSo(a, b)));
                printf("\n");
                z = chon();
                break;
            }
            case 11: {
                if (io == 1) {
                    printf("Ban da dang nhap!\n");
                    break;
                }
                io = logIn(people);
                break;
            }
            case 12: {
                dangKi(people,& sl);
                break;
            }
            case 13: {
                if (io == 1) {
                    io = 0;
                    printf("Dang xuat thanh cong!\n");
                } else printf("Ban chua dang nhap!\n");
                break;
            }
            default: {
                printf("Vui long nhap lai!");
                break;
            }
        }
    } while (z != 0);
    printf("\n\tCAM ON QUY KHACH DA SU DUNG DICH VU!");
    return 0;
}


