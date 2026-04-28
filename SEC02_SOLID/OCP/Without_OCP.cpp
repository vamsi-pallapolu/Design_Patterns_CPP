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

int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    std::vector<Product *> items{&apple, &tree, &house};

    ProductFilter pf;
    auto green_things = pf.by_color(items, Color::green);

    for (const auto &green : green_things)
    {
        std::cout << green->name << std::endl;
    }

    auto large_sizes = pf.by_size(items, Size::large);

    for (const auto &large_size : large_sizes)
    {
        std::cout << large_size->name << std::endl;
    }

    std::cout << "By Color and Size" << std::endl;
    std::vector<Product *> sizeAndColors = pf.by_size_and_color(items, Size::large, Color::green);
    for (const auto &sizeAndColor : sizeAndColors)
    {
        std::cout << sizeAndColor->name << std::endl;
    }

    return 0;
}