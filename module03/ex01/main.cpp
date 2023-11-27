#include "Command.hpp"
#include "ThuesdayDiscountCommand.hpp"
#include "PackageReductionDiscountCommand.hpp"

int main()
{
    Command command(1, "Monday", "John", std::move(Article{"Banana", 10}), 2);

    std::cout << "Total price: " << command.get_total_price() << std::endl;

    ThuesdayDiscountCommand thuesday_discount_command(command);
    std::cout << "Total price: " << thuesday_discount_command.get_total_price() << std::endl;

    PackageReductionDiscountCommand package_reduction_discount_command(command);

    std::cout << "Total price: " << package_reduction_discount_command.get_total_price() << std::endl;

    PackageReductionDiscountCommand package_reduction_discount_command2(2, "Monday", "John", Article("Banana", 10), 20);

    std::cout << "Total price: " << package_reduction_discount_command2.get_total_price() << std::endl;
}