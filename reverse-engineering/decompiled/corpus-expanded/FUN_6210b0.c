/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x6210b0; label: FUN_006210b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006210b0(undefined4 param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = *(undefined4 *)(PTR_DAT_0080f7ec + 0x14);
  FUN_005b4500(param_1,&local_c);
  FUN_005b4cf0(param_1,*(undefined4 *)(PTR_DAT_0080f7ec + 0xc));
  FUN_005b4f70(param_1,*(undefined4 *)(PTR_DAT_0080f7ec + 0x10));
  FUN_005b4900(param_1,PTR_DAT_0080f7ec);
  FUN_005b4900(param_1,PTR_DAT_0080f7ec + 0x18);
  if (DAT_02912e50 != 0) {
    FUN_005b5430(param_1,param_1,DAT_02912e50);
    DAT_02912e50 = 0;
  }
  return;
}

