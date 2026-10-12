/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x6884b0; label: FUN_006884b0
 */

void FUN_006884b0(int param_1)

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
  if (DAT_02923194 != -1) {
    DAT_02962100 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,&LAB_0065a670,"Bounciness");
    if (DAT_02962100 != 0) {
      uVar1 = FUN_00625150(0,&local_10,0,&LAB_00688390,0xbdcccccd,0x3e4ccccd,
                           (&DAT_029300dc)[DAT_02962010 * 0xb5],"Player Grav");
      FUN_00618e10(DAT_02962100,uVar1);
      uVar1 = FUN_00625150(0,&local_10,0,&LAB_006883f0,0,0x3f800000,
                           (&DAT_029300e0)[DAT_02962010 * 0xb5],"Tension");
      FUN_00618e10(DAT_02962100,uVar1);
      uVar1 = FUN_00625150(0,&local_10,0,&LAB_00688450,0,0x3f800000,
                           (&DAT_029300e4)[DAT_02962010 * 0xb5],"Damping");
      FUN_00618e10(DAT_02962100,uVar1);
      FUN_006279b0(param_1,DAT_02962100);
      *(int *)(DAT_02962100 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02962100 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

