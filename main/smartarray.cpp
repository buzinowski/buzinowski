#include "smartarray.h"
#include "iostream"
#include "assert.h"


        void SmartArray::info()
        {
            std::cout<<"Класс Динамический массив"<<std::endl;
        }

        SmartArray::SmartArray(int _nSize)
        {
            nSize = _nSize;
            pData = new int[_nSize];
        }
        int& SmartArray::operator[](int _index)
        {
            if(_index<nSize) return pData[_index];
            else
            {
                assert(0);return pData[0];
            }
        }
        int SmartArray::getSize()
        {
            std::cout<<"Size is : ";
            return nSize;
        }
        SmartArray::~SmartArray()
        {
            std::cout<<"Destruction"<<std::endl<<std::endl;
            delete [] pData;
        }

        void SmartArray::swap(int& a, int& b,int& c, int& d)
        {
            int e = a;
            a = c;
            c = e;
            int f = b;
            b = d;
            d = f;
        }

