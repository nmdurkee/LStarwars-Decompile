/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x646a20; label: FUN_00646a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00646a20(int param_1,int param_2)

{
  undefined4 uVar1;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_14;
  if (DAT_02920970 != 0) {
    _sprintf(local_14,"Sound %d Menu",*(int *)(param_2 + 0xc) + 1);
    DAT_02920a14 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_00646a00,local_14);
    if (DAT_02920a14 != 0) {
      uVar1 = FUN_00627a80(*(undefined4 *)(param_2 + 0xc),&DAT_008109d8,0,0,FUN_00646670,
                           "Sound ID...");
      FUN_00618e10(DAT_02920a14,uVar1);
      uVar1 = FUN_00627a80(*(undefined4 *)(param_2 + 0xc),&DAT_008109d8,0,0,FUN_006467d0,
                           "Sound Control...");
      FUN_00618e10(DAT_02920a14,uVar1);
      FUN_006279b0(param_1,DAT_02920a14);
      *(int *)(DAT_02920a14 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02920a14 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_14);
  return;
}

