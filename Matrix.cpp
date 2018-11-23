#include<iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int a,int b,int num[])
{
    row=a;
    col=b;
    data = new int [row * col];
    for (int i = 0; i < row * col; i++)
    data [i] = num [i];
 //   setdata(num);
}
Matrix::Matrix(){}
int Matrix::getcol(){
    return col;
}
int Matrix::getrow(){
    return row;
}
Matrix:: Matrix (const Matrix& mat){
    row=mat.row;
    col=mat.col;
    data=new int [row*col];
    for(int i=0;i<col*row;i++){

       data[i]=mat.data[i];

    }
//    return *this;


}
Matrix Matrix::operator=(const Matrix& mat){
    row=mat.row;
    col=mat.col;
    data=new int [row*col];
    for(int i=0;i<col*row;i++){

       data[i]=mat.data[i];

    }
    return *this;

}
Matrix:: ~Matrix(){
delete[]data;
}

/*int Matrix::setdata(int num[]){
    data=new int [row*col];
    for(int i=0;i<row*col;i++){
        data[i]=num[i];

    }
}
*/

int Matrix::getData(){return *data;}

Matrix Matrix::operator+ (const Matrix&  mat){

    int arr[row*col];

    if (row == mat.row && col == mat.col){
        for (int i = 0 ; i < row*col; i++){
            arr[i]=mat.data[i]+data[i];
        }

    }
    Matrix mat3(row,col,arr);
    return mat3;

}


Matrix Matrix::operator-(const Matrix&  mat){
    int arr[row*col];
    if (row == mat.row && col == mat.col){
        for (int i = 0 ; i < row*col ; i++){
            arr[i]=data[i]-mat.data[i];
        }

    }
    Matrix mat3(row,col,arr);
    return mat3;
}

Matrix Matrix::operator*(const Matrix&  mat){

  int arr[row*mat.col];

  if (col==mat.row){
    for (int i=0;i<row;i++){
        for (int j=0;j<mat.col;j++){
            float sum=0;
            for (int k=0;k<col;k++){

                sum+=data[i*col+k]*mat.data[k*mat.col+j];
                arr[i*mat.col+j]=sum;

            }
        }
    }


  }
        Matrix mat3(row,mat.col,arr);
        return mat3;
    }



Matrix Matrix::operator+(const int& scaler){
    int arr[row*col];
    for (int i = 0 ; i < row*col ; i++){
                arr[i]=data[i]+scaler;
            }
            Matrix mat3(row,col,arr);
            return mat3;

}

Matrix Matrix::operator-(const int& scaler){
    int arr[row*col];
    for (int i = 0 ; i < row*col ; i++){
                arr[i]=data[i]-scaler;
            }
            Matrix mat3(row,col,arr);
            return mat3;

}

Matrix Matrix::operator*(const int& scaler){
    int arr[row*col];
    for (int i = 0 ; i < row*col ; i++){
                arr[i]=data[i]*scaler;
            }
            Matrix mat3(row,col,arr);
            return mat3;

}
Matrix& Matrix::operator+=(const Matrix& mat){

     if(row==mat.row && col==mat.col){
        for(int i=0 ; i<row*col ; i++){
            data[i]+=mat.data[i];
        }
    }
    else{
        cout<<"they can not add "<<endl;
    }
    return *this ;
}
Matrix& Matrix::operator-=(const Matrix& mat){

     if(row==mat.row && col==mat.col){
        for(int i=0 ; i<row*col ; i++){
            data[i]-=mat.data[i];
        }
    }
    else{
        cout<<"they can not subtract "<<endl;
    }
    return *this ;
}
void Matrix:: operator++ (){

for(int i=0 ; i<row*col ; i++){
    data[i]=data[i]++;

}
}
void Matrix:: operator-- (){

for(int i=0 ; i<row*col ; i++){
    data[i]=data[i]--;
}


}
istream& operator>> (istream& in, Matrix& mat) {
           cout<<"enter the row and col :";
           in>>mat.row >> mat.col ;
           mat.data = new int[mat.row*mat.col];
           cout<<"enter the matrix data :";
           for(int i=0 ; i<mat.row*mat.col ; i++){
                in>>mat.data[i];

           }

           return in;
       }


ostream& operator<< (ostream& out, Matrix& mat)   {
	           int c=0;
	           for(int i=0 ; i<mat.row*mat.col ; i++){
                if(c==mat.col){
                    cout<<endl;
                    c=0;
                }
                    out<<mat.data[i]<<" ";
                    c++;
	           }
	           return out;
	       }



 bool Matrix ::  operator== (Matrix mat){
     for(int i=0;i<(row*col);i++){
        return(data[i]==mat.data[i]);

     }

 }
 bool Matrix ::  operator!= (Matrix mat ){

    for(int i=0;i<(row*col);i++){
        return(data[i]!=mat.data[i]);
}




 }
   bool Matrix :: isSquare   (){
   return(col==row);


   }
        bool Matrix  ::  isSymetric (){
              int sum1=0,sum2=0,x=0,y=0;
    int summ1[row],summ2[row];
    if(col==row){
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                sum1+=data[i*col+j];


                }
                summ1[x]=sum1;
                sum1=0;
                x++;

            }
              for(int i=0;i<col;i++){

                for(int j=0;j<row;j++){
                        sum2+=data[j*row+i];

                }
                 summ2[y]=sum2;
                sum2=0;
                y++;
              }
              for(int k=0;k<row;k++){
                return(summ1[k]==summ2[k]);
              }


    }

}

        bool Matrix ::  isIdentity (){

    bool check=true;
    if(col!=row){
            check=false;


    }
    else if(col==row){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==j&&data[i*col+j]!=1)
                    check=false;
                else if(i!=j&&data[i*col+j]!=0)
                    check=false;
            }
        }
    }
    return check;

        }
        Matrix Matrix:: transpose(){

        Matrix mat1;
     for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            mat1.data[i*row+j]=data[j*col+i];




        }
    }

    return mat1;

        }
