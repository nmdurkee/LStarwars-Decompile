/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55c880; label: FUN_0055c880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055c880(void)

{
  if ((DAT_0093b2b4 != 0) && ((*(byte *)(DAT_0093b2b4 + 3) & 1) != 0)) {
    return 1;
  }
  return 0;
}

