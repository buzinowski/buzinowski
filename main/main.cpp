#include <QCoreApplication>
#include "smartarray.h"
#include "smartarray.cpp"

int main()
{
     int a,b,c,d;
     SmartArray  *pArray = new SmartArray(10);

     (*pArray).info();

     std::cout<<pArray->getSize()<<std::endl<<std::endl;

     for(int i = 0;i<10;i++)
     std::cout<<(pArray->operator [](i) =  i)<<std::endl;
     std::cout<<std::endl;

     SmartArray *pNewArray = new SmartArray(30);
      std::cout<<pNewArray->getSize()<<std::endl<<std::endl;

     for(int i = 0;i < 10;i++)
     {
        (*pNewArray)[i] = (*pArray)[i];

      };

     for(int i = 10; i < 30; i++)
         (pNewArray->operator [](i) = i*i);

     for (int i = 0; i < 30; i++)
         std::cout<<i<<" : "<<((*pNewArray)[i])<<std::endl;

    std::cout<<"Enter elements of the first array a,b"<<std::endl;
    std::cin>>a>>b;
    std::cout<<"Enter elements of the second array c,d"<<std::endl;
    std::cin>>c>>d;
    std::cout<<"Current value is : "<<(*pArray)[a]<<"\t"<<(*pArray)[b]<<"\t"<<(*pNewArray)[c]<<"\t"<<(*pNewArray)[d]<<std::endl;

    (*pArray).swap((*pArray)[a],(*pArray)[b],(*pNewArray)[c],(*pNewArray)[d]);
    std::cout<<"New value is : "<<(*pArray)[a]<<"\t"<<(*pArray)[b]<<"\t"<<(*pNewArray)[c]<<"\t"<<(*pNewArray)[d];


     delete pArray;
     delete pNewArray;


}
