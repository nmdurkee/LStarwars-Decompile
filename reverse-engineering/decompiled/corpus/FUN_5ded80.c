/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5ded80; label: FUN_005ded80
 */

void FUN_005ded80(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  FUN_004ffaa0(DAT_00973fa4);
  iVar1 = DAT_009739b8;
  if (0xff < DAT_009739b8) {
    iVar1 = FUN_005c12e0();
  }
  (&DAT_009739bc)[iVar1] = param_1;
  DAT_009739b8 = DAT_009739b8 + 1;
  FUN_005ddd10(1);
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x60)) {
    iVar3 = 0;
    do {
      if (DAT_00973ff4 != 0) {
        piVar2 = (int *)(*(int *)(param_1 + 100) + iVar3);
        *piVar2 = *piVar2 + DAT_00973ff4 * 0x20000;
      }
      FUN_005de060();
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar1 < *(int *)(param_1 + 0x60));
  }
  if (*(int *)(param_1 + 0x8c) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x8c) + 0xc) = DAT_00973fa8;
    DAT_00973fa8 = *(undefined4 *)(param_1 + 0x8c);
  }
  *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) & 0xffffdfef;
  *(undefined4 *)(param_1 + 0x68) = 0;
  FUN_00603980(param_1);
  FUN_004ffac0();
  return;
}

