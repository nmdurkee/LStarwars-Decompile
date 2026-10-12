/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x468840; label: FUN_00468840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00468840(int *param_1,uint param_2,byte param_3)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    return false;
  }
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return false;
  }
  if ((param_3 & 1) != 0) {
    return param_2 != (*(uint *)(iVar1 + 0xa0) >> 4 & 1);
  }
  if (param_2 != 0) {
    FUN_00467470();
    *(uint *)(iVar1 + 0xa0) = *(uint *)(iVar1 + 0xa0) & 0xfffffffe | 0x10;
    return true;
  }
  FUN_00467450(iVar1);
  *(uint *)(iVar1 + 0xa0) = *(uint *)(iVar1 + 0xa0) & 0xffffffef | 1;
  return true;
}

