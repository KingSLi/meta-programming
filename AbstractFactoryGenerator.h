#ifndef META_PROGRAMMING_ABSTRACTFACTORYGENERATOR_H
#define META_PROGRAMMING_ABSTRACTFACTORYGENERATOR_H

#include "HierarchyGenerators.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class AbstractFactoryUnit {
public:
    virtual T* DoCreate(Type2Type<T>) = 0;
    virtual ~AbstractFactoryUnit() = default;
};

template <typename TypedList, template <class> class Unit = AbstractFactoryUnit>
class AbstractFactory : public GenScatterHierarchy<TypedList, Unit> {
public:
    using ProductList = TypedList;
    template <typename T>
    T* Get() {
        Unit<T>& unit = *this;
        return unit.DoCreate(Type2Type<T>());
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class ConcreteProduct, class Base>
class ConcreteFactoryUnit : public Base {
    using BaseProductList = typename Base::ProductList;
protected:
    using ProductList = typename NTypeList::GetTail<BaseProductList>::result;
public:
    using AbstractProduct = typename NTypeList::TypeAt<BaseProductList, 0>::result;
    ConcreteProduct* DoCreate(Type2Type<AbstractProduct>) {
        return new ConcreteProduct;
    }
};

template <typename AbstractFact, template <class, class> class Creator = ConcreteFactoryUnit, typename TypedList = typename AbstractFact::ProductList> 
class ConcreteFactory : public GenLinearHierarchy<typename NTypeList::Reverse<TypedList>::result, Creator, AbstractFact> {
public:
    using ProductList = typename AbstractFact::ProductList;
    using ConcreteProductList = TypedList;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, size_t M, typename... TypedLists>
class GetAbstractFactory {
    using BaseTypes = typename NTypeList::GetSupers<TypedLists...>::result;
public:
    using Factory = AbstractFactory<BaseTypes>;

    template <typename T>
    class GetConcreteFactory {
        using CorrespondingList = typename NTypeList::ListWithType<Typelist<TypedLists...>, T>::result;
    public:
        using result = ConcreteFactory<Factory, ConcreteFactoryUnit, CorrespondingList>;
    };
};

#endif //META_PROGRAMMING_ABSTRACTFACTORYGENERATOR_H
