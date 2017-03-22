#ifndef SMARTARRAY_H
#define SMARTARRAY_H

class SmartArray
{

private:
    int *pData;
    int nSize;
public:

    void info();
    void swap(int& a, int& b,int& c, int& d);
    SmartArray(int _nSize);
    int& operator[](int _index);
    int getSize();
    ~SmartArray();
};

#endif // SMARTARRAY_H
