/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x68a6b0; label: FUN_0068a6b0
 */

void FUN_0068a6b0(int param_1)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if ((DAT_02921884 != -1) && (*(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14) != 0)) {
    DAT_029629a4 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,&LAB_0065ecc0,"Clump Distribution")
    ;
    if (DAT_029629a4 != 0) {
      uVar1 = FUN_00627b80(1,&local_10,
                           *(char *)(DAT_02921884 * 0x50 + 0x26 + DAT_02962a14) == '\x01',1,
                           &LAB_0068a680,"Legacy");
      FUN_00618e10(DAT_029629a4,uVar1);
      uVar1 = FUN_00627b80(2,&local_10,
                           *(char *)(DAT_02921884 * 0x50 + 0x26 + DAT_02962a14) == '\x02',1,
                           &LAB_0068a680,"Random");
      FUN_00618e10(DAT_029629a4,uVar1);
      uVar1 = FUN_00627b80(3,&local_10,
                           *(char *)(DAT_02921884 * 0x50 + 0x26 + DAT_02962a14) == '\x03',1,
                           &LAB_0068a680,"Linear");
      FUN_00618e10(DAT_029629a4,uVar1);
      uVar1 = FUN_00627b80(4,&local_10,
                           *(char *)(DAT_02921884 * 0x50 + 0x26 + DAT_02962a14) == '\x04',1,
                           &LAB_0068a680,"Bell Curve");
      FUN_00618e10(DAT_029629a4,uVar1);
      FUN_006279b0(param_1,DAT_029629a4);
      *(int *)(DAT_029629a4 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029629a4 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

