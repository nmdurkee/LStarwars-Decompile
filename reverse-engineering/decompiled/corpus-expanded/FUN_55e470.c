/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55e470; label: FUN_0055e470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0055e470(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 * 0x4c + 4 + DAT_0093b274);
  if ((undefined *)(uVar1 & 0x1000010) == &DAT_01000010) {
    return false;
  }
  return (uVar1 & 0x40088) != 0;
}

