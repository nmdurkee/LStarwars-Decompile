/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x558780; label: FUN_00558780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00558780(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) &&
     ((((*(uint *)(iVar1 + 0x94) & 2) != 0 && ((*(uint *)(iVar1 + 0x94) & 1) != 0)) ||
      (param_3 != 0)))) {
    switch(param_2) {
    case 0:
      if ((*(int *)(iVar1 + 0x34) != 0) && (*(int *)(*(int *)(iVar1 + 0x34) + 0xc) == 2)) {
        return 1;
      }
      break;
    case 1:
      if ((*(int *)(iVar1 + 0x34) != 0) && (*(int *)(*(int *)(iVar1 + 0x34) + 0xc) != 0)) {
        return 1;
      }
      break;
    case 2:
      if ((*(int *)(iVar1 + 0x34) != 0) && (*(int *)(iVar1 + 0x98) != 0)) {
        return 1;
      }
      break;
    case 3:
      if ((*(int *)(iVar1 + 0x34) != 0) && (*(int *)(*(int *)(iVar1 + 0x34) + 0xc) == 0)) {
        return 1;
      }
      break;
    case 4:
      if ((*(int *)(iVar1 + 0x34) != 0) && (*(int *)(*(int *)(iVar1 + 0x34) + 0xc) == 1)) {
        return 1;
      }
    }
  }
  return 0;
}

