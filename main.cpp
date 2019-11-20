#include <iostream>
#include "TypeList.h"
#include "AbstractFactoryGenerator.h"
#include "Product.h"

using MyFactoryHierarchy = GetAbstractFactory<
        3,
        5,
        Typelist<Chair, Table, Sofa>,
        Typelist<WoodenChair, WoodenTable, WoodenSofa>,
        Typelist<MetalChair, MetalTable, MetalSofa>,
        Typelist<MetalRichChair, MetalRichTable, MetalRichSofa>,
        Typelist<MetalPoorChair, MetalPoorTable, MetalPoorSofa>
>;


void test1() {
    MyFactoryHierarchy::Factory* MyFactory = new MyFactoryHierarchy::GetConcreteFactory<Table>::result;
    auto* sofa = MyFactory->Get<Sofa>();
    auto* table = MyFactory->Get<Table>();
    auto* chair = MyFactory->Get<Chair>();

    chair->execute();
    table->execute();
    sofa->execute();

    delete sofa, table, chair, MyFactory;
}

void test2() {
    MyFactoryHierarchy::Factory* MyFactory = new MyFactoryHierarchy::GetConcreteFactory<WoodenSofa>::result;
    auto* sofa = MyFactory->Get<Sofa>();
    auto* table = MyFactory->Get<Table>();
    auto* chair = MyFactory->Get<Chair>();

    chair->execute();
    table->execute();
    sofa->execute();

    delete sofa, table, chair, MyFactory;
}

void test3() {
    MyFactoryHierarchy::Factory* MyFactory = new MyFactoryHierarchy::GetConcreteFactory<MetalPoorSofa>::result;
    auto* sofa = MyFactory->Get<Sofa>();
    auto* table = MyFactory->Get<Table>();
    auto* chair = MyFactory->Get<Chair>();

    chair->execute();
    table->execute();
    sofa->execute();

    delete sofa, table, chair, MyFactory;
}

int main() {

   test1();
   test2();
   test3();

   return 0;
}
