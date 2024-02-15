#include "Vector.h"
#include <iostream>
#include <initializer_list>
#include<utility>
using namespace std;
Vector::Vector(size_t rows, double initValue) {
    //FIXME
    rows_ = rows;
    data = new double[rows];
    for (size_t i = 0; i < rows_; i++)
    {
        data[i] = initValue;
    }
}

Vector::Vector(size_t rows) {
    //FIXME
    rows_ = rows;
    data = new double[rows];
}

Vector::Vector(std::initializer_list<double> l) {
    //FIXME
    rows_ = l.size();
    data = new double[rows_];
    size_t i=0;
    for (auto element : l)
    {
        this->data[i] = element;
        i++;
    }
}

// destructor
Vector::~Vector() {
    //FIXME

    if (data != nullptr)
    {
        delete[] this->data;
    }
}

// Copy constructor
Vector::Vector(const Vector& other) {
    //FIXME
    rows_ = other.rows_;
    data = new double[other.rows_];
    for (size_t i=0; i<rows_; i++)
    {
        data[i] = other.data[i];
    }
}

// Move constructor
Vector::Vector(Vector&& other) noexcept {
    //FIXME
    rows_ = other.rows_;
    data = other.data;
    *data = *other.data;
    other.data = nullptr;
}

// Copy assignment operator
Vector& Vector::operator=(const Vector& other) {
    //FIXME
    if (this == &other)
    {
        return *this;
    }
    delete[] data;
    rows_ = other.rows_;
    data = new double[other.rows_];
    for (size_t i=0; i<rows_; i++)
    {
        data[i] = other.data[i];
    }
    // std::cout << "*this" <<*this << std::endl;
    // std::cout << "this" << this << std::endl;
    return *this;
}

// Move assignment operator
Vector& Vector::operator=(Vector&& other) noexcept {
    //FIXME
    // a = b
    rows_ = other.rows_;
    delete[] data;
    data = other.data;
    *data = *other.data;
    other.data = nullptr;
    return *this;
}

void swap(Vector& a, Vector& b) {
    //FIXME
    size_t temp_rows;
    double *temp_data = new double[temp_rows];
    temp_rows = a.rows_;
    temp_data = a.data;
    a.rows_ =  b.rows_;
    a.data = b.data;
    b.rows_ = temp_rows;
    b.data = temp_data;
    delete[] temp_data;
}

bool Vector::operator ==(const Vector& b) const {
    //FIXME
    bool t;
    int loop = 0;
    if (this->rows_ == b.rows_)
    {
        for (size_t i=0; i<rows_; i++)
        {
            if (this->data[i] == b.data[i])
            {
                t = true;
                loop++;
                continue;
            }
            else
            {
                t = false;
                loop++;
                break;
            }
        }
        if (!loop)
        {
            t = true;
        }
    }
    else
    {
        t = false;
    }
    return t;
}

bool Vector::operator !=(const Vector& b) const {
    //FIXME
    bool t;
    int loop = 0;
    if (this->rows_ == b.rows_)
    {
        for (size_t i=0; i<rows_; i++)
        {
            if (this->data[i] != b.data[i])
            {
                t = true;
                loop++;
                break;
            }
            else
            {
                t = false;
                loop++;
                continue;
            }
        }
        if (!loop)
        {
            t = false;
        }
    }
    else
    {
        t = true;
    }
    return t;
}

Vector& Vector::operator +=(const Vector& b) {
    //FIXME
    // a += b
    if (this->rows_ == b.rows_)
    {
        for (size_t i=0; i<rows_; i++)
        {
            this->data[i] = this->data[i]+ b.data[i];
        }
    }
    return *this;
}

Vector Vector::operator +(const Vector& b) const {
    //FIXME
    Vector temp(b.rows_);
    if (this->rows_ == b.rows_)
    {
        for (size_t i=0; i<rows_; i++)
        {
            temp.data[i] = this->data[i]+ b.data[i];
        }
    }
    return temp;
}

Vector& Vector::operator -=(const Vector& b) {
    //FIXME
    if (this->rows_ == b.rows_)
    {
        for (size_t i=0; i<rows_; i++)
        {
            this->data[i] = this->data[i]- b.data[i];
        }
    }
    return *this;
}

Vector Vector::operator -(const Vector& b) const {
    //FIXME
    Vector temp(b.rows_);
    if (this->rows_ == b.rows_)
    {
        for (size_t i=0; i<rows_; i++)
        {
            temp.data[i] = this->data[i]- b.data[i];
        }
    }
    return temp;
}

Vector Vector::operator*(const Vector& b) const {
    //FIXME
    Vector temp(b.rows_);
    if (this->rows_ == b.rows_)
    {
        for (size_t i=0; i<rows_; i++)
        {
            temp.data[i] = this->data[i]*b.data[i];
        }
    }
    return temp;
}

Vector& Vector::operator *=(const Vector& b) {
    //FIXME
    if (this->rows_ == b.rows_)
    {
        for (size_t i=0; i<rows_; i++)
        {
            this->data[i] = this->data[i]*b.data[i];
        }
    }
    return *this;
}

// print matrixelements to stream
std::ostream& operator <<(std::ostream &outputStream, const Vector& m) {
    //FIXME
    for (size_t i=0; i<m.rows_; i++)
    {
        outputStream << m.data[i] <<endl;
    }
    return outputStream;
}

// read matrixelements from stream
std::istream& operator >>(std::istream &inputStream, Vector& m) {
    //FIXME
    for (size_t i=0; i<m.rows_; i++)
    {
        inputStream >> m.data[i];
    }
    return inputStream;
}

double* Vector::begin() {
    //FIXME
    return this->data;
}
double* Vector::end() {
    //FIXME
    double *p;
    p = this->data + this->rows_;
    return p;
}
const double* Vector::begin() const {
    //FIXME
    return this->data;
}
const double* Vector::end() const {
    //FIXME
    const double *p;
    p = this->data + this->rows_;
    return p;
}

size_t Vector::size() const {
    //FIXME
    size_t rows;
    rows = this->rows_;
    return rows;
}

double Vector::dot(const Vector& b) const {
    // FIXME
    // a.b
    // a = [1,2,3]
    // b = [1,1,1]
    // a.b = 1*1 + 2*1 + 3*1
    double sum = 0;
    if (this->rows_ == b.rows_)
    {
        for (size_t i=0; i<rows_; i++)
        {
            sum = sum + this->data[i]*b.data[i];
        }
    }
    return sum;
}
