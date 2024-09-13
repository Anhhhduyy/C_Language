#include <stdio.h>
#include <stdint.h>

int GIO_HANG = 0; // 0000 0000
typedef enum{
    AO = 1 <<0, // 0000 0001
    QUAN = 1 << 1, // 0000 0010
    VAY = 1 << 2, // 0000 0100
    DAM = 1 << 3, // 0000 1000
    NHAN = 1 << 4, // 0001 0000
    VONG_TAY = 1 << 5, // 0010 0000
    GIAY = 1 << 6, // 0100 0000
    TUI = 1 << 7 // 1000 0000
}DO_DUNG_CA_NHAN;

int main(){
    //Thêm vào giỏ hàng: phép or
    GIO_HANG = GIO_HANG | AO; // 0000 0001
    GIO_HANG |= NHAN; // 0000 0001 | 0001 0000 = 0001 0001
    //Xóa khỏi giỏ hàng (đảo lại)
    GIO_HANG = GIO_HANG & (~AO); // 0001 0001 & (~(0000 0001) = 1111 1110) = 0001 0000
    //GIO_HANG &= ~AO; cách 2
    if(GIO_HANG & NHAN ){
        printf("co ao");
    }
    else printf("No");
    return 0;
}