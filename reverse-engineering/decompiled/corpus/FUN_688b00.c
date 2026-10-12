/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x688b00; label: FUN_00688b00
 */

void FUN_00688b00(int param_1)

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
  if (DAT_02962010 != -1) {
    DAT_029620f0 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,&LAB_0065ae00,"Attached Sounds");
    if (DAT_029620f0 != 0) {
      uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_006886a0,"Sound Type...");
      FUN_00618e10(DAT_029620f0,uVar1);
      if (DAT_02920aa8 != -1) {
        uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_006888d0,"Highlighted Snd Settings...");
        FUN_00618e10(DAT_029620f0,uVar1);
      }
      FUN_006279b0(param_1,DAT_029620f0);
      *(int *)(DAT_029620f0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029620f0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

