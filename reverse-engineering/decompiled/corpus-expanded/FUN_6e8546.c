/* Ghidra pseudocode, not original source.
 * ev_0b5d44e813c4aa355d260cb866ec5aec765804eee128937753d2ed60240642a2
 * Entry: 0x6e8546; label: type_info::operator==
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    public: bool __thiscall type_info::operator==(class type_info const &)const 
   
   Library: Visual Studio 2005 Release */

bool __thiscall type_info::operator==(type_info *this,type_info *param_1)

{
  int iVar1;
  
  iVar1 = _strcmp((char *)(param_1 + 9),(char *)(this + 9));
  return (bool)('\x01' - (iVar1 != 0));
}

