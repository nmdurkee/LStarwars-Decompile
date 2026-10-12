/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56d450; label: FUN_0056d450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0056d450(int *param_1,uint param_2,byte param_3)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (iVar1 = *param_1, iVar1 == 0)) {
    return false;
  }
  if ((param_3 & 1) != 0) {
    return param_2 != (*(byte *)(iVar1 + 0x34) >> 3 & 1);
  }
  if (param_2 != 0) {
    *(byte *)(iVar1 + 0x34) = *(byte *)(iVar1 + 0x34) & 0xfe | 8;
    return true;
  }
  *(byte *)(iVar1 + 0x34) = *(byte *)(iVar1 + 0x34) & 0xf7 | 1;
  return true;
}

