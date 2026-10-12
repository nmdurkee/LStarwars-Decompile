/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x5805b0; label: FUN_005805b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005805b0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
    *(undefined2 *)(DAT_00951cc0 + 100) = uVar1;
  }
  return;
}

