#ifndef POLY
#define POLY
#include <iostream>
#include <assert.h>

using namespace std;

template <typename T>
class Polynomial {
private: 
    T* coefs; 
    int num_of_coefs;
    
public:
    //Constructor
    Polynomial<T>(){
        coefs = (T*)malloc(sizeof(T)*1); 
        assert(coefs);
        coefs[0] = 0;
        num_of_coefs = 0;
    }
    //Copy constructor
    Polynomial(const Polynomial<T> &p){
        this->coefs = (T*)malloc(sizeof(T)*(p.num_of_coefs+1));
        assert(this->coefs);
        this->num_of_coefs = p.num_of_coefs;

        for (int i = 0; i <= this->num_of_coefs; i++)
            this->coefs[i] = p.coefs[i];
        

    } 

    // Operator []
    T& operator [](int ind){
        if (this->num_of_coefs <= ind){ // If coef too small resize it.
            this->coefs = (T*)realloc(this->coefs ,sizeof(T)*(ind+1));
            for (int i = this->num_of_coefs; i <= ind; i++)
                this->coefs[i] = 0;
            this->num_of_coefs = ind+1;
        }
        return this->coefs[ind];
    }

    // Operator <<
    friend ostream& operator <<(ostream & os, const Polynomial<T> &p){
       int count = 0;
       int i;
       // This loop find the first obj.
        for (i = p.num_of_coefs; i>1; i--){
                count++;
                if (p.coefs[i] != 0){
                    os << p.coefs[i] << "*x^" << i;
                    break;
                }
        }// Find the Other obj.
        for (i = p.num_of_coefs-count; i>1; i--)
            if (p.coefs[i] != 0){
                if (p.coefs[i] < 0)
                    os<<p.coefs[i] << "*x^"<<i;
                else{ os <<"+"<< p.coefs[i] << "*x^"<<i;}    
            }
        // Find the last 2 obj (if exist). 
        if (p.coefs[1] != 0)
            if (p.coefs[1] > 0 && p.num_of_coefs == 2)
                    os << p.coefs[1] <<"*x";
            else os << "+" << p.coefs[1] <<"*x";

        if (p.coefs[0] != 0 )
            if (p.coefs[0] > 0 && p.num_of_coefs != 1)
                os << "+" << p.coefs[0]; 
            else os << p.coefs[0];
        

        return os;        
        
    } 
// Operator =
   Polynomial<T> & operator =(const Polynomial<T> &p){
// if other is empty (= 0), then delete this and return 0;
   if (p.num_of_coefs == 0){
        this->num_of_coefs = 0;
        free(this->coefs);
        this->coefs = (T*)malloc(sizeof(T)*1);
        this->coefs[0] = 0;
        this->num_of_coefs = 0;
        assert(this->coefs);
        return *this;
   }// if other != 0, copy it.
        free(this->coefs);
        this->coefs = (T*)malloc(sizeof(T)*(p.num_of_coefs+1));
        assert(this->coefs);
        this->num_of_coefs = p.num_of_coefs;
        for (int i = 0; i <= p.num_of_coefs; i++)
        this->coefs[i] = p.coefs[i];
    

    return *this;
    }


//  Operator +=
    Polynomial<T>& operator += (Polynomial<T> &p)
    {// If  p bigger then this. 
        if (p.num_of_coefs > this->num_of_coefs)
        {
            this->coefs = (T*)realloc(this->coefs, sizeof(Polynomial<T>)*(p.num_of_coefs+1));
            assert(this->coefs);
            for (int i = this->num_of_coefs; i <=p.num_of_coefs; i++)
                this->coefs[i] = 0;
        this->num_of_coefs = p.num_of_coefs;
        for (int i = 0; i < this->num_of_coefs; i++)
                this->coefs[i] += p.coefs[i];
        }// If p smaller then this. 
       else for (int i = 0; i < p.num_of_coefs; i++)
                this->coefs[i] += p.coefs[i];
        

        return *this;
    } 

 // Operator + 
   Polynomial<T> operator + (const Polynomial<T> &p)
   {
        Polynomial<T> temp;
        int size;
        // Find the bigger between this and p; 
        if (p.num_of_coefs>=this->num_of_coefs)
            size = p.num_of_coefs;
        else size = this->num_of_coefs; 


        temp.coefs = (T*)realloc(temp.coefs , sizeof(T)*(size+1));
        assert(temp.coefs);
        temp.num_of_coefs = size;
    // Those loops reset array[i] to zero, and copy the parameters inside. 
        for (int i = 0; i<size+1; i++)
            temp.coefs[i] = 0;

        for(int i = 0; i<=p.num_of_coefs; i++)
            temp.coefs[i] += p.coefs[i];

        for(int i = 0; i<=this->num_of_coefs; i++)
            temp.coefs[i] += this->coefs[i];
        
        return temp;
    }


    // Operator -=
Polynomial<T>& operator -= (Polynomial<T> &p){
        if (p.num_of_coefs > this->num_of_coefs)
        {// if p bigger then this, resize it and copy the parameters.
            this->coefs = (T*)realloc(this->coefs, sizeof(Polynomial<T>)*(p.num_of_coefs+1));
            assert(this->coefs);
            for (int i = this->num_of_coefs; i <=p.num_of_coefs; i++)
                this->coefs[i] = 0;
            this->num_of_coefs = p.num_of_coefs; 
            for (int i = 0; i <= this->num_of_coefs; i++)
                this->coefs[i] -= p.coefs[i];
        }
       else for (int i = 0; i <= p.num_of_coefs; i++)
                this->coefs[i] -= p.coefs[i];
        
        return *this;
    } 
// Operator - . same pattern as +
Polynomial<T> operator - (const Polynomial<T> &p)
   {
        Polynomial<T> temp;
        int size;
        if (p.num_of_coefs>=this->num_of_coefs)
            size = p.num_of_coefs;
        else size = this->num_of_coefs; 

        temp.coefs = (T*)realloc(temp.coefs, sizeof(T)*(size+1));
        assert(temp.coefs);
        temp.num_of_coefs = size;
        
        for (int i = 0; i<size+1; i++)
            temp.coefs[i] = 0;

        for(int i = 0; i<=p.num_of_coefs; i++)
            temp.coefs[i] -= p.coefs[i];

        for(int i = 0; i<=this->num_of_coefs; i++)
            temp.coefs[i] += this->coefs[i];
        
        return temp;
    }

Polynomial<T>& operator *=(const Polynomial<T> &p){
   // If this is zero, return this. 
    if (this->num_of_coefs == 0)
        return *this;
    // If p is zero, reset this to zero.
    else if(p.num_of_coefs == 0){
        free(this->coefs);
        this->coefs = (T*)malloc(sizeof(T)*(1));
        assert(this->coefs);
        this->coefs[0] = 0;
        this->num_of_coefs = 0;
        return *this;
    }
else{ // if p and this not zero, then multiply them 
      // and return the result.
    int size = (p.num_of_coefs+this->num_of_coefs+1);


    Polynomial<T> temp;
    // Copy this to temp. resize this to the rigth size+ int. all cells to 0. 
    temp.coefs = (T*)realloc(temp.coefs , sizeof(T)*(this->num_of_coefs));
    assert(temp.coefs);
    temp.num_of_coefs = this->num_of_coefs;
    for (int k = 0; k<=this->num_of_coefs; k++)
        temp.coefs[k] = this->coefs[k];

    this->coefs = (T*)realloc(this->coefs, sizeof(T)*(size));
    assert(this->coefs);
    this->num_of_coefs = size;
    for (int k = 0; k<=this->num_of_coefs; k++)
        this->coefs[k] = 0;

int i, j;
// Multiply temp*p and put the result on this.
    for(i = 0; i <= temp.num_of_coefs; i++)// =
        for (j = 0; j <= p.num_of_coefs; j++)// =
            this->coefs[i+j] += (temp.coefs[i]*p.coefs[j]);

    free(temp.coefs);

    return *this;
    }
} // Operator *
Polynomial<T> operator * (const Polynomial<T> &p){
  
    Polynomial<T> temp;
// if this or P are 0 = return temp (initialize to 0);
    if (this->num_of_coefs == 0 || p.num_of_coefs == 0)
        return temp;
// Resize temp and reset to 0;
    int size = (p.num_of_coefs+this->num_of_coefs+1);
    temp.coefs = (T*)realloc(temp.coefs, sizeof(T)*(size));
    assert(temp.coefs);
    temp.num_of_coefs = size;

    for (int k = 0; k<=temp.num_of_coefs; k++)
        temp.coefs[k] = 0; 

int i, j;
// Multiply this and p and put the result on temp.
    for(i = 0; i < this->num_of_coefs; i++)
        for (j = 0; j < p.num_of_coefs; j++)
            temp.coefs[i+j] += (this->coefs[i]*p.coefs[j]);

    return temp;

}
//Destructor.
~Polynomial() {free(this->coefs);}

};


#endif 