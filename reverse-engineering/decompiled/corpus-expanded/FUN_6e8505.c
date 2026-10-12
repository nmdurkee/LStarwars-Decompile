/* Ghidra pseudocode, not original source.
 * ev_0b5d44e813c4aa355d260cb866ec5aec765804eee128937753d2ed60240642a2
 * Entry: 0x6e8505; label: type_info::~type_info
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

