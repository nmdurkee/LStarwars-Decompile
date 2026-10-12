/* Ghidra analysis pseudocode, not original source.
 * ev_eecf13eba2be62f78d2c2fac028dc2e8e01e29bc459957490b66b8c35bfd6df7
 * Entry: 0x6e8505; label: type_info::~type_info
 */

/* Library Function - Single Match
    public: virtual __thiscall type_info::~type_info(void)
   
   Library: Visual Studio 2005 Release */

void __thiscall type_info::~type_info(type_info *this)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__00777d4c;
  _Type_info_dtor(this);
  return;
}

