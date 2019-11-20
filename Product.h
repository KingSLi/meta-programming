//
// Created by Maksim Polyanskiy on 2019-11-20.
//

#ifndef META_PROGRAMMING_PRODUCT_H
#define META_PROGRAMMING_PRODUCT_H

class Product {
public:
    virtual void execute() {
        std::cout << "This is Product" << std::endl;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Chairs

class Chair : public Product {
public:
    void execute() override {
        std::cout << "This is Chair" << std::endl;
    }
};

class WoodenChair : public Chair {
public:
    void execute() override {
        std::cout << "This is WoodenChair" << std::endl;
    }
};

class MetalChair : public Chair {
public:
    void execute() override {
        std::cout << "This is MetalChair" << std::endl;
    }
};

class MetalRichChair : public MetalChair {
public:
    void execute() override {
        std::cout << "This is MetalRichChair" << std::endl;
    }
};

class MetalPoorChair : public MetalChair {
public:
    void execute() override {
        std::cout << "This is MetalPoorChair" << std::endl;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Table

class Table : public Product {
public:
    void execute() override {
        std::cout << "This is Table" << std::endl;
    }
};

class WoodenTable : public Table {
public:
    void execute() override {
        std::cout << "This is WoodenTable" << std::endl;
    }
};

class MetalTable : public Table {
public:
    void execute() override {
        std::cout << "This is MetalTable" << std::endl;
    }
};

class MetalRichTable : public MetalTable {
public:
    void execute() override {
        std::cout << "This is MetalRichTable" << std::endl;
    }
};

class MetalPoorTable : public MetalTable {
public:
    void execute() override {
        std::cout << "This is MetalPoorTable" << std::endl;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Sofa

class Sofa : public Product {
public:
    void execute() override {
        std::cout << "This is Sofa" << std::endl;
    }
};


class WoodenSofa : public Sofa {
public:
    void execute() override {
        std::cout << "This is WoodenSofa" << std::endl;
    }
};



class MetalSofa : public Sofa {
public:
    void execute() override {
        std::cout << "This is MetalSofa" << std::endl;
    }
};


class MetalRichSofa : public MetalSofa {
public:
    void execute() override {
        std::cout << "This is MetalRichSofa" << std::endl;
    }
};



class MetalPoorSofa : public MetalSofa {
public:
    void execute() override {
        std::cout << "This is MetalPoorSofa" << std::endl;
    }
};
#endif //META_PROGRAMMING_PRODUCT_H
