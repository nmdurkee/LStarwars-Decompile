/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dddc0; label: FUN_006dddc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dddc0(void)

{
  if (DAT_02975c4c != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x006dddc9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_02975c4c)();
    return;
  }
  return;
}

