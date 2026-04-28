#include <iostream>
#include < vector>

enum class Color
{
    red,
    green,
    blue
};
enum class Size
{
    small,
    medium,
    large
};

struct Product
{

    std::string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    // Filter the products by color
    std::vector<Product *> by_color(const std::vector<Product *> &items, Color color)
    {
        std::vector<Product *> result;
        for (const auto &item : items)
        {
            if (item->color == color)
            {
                result.push_back(item);
            }
        }
        return result;
    }

    // Filter the products by size
    std::vector<Product *> by_size(const std::vector<Product *> &products, Size size)
    {
        std::vector<Product *> result;
        for (Product *const &product : products)
        {
            if (product->size == size)
            {
                result.push_back(product);
            }
        }
        return result;
    }

    // Filter products by size and color
    std::vector<Product *> by_size_and_color(const std::vector<Product *> &products, Size size, Color color)
    {
        std::vector<Product *> result;
        for (const auto &product : products)
        {
            if (product->size == size && product->color == color)
            {
                result.push_back(product);
            }
        }
        return result;
    }
};

template <typename T>
struct Specification
{
    virtual bool is_satisfied(T *item) = 0;
};

template <typename T>
struct Filter
{
    virtual std::vector<T *> filter(std::vector<T *> &items, Specification<T> &spec) = 0;
};

struct BetterFilter : public Filter<Product>
{
    std::vector<Product *> filter(std::vector<Product *> &items, Specification<Product> &spec) override
    {
        std::vector<Product *> result;
        for (const auto &item : items)
        {
            if (spec.is_satisfied(item))
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

struct ColorSpecification : public Specification<Product>
{
    Color _color;

    ColorSpecification(const Color color) : _color{color} {};

    bool is_satisfied(Product *item)
    {
        return item->color == _color;
    }
};

struct SizeSpecification : public Specification<Product>
{
    Size _size;
    SizeSpecification(const Size size) : _size{size} {}

    bool is_satisfied(Product *item) override
    {
        return item->size == _size;
    }
};

int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    std::vector<Product *> items{&apple, &tree, &house};

    BetterFilter bf;
    ColorSpecification green(Color::green);
    for (const auto &item : bf.filter(items, green))
    {
        std::cout << item->name << " is " << "green" << std::endl;
    }

    SizeSpecification large(Size::large);
    for (const Product *const &item : bf.filter(items, large))
    {
        std::cout << item->name << " is " << "large" << std::endl;
    }

    return 0;
}