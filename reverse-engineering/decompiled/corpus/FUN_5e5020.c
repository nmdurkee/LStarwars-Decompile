/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e5020; label: FUN_005e5020
 */

int FUN_005e5020(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00547580(DAT_00973ff8,0);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      FUN_005e4f30(param_2,(undefined4 *)(param_1 + 0x1f0),1);
      iVar2 = FUN_005e4ee0(*(undefined4 *)(param_1 + 0x1f0));
      return iVar2;
    }
    if ((piVar1[1] == param_2) && (*(int *)(*piVar1 + 0x1f0) == *(int *)(param_1 + 0x1f0))) break;
    piVar1 = (int *)FUN_00547580(DAT_00973ff8,piVar1);
  }
  return *piVar1;
}

