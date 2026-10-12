/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x652450; label: FUN_00652450
 */

void FUN_00652450(int *param_1)

{
  int iVar1;
  int iVar2;
  
  DAT_02962028 = param_1;
  DAT_0296202c = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = 0;
    iVar1 = *param_1;
    while (iVar1 != 0) {
      FUN_004f1ff0(iVar1);
      DAT_0296202c = DAT_0296202c + 1;
      iVar2 = iVar2 + 1;
      iVar1 = param_1[iVar2 * 7];
    }
  }
  return;
}

