/* Ghidra pseudocode, not original source.
 * ev_92748b398136944cd3b8ebaa69598612f81b868998f444146461847577bf6b2d
 * Entry: 0x6dea90; label: FUN_006dea90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dea90(int param_1)

{
  *DAT_0297ace0 = (short)((uint)(param_1 - (int)DAT_0297ace0) >> 4) + -1;
  DAT_0297ace0 = (short *)0x0;
  return;
}

