/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x68ad00; label: FUN_0068ad00
 */

void FUN_0068ad00(int param_1)

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
    DAT_02962998 = FUN_00619250(0x46,0x46,0xdc,0xfa,DAT_02912e80,&LAB_0065ed20,"Clump Properties");
    if (DAT_02962998 != 0) {
      uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0068a2d0,"Clump Sizes...");
      FUN_00618e10(DAT_02962998,uVar1);
      if (*(char *)(DAT_02921884 * 0x50 + 0x27 + DAT_02962a14) == '\x03') {
        uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Clump Area Type...");
        FUN_00618e10(DAT_02962998,uVar1);
        uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Clump Distribution...");
      }
      else {
        uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0068a4c0,"Clump Area Type...");
        FUN_00618e10(DAT_02962998,uVar1);
        uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0068a6b0,"Clump Distribution...");
      }
      FUN_00618e10(DAT_02962998,uVar1);
      uVar1 = FUN_00627a80(1,&local_10,0,0,&LAB_0068a950,"Clump Fading...");
      FUN_00618e10(DAT_02962998,uVar1);
      uVar1 = FUN_00627a80(1,&local_10,0,0,&LAB_0068ab90,"Clump Terraining...");
      FUN_00618e10(DAT_02962998,uVar1);
      iVar2 = DAT_02962a14 + DAT_02921884 * 0x50;
      if (*(char *)(iVar2 + 0x27) == '\x01') {
        uVar1 = FUN_00625150(0,&local_10,0,&LAB_0068a010,0x3c23d70a,0x3ffeb852,
                             *(undefined4 *)(iVar2 + 0x18),&DAT_0076e58c);
        FUN_00618e10(DAT_02962998,uVar1);
      }
      uVar1 = FUN_00627bc0(0,&local_10,*(undefined4 *)(DAT_02921884 * 0x50 + 0x1c + DAT_02962a14),1,
                           &LAB_0065ea20,"Collide with Player");
      FUN_00618e10(DAT_02962998,uVar1);
      FUN_006279b0(param_1,DAT_02962998);
      *(int *)(DAT_02962998 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02962998 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

