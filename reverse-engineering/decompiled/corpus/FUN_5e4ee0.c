/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e4ee0; label: FUN_005e4ee0
 */

int FUN_005e4ee0(int param_1)

{
  int *piVar1;
  int unaff_EDI;
  
  piVar1 = (int *)FUN_00547580(DAT_00973ff8,0);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if ((piVar1[1] == unaff_EDI) && (*(int *)(*piVar1 + 0x1f0) == param_1)) break;
    piVar1 = (int *)FUN_00547580(DAT_00973ff8,piVar1);
  }
  return *piVar1;
}

