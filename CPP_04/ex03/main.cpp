#include <iostream>

// adjust include paths to match your project
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

static void rule(const std::string& s) {
    std::cout << "\n---- " << s << " ----\n";
}

int main() {
    rule("1) Build MateriaSource and learn basic materias");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    rule("2) Create characters");
    ICharacter* vivi = new Character("Vivi");
    ICharacter* seph = new Character("Seph");

    rule("3) Create materias from source (and try an unknown type)");
    AMateria* mIce1 = src->createMateria("ice");
    AMateria* mCure1 = src->createMateria("cure");
    AMateria* mUnknown = src->createMateria("fire"); // should be NULL

    std::cout << "createMateria(\"fire\") => "
              << (mUnknown ? "NOT NULL (ERROR)" : "NULL (OK)") << "\n";

    rule("4) Equip Vivi with ice + cure, then use them on Seph");
    vivi->equip(mIce1);   // slot 0
    vivi->equip(mCure1);  // slot 1
    vivi->use(0, *seph);  // expect ice line
    vivi->use(1, *seph);  // expect cure line

    rule("5) Use an empty slot (should do nothing, no crash)");
    vivi->use(3, *seph);  // empty — no output expected

    rule("6) Unequip slot 0 (must NOT delete)");
    // We still own mIce1 pointer because Character::unequip must not delete it.
    // We'll delete it ourselves at the end.
    vivi->unequip(0);
    vivi->use(0, *seph); // should now do nothing

    rule("7) Refill slot 0 and 2 to have more than one item again");
    AMateria* mIce2 = src->createMateria("ice");
    AMateria* mCure2 = src->createMateria("cure");
    vivi->equip(mIce2); // goes into slot 0 (freed by unequip)
    vivi->equip(mCure2); // goes into slot 2
    vivi->use(0, *seph); // expect ice line
    vivi->use(2, *seph); // expect cure line

    rule("8) Deep copy Character (copy should own clones, not same pointers)");
    Character viviCopy(*(static_cast<Character*>(vivi)));
    // Both should be able to use their stuff independently
    vivi->use(1, *seph);      // cure from original
    viviCopy.use(1, *seph);   // cure from copy (should print too)

    rule("9) Destroy original Vivi, copy must still work");
    delete vivi; vivi = 0;
    viviCopy.use(0, *seph);   // expect ice line from the copy
    viviCopy.use(2, *seph);   // expect cure line from the copy

    rule("10) Cleanup");
    delete seph;  seph  = 0;
    delete src;   src   = 0;
    // We manually delete the unequipped pointer mIce1 dropped on the "floor".
    delete mIce1; mIce1 = 0;
    // mUnknown is NULL (no delete). mIce2/mCure2 are owned by vivi (deleted already),
    // and viviCopy owns its own internal clones (deleted with viviCopy below).

    rule("11) Destroy the copy (should free its own cloned materias)");
    // NOTE: viviCopy is a stack object; it will be destroyed at end of scope.
    std::cout << "\n(end of main)\n";
    return 0;
}
