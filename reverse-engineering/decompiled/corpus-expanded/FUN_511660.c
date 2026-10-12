/* Ghidra pseudocode, not original source.
 * ev_a3dc7e4d451c42d041af92cbf24a16255b1dce01fb5c93e82b55e7bce3880be0
 * Entry: 0x511660; label: FUN_00511660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00511660(int param_1)

{
  *(undefined4 *)(param_1 + 0x98) = _DAT_00800974;
  FUN_0050f740(param_1,PTR_DAT_008009d4,DAT_00921d60);
  return;
}

