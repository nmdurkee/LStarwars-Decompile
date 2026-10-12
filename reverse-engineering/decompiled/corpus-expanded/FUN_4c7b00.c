/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c7b00; label: FUN_004c7b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004c7b00(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return *param_1 + 0x50;
  }
  return 0;
}

