#include <chrono>
#include <iostream>
#define MAX 100000
using namespace std;
using namespace std::chrono;
//*******************************************

template <class T> void printArray(T arr[], int n) {
  for (int i = 0; i < n; ++i) {
    if (i == n - 1) {
      cout << arr[i] << endl;
    } else {
      cout << arr[i] << ',';
    }
  }
  cout << endl;
}


//*******************************************

int randomNum(int min, int max) {
  int range = max - min + 1;
  return (rand() % (range + min));
}
//*******************************************

template <class T> void selectionSortAscendente(T arr[], int n) {
  int i, j, min;
  for (i = 0; i < n; i++) {
    min = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min])
        min = j;
    swap(arr[i], arr[min]);
  }
}
//*******************************************

template <class T> void selectionSortDescendente(T arr[], int n) {
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] < arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
//*******************************************

template <class T> void insertionSortAscendente(T arr[], int n) {
  int i, j;
  T temp;

  for (int i = 1; i < n; ++i) {
    temp = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = temp;
  }
}
//*******************************************

//******************************************* 

template <typename T> void countSortAscendente(T array[], int size) {
  int output[MAX];
  int count[MAX];
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  } 

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}
//*******************************************
template <typename T> void countSortDescendente(T array[], int size) {
  int output[MAX];
  int count[MAX];
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  } 
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }
  for (int i = 0; i < size; i++) {
    output[count[array[i]] + 1] = array[i];
    count[array[i]]--;
  }
  for (int i = 0; i < size; i++) {
    array[i] = output[size-i];
  }
}
//*******************************************
template <typename T> void bubbleSortAscendente(T arr[], T n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
}

//*******************************************

template <typename T> void bubbleSortDescendente(T arr[], T n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j + 1] > arr[j])
        swap(arr[j + 1], arr[j]);
}

//*******************************************
// Merged
template <typename T> void mergeAscendente(T arr[], T p, T q, T n) {
  
  int n1 = q - p + 1;
  int n2 = n - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

template <typename T >void mergeSortAscendente(T arr[], T l, T n) {
  if (l < n) {
    // m is the point where the array is divided into two subarrays
    int m = l + (n - l) / 2;

    mergeSortAscendente(arr, l, m);
    mergeSortAscendente(arr, m + 1, n);

    // Merge the sorted subarrays
    mergeAscendente(arr, l, m, n);
  }
}





void mergeDescendente(int array[], int low, int high, int mid){

  int i=low,j=mid+1,k=0;
  int temp[high-low+1];
  
  while(i<=mid && j<= high){
    if(array[i]>array[j])            //comparison step
      temp[k++]=array[i++];
    else
      temp[k++]=array[j++];
  }
  while(i<=mid){
    temp[k++]=array[i++];
  }
  while(j<=high){
    temp[k++]=array[j++];
  }
  
  for(i=low;i<=high;i++){
  
      array[i]=temp[i-low];
  
  }
return;
}


void mergeSortDescendente(int array[],int low, int high){
  int mid;
  if(low<high){
      mid=(low+high)/2;
  
      mergeSortDescendente(array,low,mid);
      mergeSortDescendente(array,mid+1,high);
      mergeDescendente(array,low,high,mid);
  }
return;
}

//*******************************************

int main() {
  // srand(time(NULL));

  // Arrays de ints*********************************
  int arrayCien[100];
  int arrayMil[1000];
  int arrayDmil[10000];
  int arrayCmil[100000];
  int arrayMillon[1000000];
  int arrayDmillon[10000000];

  for (int i = 0; i < 100; i++) {
    arrayCien[i] = randomNum(0, 999);
  }
  for (int i = 0; i < 1000; i++) {
    arrayMil[i] = randomNum(0, 999);
  }
  for (int i = 0; i < 10000; i++) {
    arrayDmil[i] = randomNum(0, 999);
  }
  for (int i = 0; i < 100000; i++) {
    arrayCmil[i] = randomNum(0, 999);
  }
  for (int i = 0; i < 1000000; i++) {
    arrayMillon[i] = randomNum(0, 999);
  }
  for (int i = 0; i < 10000000; i++) {
    arrayDmillon[i] = randomNum(0, 999);
    // cout<<arrayCien[i]<<endl;
  }
  //*******************************************
  //   ESCOGER UNO DE LOS SORTS Y CAMBIAR EL ARRAY QUE SE QUIERE PROBAR
  int n = sizeof(arrayDmil) / sizeof(arrayDmil[0]); //CAMBIO
  auto start = std::chrono::steady_clock::now();

  selectionSortAscendente(arrayDmil,n);  //CAMBIO 
  //selectionSortDescendente(arrayDmil, n); //CAMBIO
 
  //insertionSortAscendente(arrayDmil, n);  //CAMBIO
  //insertionSortDescendente(arrayCmil, n); //CAMBIO

  //countSortAscendente(arrayDmil , n); //CAMBIO
  //countSortDescendente(arrayDmil, n); //CAMBIO

  //bubbleSortAscendente(arrayCien, n); //CAMBIO
  //bubbleSortDescendente(arrayDmil, n); //CAMBIO

  //mergeSortAscendente(arrayDmil,0,n); //CAMBIO
  //mergeSortDescendente(arrayDmil,0,n); //CAMBIO

  
  auto finish = std::chrono::steady_clock::now();
  printArray(arrayDmil, n); // //CAMBIO

  double elapsed_seconds =
      std::chrono::duration_cast<std::chrono::duration<double>>(finish - start)
          .count();
  cout << elapsed_seconds << 's' << endl;
  return 0;
}
