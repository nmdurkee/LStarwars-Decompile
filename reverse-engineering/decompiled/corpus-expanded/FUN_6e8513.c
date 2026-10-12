/* Ghidra pseudocode, not original source.
 * ev_0b5d44e813c4aa355d260cb866ec5aec765804eee128937753d2ed60240642a2
 * Entry: 0x6e8513; label: type_info::`scalar_deleting_destructor'
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    public: virtual void * __thiscall type_info::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2005 Release */

void * __thiscall type_info::_scalar_deleting_destructor_(type_info *this,uint param_1)

{
  ~type_info(this);
  if ((param_1 & 1) != 0) {
    FUN_006e85b0(this);
  }
  return this;
}

