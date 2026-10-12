/* Ghidra pseudocode, not original source.
 * ev_6ea325c01e2f5d3a14c4ac5085e7df4745032b0fec5c1eb605a31240a38307be
 * Entry: 0x540070; label: FUN_00540070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00540070(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 < 0x10) {
      FUN_004f1f10();
      return;
    }
  }
  return;
}

