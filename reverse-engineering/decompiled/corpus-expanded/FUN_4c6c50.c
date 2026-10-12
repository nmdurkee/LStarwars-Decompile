/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c6c50; label: FUN_004c6c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c6c50(void)

{
  if ((DAT_00880474 != 0) && (DAT_008800e0 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x004c6c62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_008800e0)();
    return;
  }
  return;
}

