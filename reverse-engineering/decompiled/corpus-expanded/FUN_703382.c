/* Ghidra pseudocode, not original source.
 * ev_dafa2233724afb43ee4ce5fb75a2fdf73c0a8c82e75434708f3b2ad0dea6bad5
 * Entry: 0x703382; label: DName::getLastChar
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

