/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4b30e0; label: FUN_004b30e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b30e0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  FUN_0058d8b0(param_1);
  if (*(char *)(param_1 + 0x7b5) == '\x17') {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28);
  }
  FUN_004abac0(param_1,0,uVar1,0x41000000,0);
  FUN_004b0c80();
  if ((*(byte *)(param_1 + 0xeec) & 8) != 0) {
    if ((*(short *)(param_1 + 0x1064) == DAT_007f192c) ||
       (*(short *)(param_1 + 0x1064) == DAT_007f1930)) {
      FUN_004b3d40(param_1,*(uint *)(*(int *)(param_1 + 0xca4) + 8) & (DAT_00802280 | DAT_0080227c),
                   0,0,0,0);
    }
    FUN_004a6c30(*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_0080227c,0,0x3ecccccd,1);
  }
  FUN_004a82a0(param_1,0);
  if (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28)) {
    uVar2 = FUN_00550040(*(undefined2 *)(param_1 + 0x1060),*(undefined2 *)(param_1 + 0x27a));
    if (_DAT_00925018 * 910.0 < (float)(int)((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f))) {
      if ((*(short *)(param_1 + 0x1064) != DAT_007f192c) &&
         (*(short *)(param_1 + 0x1064) != DAT_007f1930)) {
        FUN_00681f40("R2Move",param_1 + 0x80);
        return;
      }
      FUN_00681f40("fly_paddle_rotate_lp",param_1 + 0x80);
    }
  }
  return;
}

