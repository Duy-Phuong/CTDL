#include <stdio.h>

void XuatFile(char* tenFile, float* arr, int n)
{
	//mo file de ghi
	FILE* fo = fopen(tenFile, "wt"); // wt = write (ghi) + text (dang van ban)
	//ghi du lieu ra file
	for (int i = 0; i < n; i++)
	{
		fprintf(fo, "%0.1f ", arr[i]);
	}
	// dong file
	fclose(fo);
}

void XuatFileTong(char* tenFile, float* arr, int n)
{
	//mo file de ghi
	FILE* fo = fopen(tenFile, "wt"); // wt = write (ghi) + text (dang van ban)
	//ghi du lieu ra file
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		s+=arr[i];
	}

	fprintf(fo, "tong: %0.1f ", s);
	// dong file
	fclose(fo);
}

void XuatFileLe(char* tenFile, float* arr, int n)
{
	//mo file de ghi
	FILE* fo = fopen(tenFile, "wt"); // wt = write (ghi) + text (dang van ban)
	//ghi du lieu ra file
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			fprintf(fo, "%0.1f ", arr[i]);
		}
	}
		
	// dong file
	fclose(fo);
}

int Tong(int* a, int n)
{
	if (n == 0)
		return 0;
	return Tong(a, n - 1) + a[n-1];
}
int Tich(int* a, int n)
{
	if (n == 0)
		return 1;
	return Tich(a, n - 1) * a[n-1];
}
int TongLe(int* a, int n)
{
	if (n == 0)
		return 0;
	else
	{
		if (a[n - 1] % 2 == 1)
			return TongLe(a, n - 1) + a[n - 1];
		else
			return TongLe(a, n - 1) + 0;
	}
}
void main()
{
	//// MANG 2 CHIEU
	//int m, n;
	//printf("Nhap so dong: ");
	//scanf("%d", &m);
	//printf("Nhap so cot: ");
	//scanf("%d", &n);
	//int**  a = new int*[m];
	//for (int i = 0; i < m; i++)
	//	a[i] = new int[n];
	////dung vong lap de nhap cac gia tri a[i]
	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		printf("Nhap a[%d][%d]: ", i, j);
	//		scanf("%d", &a[i][j]);
	//	}
	//}
	//printf("\nmang 2 chieu:\n");
	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		printf("%d \t", a[i][j]);
	//	}
	//	printf("\n");
	//}

	
	// nhap xuat file
	// mo file de doc
	//FILE* fi = fopen("1512418.txt", "rt");
	////doc du lieu
	//int n;
	//fscanf(fi, "%d", &n);
	//float* arr = new float[n];
	//for (int i = 0; i < n; i++)
	//	fscanf(fi, "%f", &arr[i]);
	////dong file
	//fclose(fi);
	//// in ra man hinh de kiem tra
	//for (int i = 0; i < n; i++)
	//	printf("%0.1f ", arr[i]);
	//printf("\n");
	//// xuat ra file
	//XuatFile("out_1512418.txt", arr, n);
	//XuatFileLe("so_le.txt", arr, n);
	//XuatFileTong("tong_mang.txt", arr, n);

	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	printf("%d\n", Tong(a, n));
	printf("%d\n", Tich(a, n));
	printf("%d\n", TongLe(a, n));
}