/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x505b20; label: FUN_00505b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00505b20(int param_1)

{
  if ((*(int *)(param_1 + 0x18) != 0) && (DAT_0092139c != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00505b37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_0092139c)();
    return;
  }
  return;
}

