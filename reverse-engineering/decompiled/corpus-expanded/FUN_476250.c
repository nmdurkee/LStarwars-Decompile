/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x476250; label: FUN_00476250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00476250(int param_1,int param_2)

{
  if ((DAT_0093b324 != 0) && ((param_1 == 0 || (param_1 == 1)))) {
    if ((param_2 == 0) || (param_2 == 1)) {
      FUN_00475fb0();
      return;
    }
    if (param_2 == -1) {
      FUN_00476010(param_1);
    }
  }
  return;
}

