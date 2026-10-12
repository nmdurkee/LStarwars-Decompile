/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x665c50; label: FUN_00665c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00665c50(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_24;
  local_24 = 0x80000000;
  local_20 = 0x80ff0000;
  local_1c = 0x80808080;
  local_18 = 0x80404040;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    _sprintf(local_14,"Sound %d Menu",*(int *)(param_2 + 0xc) + 1);
    DAT_02962a58 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_00665c30,local_14);
    if (DAT_02962a58 != 0) {
      uVar1 = FUN_00627a80(*(undefined4 *)(param_2 + 0xc),&local_24,0,0,FUN_00665830,"Sound ID...");
      FUN_00618e10(DAT_02962a58,uVar1);
      uVar1 = FUN_00627a80(*(undefined4 *)(param_2 + 0xc),&local_24,0,0,FUN_006659d0,
                           "Sound Control...");
      FUN_00618e10(DAT_02962a58,uVar1);
      FUN_006279b0(param_1,DAT_02962a58);
      *(int *)(DAT_02962a58 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02962a58 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_24);
  return;
}

