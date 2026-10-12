/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x694320; label: FUN_00694320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00694320(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int extraout_ECX;
  uint uVar3;
  int iVar4;
  
  if ((in_ECX == (int *)0x0) || (DAT_02962b8c == 0)) {
    return 0xffffffff;
  }
  iVar1 = in_ECX[0x76];
  iVar4 = param_2;
  if (iVar1 != 0) {
    if (param_2 == 0) {
      iVar4 = FUN_00693e50(param_1);
      if (iVar4 == -1) {
        return 0xffffffff;
      }
      if (*(int *)(iVar1 + 0xc + iVar4 * 4) == 0) {
        return 0xffffffff;
      }
      return (*(int *)(iVar1 + 0xc + iVar4 * 4) - *(int *)(iVar1 + 4)) / 0x3c |
             ((iVar1 - *in_ECX) / 0x24) * 0x800;
    }
    uVar3 = 0;
    if (0 < *(int *)(iVar1 + 8)) {
      iVar4 = 0;
      do {
        if (((*(int *)(*(int *)(iVar1 + 4) + 0x14 + iVar4) == param_1) &&
            (iVar1 = *(int *)(*(int *)(iVar1 + 4) + iVar4 + 8), iVar1 != 0)) &&
           (iVar1 = FUN_004f8b10(iVar1,param_2), iVar1 == 0)) {
          return ((in_ECX[0x76] - *in_ECX) / 0x24) * 0x800 | uVar3;
        }
        iVar1 = in_ECX[0x76];
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0x3c;
      } while ((int)uVar3 < *(int *)(iVar1 + 8));
    }
    FUN_00693b70(param_2);
    iVar4 = extraout_ECX;
  }
  if (iVar4 != 0) {
    uVar3 = 0;
    if (0 < in_ECX[3]) {
      iVar1 = 0;
      do {
        if (((*(int *)(iVar1 + in_ECX[2] + 0x14) == param_1) &&
            (iVar2 = *(int *)(iVar1 + in_ECX[2] + 8), iVar2 != 0)) &&
           (iVar2 = FUN_004f8b10(iVar2,iVar4), iVar4 = param_2, iVar2 == 0)) {
          return in_ECX[1] << 0xb | uVar3;
        }
        uVar3 = uVar3 + 1;
        iVar1 = iVar1 + 0x3c;
      } while ((int)uVar3 < in_ECX[3]);
    }
    FUN_00693b70(iVar4);
  }
  return 0xffffffff;
}

