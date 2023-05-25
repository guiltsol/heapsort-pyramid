#include <iostream>
using namespace std;
void printArray(int arr[], int n);
void heapify(int arr[], int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
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
// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        hep(arr, n);
    
        //printArray(arr, n);//В виде массива
    }
    cout << "Пирамида готова: ";
    printArray(arr, n);
    cout << endl;
    cout << "Начало сортировки: " << endl;
    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
        //hep(arr, i); //В виде пирамиды 
        printArray(arr, i); //В виде массива
       
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
    cout << "Исходный массив:";
    printArray(arr, n);
    cout << "------------------------" << endl;
    cout << "Делаем из данного массива пирамиду:" << endl;
    cout << "------------------------" << endl;

    heapSort(arr, n);

    cout << "Отсортированный массив: \n";
    printArray(arr, n);
    system("pause");
}


