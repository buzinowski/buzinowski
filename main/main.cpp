#include <QCoreApplication>
#include "smartarray.h"
#include "smartarray.cpp"

int main()
{

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

     std::cout<<"Current value : "<<"pArray[2] is "<<((*pArray)[2])<<", "<<"pArray[4] is "<<((*pArray)[4])<<" \t"<<"pNewArray[16] is "<<((*pNewArray)[16])<<", "<<"pNewArray[12] is "<<((*pNewArray)[12])<<std::endl;
     std::cout<<std::endl;

    ( *pArray).swap((*pArray)[2],(*pArray)[4],(*pNewArray)[16],(*pNewArray)[12]);


     std::cout<<"New Value : "<<"pArray[2] is "<<((*pArray)[2])<<", "<<"pArray[4] is "<<((*pArray)[4])<<" \t"<<"pNewArray[16] is "<<((*pNewArray)[16])<<", "<<"pNewArray[12] is "<<((*pNewArray)[12])<<std::endl;
     std::cout<<std::endl;



     delete pArray;
     delete pNewArray;


}
