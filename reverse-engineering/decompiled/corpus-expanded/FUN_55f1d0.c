/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55f1d0; label: FUN_0055f1d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055f1d0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0056e0f0(0x80);
  if ((iVar1 == 0) && ((param_1 == 0 || (*(float *)(param_1 + 0xdec) <= 0.0)))) {
    return 0;
  }
  return 1;
}

