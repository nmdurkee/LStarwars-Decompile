/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e4f80; label: FUN_004e4f80
 */

void FUN_004e4f80(int param_1)

{
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,"reactor_1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aae4,"reactor_2",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aaf0,"reactor_3",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aafc,"reactor_4",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ab08,"reactor_5",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ab14,"reactor_6",1);
  DAT_0087aa25 = 0;
  DAT_0087aa24 = 0;
  DAT_0087aa23 = 0;
  DAT_0087aa22 = 0;
  DAT_0087aa21 = 0;
  DAT_0087aa20 = 0;
  DAT_0087aa7c = FUN_00650dc0("env_tractorbeam_lp");
  DAT_0087aa80 = FUN_00650dc0("env_tractorbeam_off");
  return;
}

