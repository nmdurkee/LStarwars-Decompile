/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x6210b0; label: FUN_006210b0
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

