/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61f010; label: FUN_0061f010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061f010(int param_1)

{
  do {
    if (param_1 == 0) {
      return;
    }
    param_1 = *(int *)(param_1 + 0x40);
  } while (param_1 != 0);
  return;
}

