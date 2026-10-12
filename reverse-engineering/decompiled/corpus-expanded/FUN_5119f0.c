/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x5119f0; label: FUN_005119f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005119f0(int param_1)

{
  FUN_00510fd0();
  *(undefined4 *)(param_1 + 0x98) = _DAT_00800974;
  FUN_0050f740(param_1,PTR_DAT_008009d4,DAT_00921d60);
  return;
}

