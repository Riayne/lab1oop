#include <iostream>
#include<vector>
using namespace std;

class Matrix{

    
    int row;
    int col;
    double* value;
    public:

    //default
    Matrix(){
        row = 0;
        col = 0;
        value = nullptr;
    }

    //parameterized
    Matrix(int r,int c){
        row = r;
        col = c;
        value = new double[row *col]();
    }

    //copy
    Matrix(const Matrix& other): row(other.row) , col(other.col){
        value = new double[row*col];
        for(int i=0;i<row*col;i++){
            value[i] = other.value[i];
        }

    } 

    Matrix(Matrix&& other) noexcept : row(other.row), col(other.col) , value(other.value){
        other.value = nullptr;
        other.row = other.col = 0;
    }

    // destructor
    ~Matrix(){
        delete[] value;
    }
    
    //getters
    int getRows(){
        return row;
    }
    int getCols(){
        return col;
    }

    //other members
    double& at(int r,int c) const{
        if(r<0 || r>=row ||c<0||c>=col){
            cout<<"out of range"<<endl;
        }
        return value[r*col+c];
    }

    void fill(double fillValue){

        for (int i = 0; i < row * col; i++) {
            value[i] = fillValue;
        }
    }

     Matrix transpose() const {
        Matrix transposed(col, row);  
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; c++) {
                transposed.at(c,r) = at(r,c);
            }
        }
        return transposed;
    }


    void print() const {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << " "<<at(i,j)<<endl;
            }
            cout << "\n";
        }
    }

};

int main(){
   Matrix A;
   cout<<"default"<<endl;
   cout<<"Rows: "<<A.getRows()<<"Col: "<<A.getCols()<<endl;

   Matrix B(3,3);

   cout<<"Parameterized Constructor\n";
   B.fill(4.0);
   B.print();
   cout<<endl;

   Matrix C=B;
   cout<<"copy"<<endl;
   C.print();
   cout<<endl;

   Matrix D = move(B);
   cout<<"move"<<endl;
   D.print();
   cout<<endl;

   Matrix E = D.transpose();
   cout<<"transpose"<<endl;
   E.print();

   return 0;
}
