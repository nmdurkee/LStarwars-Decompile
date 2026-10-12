/* Ghidra pseudocode, not original source.
 * ev_a3dc7e4d451c42d041af92cbf24a16255b1dce01fb5c93e82b55e7bce3880be0
 * Entry: 0x511770; label: FUN_00511770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00511770(int param_1)

{
  *(float *)(param_1 + 0x98) = _DAT_00800974 - _DAT_00800994;
  FUN_0050f740(param_1,PTR_s_Retry_008009dc,DAT_00921d60);
  FUN_0050f740(param_1,PTR_s_Cancel_008009d8,DAT_00921d60);
  return;
}

