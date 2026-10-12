/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f9de0; label: FUN_004f9de0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004f9de0(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  piVar2 = param_1;
  uVar4 = 0;
  _DAT_0091eeb8 = 0;
  if (*param_1 == 0x12345678) {
    param_1 = param_1 + 3;
  }
  else if (*param_1 == 0x1234567a) {
    param_1 = param_1 + 6;
  }
  else {
    param_1 = param_1 + 5;
  }
  uVar1 = piVar2[1];
  piVar5 = param_1;
  if (uVar1 != 0) {
    do {
      iVar3 = FUN_004f8b10(*piVar5 + (int)piVar2,param_2);
      if (iVar3 == 0) {
        if ((*(byte *)(param_1 + uVar4 * 7 + 4) & 2) != 0) {
          return 0;
        }
        return uVar4 + 1;
      }
      uVar4 = uVar4 + 1;
      piVar5 = piVar5 + 7;
    } while (uVar4 < uVar1);
  }
  return 0;
}

