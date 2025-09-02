#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main()
{
    std::cout << RED << "------ GIVEN MAIN : ------" << RESET << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    std::cout << RED << "------ OTHER TESTS : ------" << RESET << std::endl;
    IMateriaSource* source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    ICharacter* vic = new Character("Vic");
    AMateria* temp;

    temp = source->createMateria("ice");
    vic->equip(temp);
    temp = source->createMateria("cure");
    vic->equip(temp);
    temp = source->createMateria("unknown");
    if (!temp)
        std::cout << "Unknown materia can't be created!" << std::endl;

    ICharacter* iris = new Character("Iris");
    vic->use(0, *iris);
    vic->use(1, *iris);

    vic->unequip(0);
    vic->use(0, *iris); // Should have no effect

    temp = source->createMateria("cure");
    vic->equip(temp);

    vic->use(0, *iris);

    delete source;
    delete vic;
    delete iris;
    return 0;
}


