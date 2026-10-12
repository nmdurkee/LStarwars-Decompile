/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703382; label: DName::getLastChar
 */

/* Library Function - Single Match
    public: char __thiscall DName::getLastChar(void)const 
   
   Library: Visual Studio 2005 Release */

char __thiscall DName::getLastChar(DName *this)

{
  char cVar1;
  int iVar2;
  int *extraout_ECX;
  int *piVar3;
  int *piVar4;
  
  piVar4 = (int *)0x0;
  iVar2 = isEmpty(this);
  if ((iVar2 == 0) && (piVar3 = (int *)*extraout_ECX, piVar3 != (int *)0x0)) {
    do {
      iVar2 = (**(code **)*piVar3)();
      if (iVar2 != 0) {
        piVar4 = piVar3;
      }
      piVar3 = (int *)piVar3[1];
    } while (piVar3 != (int *)0x0);
    if (piVar4 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x007033b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      cVar1 = (**(code **)(*piVar4 + 4))();
      return cVar1;
    }
  }
  return '\0';
}

