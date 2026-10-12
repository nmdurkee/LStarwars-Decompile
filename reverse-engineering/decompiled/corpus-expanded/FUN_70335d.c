/* Ghidra pseudocode, not original source.
 * ev_dafa2233724afb43ee4ce5fb75a2fdf73c0a8c82e75434708f3b2ad0dea6bad5
 * Entry: 0x70335d; label: DName::length
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    public: int __thiscall DName::length(void)const 
   
   Library: Visual Studio 2005 Release */

int __thiscall DName::length(DName *this)

{
  int iVar1;
  undefined4 *extraout_ECX;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = isEmpty(this);
  if (iVar1 == 0) {
    for (puVar2 = (undefined4 *)*extraout_ECX; puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)puVar2[1]) {
      iVar1 = (**(code **)*puVar2)();
      iVar3 = iVar3 + iVar1;
    }
  }
  return iVar3;
}

