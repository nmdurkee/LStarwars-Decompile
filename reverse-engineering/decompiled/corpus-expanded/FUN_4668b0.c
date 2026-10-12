/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x4668b0; label: FUN_004668b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004668b0(int param_1)

{
  int iVar1;
  
  DAT_00877ad8 = 0;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    DAT_00877ad8 = FUN_00466840(*(undefined4 *)(param_1 + 0x510));
  }
  return;
}

