/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c8c40; label: FUN_004c8c40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c8c40(int param_1)

{
  DAT_00880548 = FUN_00578750(7);
  FUN_00566630(3);
  FUN_00566640(FUN_004c8bd0);
  FUN_004e5fe0(param_1);
  DAT_00880564 = 0;
  FUN_00433120();
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,"clear1_ffield1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aae4,"clear1_ffield2",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aaf0,"clear2_ffield1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aafc,"clear2_ffield2",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ab08,"clear1_ffield1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ab14,"clear3_ffield1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ab20,"clear3_ffield2",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ab2c,"clear4_ffield1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ab38,"clear4_ffield2",1);
  _DAT_00880560 = 0;
  _DAT_0088055c = 0;
  _DAT_0087aa38 = 0;
  _DAT_0087aa3c = 0;
  DAT_0087aa40 = 0;
  _DAT_00880554 = 0;
  _DAT_00880550 = 0;
  return;
}

