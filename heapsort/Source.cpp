#include <iostream>
using namespace std;
void printArray(int arr[], int n);
void heapify(int arr[], int n, int i)
{
    int largest = i;
    // �������������� ���������� ������� ��� ������
    int l = 2 * i + 1; // ����� = 2*i + 1
    int r = 2 * i + 2; // ������ = 2*i + 2

 // ���� ����� �������� ������� ������ �����
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // ���� ����� ������� ������� �� ������
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // ���������� ����������� � �������� ���� ���������� ���������
        heapify(arr, n, largest);
    }
}
void hep(int arr[],int n) {
    int i = 0;
    int k = 1;
    while (i < n) {
        while ((i < k) && (i < n)) {
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
        k = k * 2 + 1;
    }
    cout << "-------------------" << endl;
}
// �������� �������, ����������� ������������� ����������
void heapSort(int arr[], int n)
{
    // ���������� ���� (�������������� ������)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        hep(arr, n);
    
        //printArray(arr, n);//� ���� �������
    }
    cout << "�������� ������: ";
    printArray(arr, n);
    cout << endl;
    cout << "������ ����������: " << endl;
    // ���� �� ������ ��������� �������� �� ����
    for (int i = n - 1; i >= 0; i--)
    {
        
        // ���������� ������� ������ � �����
        swap(arr[0], arr[i]);

        // �������� ��������� heapify �� ����������� ����
        heapify(arr, i, 0);
        //hep(arr, i); //� ���� �������� 
        printArray(arr, i); //� ���� �������
       
    }
    
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int arr[] = { -9, -3, 4, -10, -1, -6, 8, 8, -8, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "�������� ������:";
    printArray(arr, n);
    cout << "------------------------" << endl;
    cout << "������ �� ������� ������� ��������:" << endl;
    cout << "------------------------" << endl;

    heapSort(arr, n);

    cout << "��������������� ������: \n";
    printArray(arr, n);
    system("pause");
}


