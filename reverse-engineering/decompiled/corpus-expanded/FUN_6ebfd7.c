/* Ghidra pseudocode, not original source.
 * ev_071b5a91353aec3b9b3ca880d0ad8ff1dbba963601d7a5f67d3b8ab6c7f681aa
 * Entry: 0x6ebfd7; label: __cinit
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 2005 Release */

int __cdecl __cinit(int param_1)

{
  BOOL BVar1;
  int iVar2;
  undefined4 *puVar3;
  
  BVar1 = __IsNonwritableInCurrentImage((PBYTE)&PTR___fpmath_00777ce8);
  if (BVar1 != 0) {
    __fpmath(param_1);
  }
  __initp_misc_cfltcvt_tab();
  iVar2 = __initterm_e(&DAT_00751414,&DAT_00751430);
  if (iVar2 == 0) {
    _atexit((_func_4879 *)&LAB_006f1515);
    puVar3 = &DAT_0075134c;
    do {
      if ((code *)*puVar3 != (code *)0x0) {
        (*(code *)*puVar3)();
      }
      puVar3 = puVar3 + 1;
    } while (puVar3 < &DAT_00751410);
    if ((DAT_029a9c5c != (code *)0x0) &&
       (BVar1 = __IsNonwritableInCurrentImage((PBYTE)&DAT_029a9c5c), BVar1 != 0)) {
      (*DAT_029a9c5c)(0,2,0);
    }
    iVar2 = 0;
  }
  return iVar2;
}

