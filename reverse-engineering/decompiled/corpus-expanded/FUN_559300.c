/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x559300; label: FUN_00559300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00559300(int *param_1,uint param_2,byte param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return 0;
  }
  if (((*(uint *)(iVar1 + 0x94) & 0x100) != 0) &&
     ((iVar2 = *(int *)(*(int *)(iVar1 + 0x34) + 0xc), iVar2 == 2 || (iVar2 == 1)))) {
    *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) & 0xfffffeff | 1;
  }
  uVar3 = *(uint *)(iVar1 + 0x9c) >> 2 & 1;
  if (uVar3 != 0) {
    *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) & 0xfffffeff | 1;
  }
  if ((param_3 & 1) == 0) {
    if (param_2 != 0) {
      FUN_005579d0(iVar1);
      *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) & 0xfffffffe | 0x100;
      return 1;
    }
    *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) & 0xfffffeff | 1;
  }
  else {
    if (param_2 == (*(uint *)(iVar1 + 0x94) >> 8 & 1)) {
      if ((param_3 & 4) == 0) {
        return 0;
      }
      if ((*(uint *)(iVar1 + 0x94) >> 1 & 1) != param_2) {
        return 0;
      }
    }
    if ((param_2 == 1) && (uVar3 != 0)) {
      return 0;
    }
  }
  return 1;
}

