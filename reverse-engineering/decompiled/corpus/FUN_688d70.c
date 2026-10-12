/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x688d70; label: FUN_00688d70
 */

void FUN_00688d70(void)

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
  FUN_0065a510();
  DAT_029211f4 = FUN_005e4d40(1);
  *(undefined4 *)(DAT_029211f4 + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_029211f4 + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_029211f4 + 0x5c) = 0x3f000000;
  *(uint *)(DAT_029211f4 + 0x40) = *(uint *)(DAT_029211f4 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_029211f4 + 0x40) = *(uint *)(DAT_029211f4 + 0x40) & 0xffff3fff;
  *(undefined4 *)(DAT_029211f4 + 0x70) = 0x3f800000;
  *(uint *)(DAT_029211f4 + 0x40) = *(uint *)(DAT_029211f4 + 0x40) & 0xfffffff0;
  FUN_005e4b00(DAT_029211f4);
  DAT_02921190 = FUN_005e4d00(1);
  *(undefined4 *)(DAT_02921190 + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_02921190 + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_02921190 + 0x5c) = 0x3f000000;
  *(uint *)(DAT_02921190 + 0x40) = *(uint *)(DAT_02921190 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02921190 + 0x40) = *(uint *)(DAT_02921190 + 0x40) | 0xc000;
  *(undefined4 *)(DAT_02921190 + 0x70) = 0x3f800000;
  *(uint *)(DAT_02921190 + 0x40) = *(uint *)(DAT_02921190 + 0x40) & 0xfffffff0;
  FUN_005e4b00(DAT_02921190);
  DAT_029620d4 = FUN_00619250(0x46,0x46,0xdc,300,DAT_02912e80,&LAB_0065ae20,"Options");
  if (DAT_029620d4 != 0) {
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065aca0,"Attached Particles...");
    FUN_00618e10(DAT_029620d4,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_00688b00,"Attached Sounds...");
    FUN_00618e10(DAT_029620d4,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_006884b0,"Bounciness...");
    FUN_00618e10(DAT_029620d4,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065a360,"Switch Properties...");
    FUN_00618e10(DAT_029620d4,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,&LAB_0065ae30,"Save Params");
    FUN_00618e10(DAT_029620d4,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,&LAB_00688c00,"Load Params");
    FUN_00618e10(DAT_029620d4,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,&LAB_00688360,"Dump Cube Map");
    FUN_00618e10(DAT_029620d4,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065b2f0,"Memory Card Test Bed...");
    FUN_00618e10(DAT_029620d4,uVar1);
  }
  return;
}

