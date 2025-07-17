#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    float price;
    int quantity;
} Product;

typedef struct SNodeProduct {
    Product product;
    struct SNodeProduct *next;
} SNodeProduct;

typedef struct DNodeProduct {
    Product product;
    struct DNodeProduct *next;
    struct DNodeProduct *prev;
} DNodeProduct;

//
SNodeProduct *head = NULL;
DNodeProduct *tail = NULL;
//
void deplayMenu() {
    printf("\n-----Menu-----\n");
    printf("1. Them san pham\n");
    printf("2. Hien thi danh sach san pham\n");
    printf("3. Xoa san pham\n");
    printf("4. Cap nhat thong tin san pham\n");
    printf("5. Danh dau san pham da ban\n");
    printf("6. Hien thi danh sach san pham da ban\n");
    printf("7. Sap xep san pham theo gia tang dan\n");
    printf("8. Tim kiem san pham theo ten\n");
    printf("9. Thoat chuong trinh\n");
    printf("\n Lua chon cua ban: ");
}

//
int addID(int id) {
    SNodeProduct *temp = head;
    while (temp != NULL) {
        if (temp->product.id == id) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

//
void addProduct() {
    Product prod;
    do {
        printf("Nhap Id: ");
        scanf("%d", &prod.id);
        getchar();
    } while (addID(prod.id));

    printf("Nhap ten san pham: ");
    fgets(prod.name, 100, stdin);
    prod.name[strcspn(prod.name, "\n")] = '\0';

    printf("Nhap gia tien san pham: ");
    scanf("%f", &prod.price);
    getchar();
    do {
        printf("Nhap so luong ton kho: ");
        scanf("%d", &prod.quantity);
        getchar();
    } while (prod.quantity < 0);

    SNodeProduct *newNode = (SNodeProduct *) malloc(sizeof(SNodeProduct));
    newNode->product = prod;
    newNode->next = head;
    head = newNode;

    printf("Them thanh cong san pham\n");
}

//
void deplayProduct() {
    SNodeProduct *temp = head;
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Price: %.3f | Quantity: %d\n",
               temp->product.id, temp->product.name, temp->product.price, temp->product.quantity);
        temp = temp->next;
    }
}

//
void deSNodeProduct() {
    int id;
    printf("Nhap Id ban muon xoa: ");
    scanf("%d", &id);

    SNodeProduct *temp = head, *prev = NULL;
    while (temp != NULL && temp->product.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong ton tai trong kho\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Xoa thanh cong\n");
}

//
void updataSnodeProduct() {
    int id;
    printf("Nhap Id san pham ban can cap nhat: ");
    scanf("%d", &id);
    SNodeProduct *temp = head;
    while (temp != NULL && temp->product.id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong ton tai trong kho\n");
        return;
    }
    getchar();
    printf("Nhap ten san pham moi: ");
    fgets(temp->product.name, 100, stdin);
    temp->product.name[strcspn(temp->product.name, "n")] = '\0';

    printf("Nhap gia tien san pham moi: ");
    scanf("%f", &temp->product.price);

    printf("Nhap so luong san pham: ");
    scanf("%d", &temp->product.quantity);

    printf("Da cap nhat thanh cong\n");
}

//
void updataDNodeProduct() {
    int id;
    printf("Nhap Id ban can danh dau: ");
    scanf("%d", &id);
    SNodeProduct *temp = head, *prev = NULL;
    while (temp != NULL && temp->product.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong ton tai trong kho\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    DNodeProduct *newNode = (DNodeProduct *) malloc(sizeof(DNodeProduct));
    newNode->product = temp->product;
    newNode->next = tail;
    newNode->prev = NULL;
    if (tail == NULL) {
        tail->next = newNode;
    }
    tail = newNode;
    free(temp);
    printf("Da dau thanh cong\n");
}

//
void deplayDNodeProduct() {
    if (tail == NULL) {
        printf("Khong ton tai trong kho\n");
        return;
    }
    DNodeProduct *temp = tail;
    while (temp != NULL) {
        printf("Id: %d | Name: %s | Price: %.3f | Quantity: %d",
               temp->product.id, temp->product.name, temp->product.price, temp->product.quantity);
        temp = temp->next;
    }
}

//
void searchProduct() {
    char name[100];
    getchar();
    printf("Nhap ten can tim kiem: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "n")] = '\0';

    SNodeProduct *temp = head;
    int count = 0;
    while (temp != NULL) {
        if (strstr(temp->product.name, name) != NULL) {
            printf("Id: %d | Name: %s | Price: %.3f | Quantity: %d",
                temp->product.id, temp->product.name, temp->product.price, temp->product.quantity);
            count++;
        }
        temp = temp->next;
    }
    if (count == 0) {
        printf("Khong ton tai trong kho\n");
    }
}
//
int main() {
    int choice;
    do {
        deplayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addProduct();
                break;
            case 2:
                deplayProduct();
                break;
            case 3:
                deSNodeProduct();
                break;
            case 4:
                updataSnodeProduct();
                break;
            case 5:
                updataDNodeProduct();
                break;
            case 6:
                deplayDNodeProduct();
                break;
            case 7:
                break;
            case 8:
                searchProduct();
                break;
            case 9:
                printf("Dang thoat chuong trinh\n");
                break;
        }
    } while (choice != 9);
    return 0;
}
