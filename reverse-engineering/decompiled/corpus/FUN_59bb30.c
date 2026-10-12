/* Ghidra analysis pseudocode, not original source.
 * ev_0d1e553906e4ac29f0c898728bb3c9cf38177ab98ca2cbcdea8e6b852723dd83
 * Entry: 0x59bb30; label: FUN_0059bb30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0059bb30(int param_1,undefined2 *param_2,int *param_3,uint *param_4)

{
  short sVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  
  if (((DAT_00802854 == -1) || (*(char *)(param_1 + 0x7b5) != DAT_00802854)) &&
     ((DAT_00802838 == -1 ||
      ((*(char *)(param_1 + 0x7b5) != DAT_00802838 || (*(char *)(param_1 + 0x7b8) != '\t')))))) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) || ((*(uint *)(param_1 + 0xef4) & 0x30000) != 0))
      && ((0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28) || (bVar2)))) &&
     (*(char *)(param_1 + 0x1078) != '\0')) {
    iVar5 = FUN_0056bfb0(param_1,(int)*(char *)(param_1 + 0x6c0));
    if (iVar5 == 0) {
      if (ABS(*(float *)(param_1 + 0x6b8)) < _DAT_02998b64) {
        if (bVar2) {
          uVar3 = *(undefined2 *)(param_1 + 0x5a);
        }
        else {
          uVar3 = FUN_0054b3d0(param_1,*(undefined4 *)(param_1 + 0xca4));
        }
        uVar4 = FUN_005be2d0(*(undefined4 *)(param_1 + 0x6b4),*(undefined4 *)(param_1 + 0x6bc));
        uVar6 = FUN_00550040(uVar3,uVar4);
        if (param_4 != (uint *)0x0) {
          *param_4 = uVar6;
        }
        iVar5 = (uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f);
        if ((0x4e38 < iVar5) ||
           (((0x1555 < iVar5 && (sVar1 = *(short *)(param_1 + 0x7aa), sVar1 != -1)) &&
            ((sVar1 == DAT_00804c60 || (sVar1 == DAT_00804c5c)))))) {
          if (param_2 != (undefined2 *)0x0) {
            *param_2 = uVar4;
          }
          if (param_3 != (int *)0x0) {
            *param_3 = (int)*(char *)(param_1 + 0x6c0);
          }
          return 1;
        }
      }
    }
  }
  if (param_3 != (int *)0x0) {
    *param_3 = -1;
  }
  return 0;
}

