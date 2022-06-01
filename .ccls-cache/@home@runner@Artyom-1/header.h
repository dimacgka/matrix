#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

class BaseArrayProcessor
{
protected:
double** array;
int n, jmax, imax;

public:
BaseArrayProcessor(int n)
{
this->n = n;
imax = 0;
jmax = 0;
array = new double*[this->n];
for(int i = 0; i < this->n; i++)
array[i] = new double[this->n];

cout << "Base processor class object created" << endl;
}

~BaseArrayProcessor()
{
for(int i =0; i < n; i++)
delete[] array[i];

delete[] array;
cout<<"Base processor class object destroyed"<<endl;
}
};


class DerivedArrayProcessor : public BaseArrayProcessor
{
    private:
    void GenerateMatrixElements()
    {
        for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
    {
        array[i][j] = rand() % 11 - 5;
        cout<<array[i][j]<<'\t';
    }

    cout<<endl;
    }

cout<<endl;
}

    void searchMaxElemnt()
    {
        cout << endl;
        int nmax = 1;
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if (nmax < array[i][j]){ 
                nmax = array[i][j];
                imax = i; 
                jmax = j;
                }
            }
        }
    }
  
  void cheking()
  {
    if (imax < jmax){
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            int t = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = t;
            }
        }
        for (int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j==0)
                    cout << endl;
                cout << array[i][j]<<"\t";
            }
        }
    }
    else {
      int sum=0;
        for(int i=imax; i<n; i++)
          sum += array[i][jmax];
        for (int j=jmax; jmax<n; j++)
          sum += array[imax][j];
    cout << endl;
    cout << sum;    
    }
  }

void ShowMatrix()
{
for(int i =0; i < n; i++)
{
for(int j =0; j < n; j++)
cout<<array[i][j]<<'\t';

cout<<endl;
}

  cout<<endl;
}
public:
  DerivedArrayProcessor(int n) : BaseArrayProcessor(n)
  {
    srand(time(0));
    GenerateMatrixElements();
    cout<<"Matrix processor class object created"<<endl;
  }

  void Run()
  {
    searchMaxElemnt();
    cheking();
    ShowMatrix();

  }

  ~DerivedArrayProcessor()
  {
    cout<<"Matrix processor class object destroyed"<<endl;
  }
};