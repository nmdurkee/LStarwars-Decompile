/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d90c0; label: FUN_005d90c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d90c0(int param_1,int param_2)

{
  if (param_1 != 0) {
    if (param_2 != 0) {
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 1;
      return;
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}

