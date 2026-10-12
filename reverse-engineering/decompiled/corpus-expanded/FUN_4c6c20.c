/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c6c20; label: FUN_004c6c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c6c20(int param_1)

{
  if (DAT_0087bf8c != (code *)0x0) {
    (*DAT_0087bf8c)();
  }
  FUN_004c5460(DAT_008801ac);
  FUN_00595660(*(undefined4 *)(param_1 + 0x2ab4),0x3f800000);
  return;
}

