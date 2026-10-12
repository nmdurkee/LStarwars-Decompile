/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55e4a0; label: FUN_0055e4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055e4a0(int param_1,undefined4 param_2)

{
  if (DAT_0093d828 != (code *)0x0) {
    (*DAT_0093d828)(param_1,param_2);
  }
  FUN_005b2cf0(param_1);
  FUN_005999a0(param_1);
  FUN_0058b0f0(param_1);
  *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfffff3ff;
  return;
}

