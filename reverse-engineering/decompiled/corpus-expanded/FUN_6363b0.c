/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x6363b0; label: FUN_006363b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006363b0(int param_1)

{
  FUN_00633e40(param_1 + 0x9c,param_1 + 0x84);
  _DAT_009716e8 = *(undefined4 *)(param_1 + 0xc0);
  _DAT_009716ec = *(undefined4 *)(param_1 + 0xc4);
  _DAT_009716f0 = *(undefined4 *)(param_1 + 200);
  FUN_005fca90();
  return;
}

