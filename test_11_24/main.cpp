#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//void sort(int a[], int n) 
//{
//    int i, j, temp;
//    for (i = 0; i < n - 1; i++) 
//    {
//        for (j = 0; j < n - 1 - i; j++) 
//        {
//            if (a[j] > a[j + 1]) 
//            {
//                temp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = temp;
//            }
//        }
//    }
//}
//void PrintArr(int a[], int n);
//
//int main() 
//{
//    int n;
//    int a[10]; 
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);
//    }
//    sort(a, n);
//    for (int i = 0; i < n; i++) {
//        printf("%d", a[i]);
//        if (i < n - 1) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//    return 0;
//}

//#include <stdio.h>
//
//int main() 
//{
//    int n, i;
//    scanf("%d", &n);
//    int arr[1000];
//    for (i = 0; i < n; i++) 
//    {
//        scanf("%d", &arr[i]);
//    }
//    int min = arr[0];
//    int m = 0;
//    for (i = 1; i < n; i++) 
//    {
//        if (arr[i] < min) 
//        {
//            min = arr[i];
//            m = i;
//        }
//    }
//    printf("%d %d", min, m);
//    return 0;
//}

//#include <stdio.h>
//void insert(int a[], int n, int num) 
//{
//    int i;
//    for (i = n - 1; i >= 0 && a[i] > num; i--) 
//    {
//        a[i + 1] = a[i];
//    }
//    a[i + 1] = num;
//}
//int main() 
//{
//    int n, num;
//    scanf("%d", &n);
//    int arr[1001];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//    scanf("%d", &num);
//    insert(arr, n, num);
//    for (int i = 0; i < n; i++)
//    {
//        printf("%d", arr[i]);
//        if (i < n - 1)
//        {
//            printf(" ");
//        }
//    }
//    printf("\n");
//    return 0;
//}

//#include <stdio.h>
//void insert(int a[], int n, int num) {
//    int i;
//    for (i = n - 1; i >= 0 && a[i] > num; i--) {
//        a[i + 1] = a[i];
//    }
//    a[i + 1] = num;
//}
//void PrintArr(int a[], int n) {
//    int i;
//    for (i = 0; i < n; i++) {
//        printf("%d", a[i]);
//        if (i < n - 1) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//}
//int main() {
//    int n, num, i;
//    scanf("%d", &n);
//    int arr[1001]; 
//    for (i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//    scanf("%d", &num);
//    insert(arr, n, num);
//    PrintArr(arr, n + 1);
//    return 0;
//}

//void func(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//    int l1 = m - 1;
//    int l2 = n - 1;
//    int l3 = nums1Size - 1;
//    while (l1 >= 0 && l2 >= 0)
//    {
//        if (nums1[l1] >= nums2[l2])
//        {
//            nums1[l3--] = nums1[l1--];
//        }
//        else
//        {
//            nums1[l3--] = nums2[l2--];
//        }
//    }
//    while (l2 >= 0)
//    {
//        nums1[l3--] = nums2[l2--];
//    }
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    setvbuf(stdin, NULL, _IONBF, 0);
//    setvbuf(stdout, NULL, _IONBF, 0);
//    int m, n;
//    int i, j, k;
//    scanf("%d", &m);
//    int* a = (int*)malloc(m * sizeof(int));
//    for (i = 0; i < m; i++) {
//        scanf("%d", &a[i]);
//    }
//    scanf("%d", &n);
//    int* b = (int*)malloc(n * sizeof(int));
//    for (i = 0; i < n; i++) {
//        scanf("%d", &b[i]);
//    }
//    int* c = (int*)malloc((m + n) * sizeof(int));
//    i = m - 1;
//    j = 0;
//    k = 0;
//    while (i >= 0 && j < n) {
//        if (a[i] >= b[j]) {
//            c[k++] = a[i--];
//        }
//        else {
//            c[k++] = b[j++];
//        }
//    }
//    while (i >= 0) {
//        c[k++] = a[i--];
//    }
//    while (j < n) {
//        c[k++] = b[j++];
//    }
//    for (i = 0; i < m + n; i++) {
//        printf("%d", c[i]);
//        if (i != m + n - 1) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//    free(a);
//    free(b);
//    free(c);
//
//    return 0;
//}

//#include <stdio.h>
//#define MAX_SIZE 2000000  
//
//int main() {
//    int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
//    int m, n, total; 
//    int i, j, temp;
//    scanf("%d", &m);
//    for (i = 0; i < m; i++) {
//        scanf("%d", &a[i]);
//    }
//    scanf("%d", &n);
//    for (i = 0; i < n; i++) {
//        scanf("%d", &b[i]);
//    }
//    total = m + n;
//  
//    for (i = 0; i < m; i++) {
//        c[i] = a[i];
//    }
//   
//    for (i = 0; i < n; i++) {
//        c[m + i] = b[i];
//    }
//
//   
//    for (i = 0; i < total - 1; i++) {
//        int max_index = i;  
//        
//        for (j = i + 1; j < total; j++) {
//            if (c[j] > c[max_index]) {
//                max_index = j;
//            }
//        }
//       
//        temp = c[i];
//        c[i] = c[max_index];
//        c[max_index] = temp;
//    }
//
//    for (i = 0; i < total; i++) {
//        printf("%d", c[i]);
//        if (i != total - 1) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//
//    return 0;
//}

//#include <stdio.h>
//#define MAX_SIZE 2000000  
//
//int main() {
//    
//    int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
//    int m, n;  
//    int i = 0, j = 0, k = 0;  
//
//    
//    scanf("%d", &m);
//    for (i = 0; i < m; i++) {
//        scanf("%d", &a[i]);
//    }
//
//   
//    for (j = 0; j < n; j++) {
//        scanf("%d", &b[j]);
//    }
//
//    
//    i = m - 1;  
//    j = 0;      
//    k = 0;      
//
//   
//    while (i >= 0 && j < n) {
//        if (a[i] >= b[j]) {  
//            c[k] = a[i];
//            i--;  
//        }
//        else {
//            c[k] = b[j];
//            j++;  
//        k++;  
//    }
//
//   
//    while (i >= 0) {
//        c[k] = a[i];
//        i--;
//        k++;
//    }
//
//  
//    while (j < n) {
//        c[k] = b[j];
//        j++;
//        k++;
//    }
//
//    
//    for (int x = 0; x < k; x++) {
//        printf("%d", c[x]);
//        if (x != k - 1) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//
//    return 0;
//}

//#include <stdio.h>
//#define MAX_SIZE 2000000  
//
//int main() {
//    
//    int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
//    int m, n;  
//    int i = 0, j = 0, k = 0;  
//
//   
//    scanf("%d", &m);
//    for (i = 0; i < m; i++) {
//        scanf("%d", &a[i]);
//    }
//
//   
//    scanf("%d", &n);
//    for (j = 0; j < n; j++) {
//        scanf("%d", &b[j]);
//    }
//
//    
//    i = m - 1; 
//    j = 0;      
//    k = 0;     
//
//   
//    while (i >= 0 && j < n) {
//        if (a[i] >= b[j]) {  
//            c[k] = a[i];
//            i--;  
//        }
//        else {
//            c[k] = b[j];
//            j++;  
//        }
//        k++;  
//    }
//
//    
//    while (i >= 0) {
//        c[k] = a[i];
//        i--;
//        k++;
//    }
//
//    
//    while (j < n) {
//        c[k] = b[j];
//        j++;
//        k++;
//    }
//
//    
//    for (int x = 0; x < k; x++) {
//        printf("%d", c[x]);
//        if (x != k - 1) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//
//    return 0;
//}


//#include <stdio.h>
//#define MAX_SIZE 1000  
//
//int main() {
//    int arr[MAX_SIZE];
//    int n, i, j = 0; 
//
//    
//    scanf("%d", &n);
//    for (i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    
//    if (n == 0) {  
//        printf("0\n");
//        return 0;
//    }
//
//    
//    for (i = 1; i < n; i++) {
//        
//        if (arr[i] != arr[j]) {
//            j++;  
//            arr[j] = arr[i];  
//        }
//    }
//
//    
//    int new_len = j + 1;
//
//    
//    printf("%d\n", new_len);
//    for (i = 0; i < new_len; i++) {
//        printf("%d", arr[i]);
//        if (i != new_len - 1) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//
//    return 0;
//}


#include <stdio.h>
#define MAX_SIZE 1000000 

int main() {
    // 关闭输入输出缓冲，解决大数据量读写慢的核心问题
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    int arr[MAX_SIZE];
    int n, i, j = 0;

    // 快速读取数组长度（避免scanf冗余操作）
    scanf("%d", &n);
    // 批量读取数组元素（循环无冗余逻辑）
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 边界处理：数组为空直接输出（避免后续循环）
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    // 核心去重：双指针原地修改（无额外操作，最快逻辑）
    for (i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            arr[++j] = arr[i];  // 合并j++和赋值，减少指令
        }
    }

    int new_len = j + 1;

    // 输出优化：先输出长度，再批量输出数组（减少printf调用次数）
    printf("%d\n", new_len);
    for (i = 0; i < new_len; i++) {
        if (i > 0) printf(" ");  // 避免最后多输出空格，减少判断次数
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}