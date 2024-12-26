#include <iostream>

#pragma region House

class House
{
public:
    virtual void print_desc() = 0;
};

class WoodHouse : public House
{
public:
    virtual void print_desc()
    {
        std::cout << "Wooden house" << std::endl;
    }
};

class BrickHouse : public House
{
public:
    virtual void print_desc()
    {
        std::cout << "Brick house" << std::endl;
    }
};

class ConcreteHouse : public House
{
public:
    virtual void print_desc()
    {
        std::cout << "Concrete house" << std::endl;
    }
};

#pragma endregion

#pragma region Fence

class Fence
{
public:
    virtual void print_desc() = 0;
};

class WoodFence : public Fence
{
public:
    virtual void print_desc()
    {
        std::cout << "Wooden fence" << std::endl;
    }
};

class BrickFence : public Fence
{
public:
    virtual void print_desc()
    {
        std::cout << "Brick fence" << std::endl;
    }
};

class ConcreteFence : public Fence
{
public:
    virtual void print_desc()
    {
        std::cout << "Concrete fence" << std::endl;
    }
};

#pragma endregion

#pragma region Barn

class Barn
{
public:
    virtual void print_desc() = 0;
};

class WoodBarn : public Barn
{
public:
    virtual void print_desc()
    {
        std::cout << "Wooden barn" << std::endl;
    }
};

class BrickBarn : public Barn
{
public:
    virtual void print_desc()
    {
        std::cout << "Brick barn" << std::endl;
    }
};

class ConcreteBarn : public Barn
{
public:
    virtual void print_desc()
    {
        std::cout << "Concrete barn" << std::endl;
    }
};

#pragma endregion

typedef struct Area_s
{
    House* house;
    Fence* fence;
    Barn* barn;
} Area;

#pragma region Dev

class Developer
{
public:
    virtual House* buildHouse() = 0;
    virtual Fence* buildFence() = 0;
    virtual Barn* buildBarn() = 0;

    void BuildArea(Area* area)
    {
        area->house = buildHouse();
        area->fence = buildFence();
        area->barn = buildBarn();
    }

    void DestroyArea(Area* area)
    {
        delete area->house;
        delete area->fence;
        delete area->barn;
    }
};

class WoodDeveloper : public Developer
{
public:
    virtual House* buildHouse() { return new WoodHouse(); }
    virtual Fence* buildFence() { return new WoodFence(); }
    virtual Barn* buildBarn() { return new WoodBarn(); }
};

class BrickDeveloper : public Developer
{
public:
    virtual House* buildHouse() { return new BrickHouse(); }
    virtual Fence* buildFence() { return new BrickFence(); }
    virtual Barn* buildBarn() { return new BrickBarn(); }
};

class ConcreteDeveloper : public Developer
{
public:
    virtual House* buildHouse() { return new ConcreteHouse(); }
    virtual Fence* buildFence() { return new ConcreteFence(); }
    virtual Barn* buildBarn() { return new ConcreteBarn(); }
};

#pragma endregion

void printArea(Area* area)
{
    area->house->print_desc();
    area->fence->print_desc();
    area->barn->print_desc();
}

int main()
{
    Developer* wood_dev = new WoodDeveloper();
    Developer* brick_dev = new BrickDeveloper();
    Developer* concrete_dev = new ConcreteDeveloper();

    Area* a1 = new Area();
    Area* a2 = new Area();
    Area* a3 = new Area();

    wood_dev->BuildArea(a1);
    brick_dev->BuildArea(a2);
    concrete_dev->BuildArea(a3);

    std::cout << "Area 1:" << std::endl;
    printArea(a1);
    std::cout << std::endl;
    std::cout << "Area 2:" << std::endl;
    printArea(a2);
    std::cout << std::endl;
    std::cout << "Area 3:" << std::endl;
    printArea(a3);
    std::cout << std::endl;
}
