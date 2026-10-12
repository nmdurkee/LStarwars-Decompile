/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x68a2d0; label: FUN_0068a2d0
 */

void FUN_0068a2d0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if ((DAT_02921884 != -1) && (*(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14) != 0)) {
    DAT_0296299c = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,&LAB_0065ec80,"Clump Sizes");
    if (DAT_0296299c != 0) {
      uVar1 = FUN_00625150(0,&local_10,0,&LAB_0068a040,0,0x40a00000,
                           *(undefined4 *)(DAT_02921884 * 0x50 + 0x2c + DAT_02962a14),
                           "Min Model Size");
      FUN_00618e10(DAT_0296299c,uVar1);
      uVar1 = FUN_00625150(0,&local_10,0,&LAB_0068a070,0,0x40a00000,
                           *(undefined4 *)(DAT_02921884 * 0x50 + 0x30 + DAT_02962a14),
                           "Max Model Size");
      FUN_00618e10(DAT_0296299c,uVar1);
      iVar2 = DAT_02962a14 + DAT_02921884 * 0x50;
      if (*(char *)(iVar2 + 0x27) == '\x01') {
        uVar1 = FUN_00625150(0,&local_10,0,&LAB_0068a0a0,0x3dcccccd,0x411e6666,
                             *(undefined4 *)(iVar2 + 0x20),"Bend Height");
        FUN_00618e10(DAT_0296299c,uVar1);
      }
      FUN_006279b0(param_1,DAT_0296299c);
      *(int *)(DAT_0296299c + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_0296299c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

