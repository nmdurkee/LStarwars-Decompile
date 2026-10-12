/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x5621a0; label: FUN_005621a0
 */

undefined4 FUN_005621a0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  float10 fVar3;
  
  FUN_00548020(param_1,0,0);
  if (DAT_0080287c == -1) goto LAB_00562300;
  if ((param_2 == 0xffffffff) ||
     (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + param_2 * 4) == 0)) {
    if (DAT_0093d824 != (code *)0x0) {
      iVar2 = (*DAT_0093d824)(param_1);
      if (iVar2 != 0) {
        param_2 = (uint)DAT_00804c14;
        if ((DAT_00804c14 != 0xffff) &&
           (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + (short)DAT_00804c14 * 4) != 0))
        goto LAB_00562270;
      }
    }
    if (DAT_00955584 != (code *)0x0) {
      iVar2 = (*DAT_00955584)(param_1);
      if (iVar2 != 0) {
        param_2 = (uint)DAT_00804d04;
        if ((DAT_00804d04 != 0xffff) &&
           (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + (short)DAT_00804d04 * 4) != 0))
        goto LAB_00562270;
      }
    }
    param_2 = (uint)DAT_00804c10;
    if ((DAT_00804c10 == 0xffff) ||
       (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + (short)DAT_00804c10 * 4) == 0)) {
      param_2 = (uint)DAT_00804bfc;
      if ((DAT_00804bfc == 0xffff) ||
         (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + (short)DAT_00804bfc * 4) == 0)) {
        param_2 = (uint)DAT_00804bf0;
      }
    }
  }
LAB_00562270:
  *(short *)(param_1 + 0x7aa) = (short)param_2;
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + (short)param_2 * 4) != 0) {
    *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_0080287c;
    FUN_0062e650(param_1 + 8,0xffffffff);
    FUN_0062e690(param_1 + 2000,0xffffffff);
    *(undefined4 *)(param_1 + 0xdac) = 0;
    fVar3 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)*(short *)(param_1 + 0x7aa)
                                  ,0,0,1);
    *(float *)(param_1 + 0x77c) = (float)fVar3;
    uVar1 = *(uint *)(param_1 + 0xe24);
    *(uint *)(param_1 + 0xe24) = (uVar1 * 2 ^ uVar1) & 0x800 ^ uVar1;
    return 1;
  }
LAB_00562300:
  *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfffffbff;
  return 0;
}

