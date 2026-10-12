/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x504d70; label: FUN_00504d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00504d70(int *param_1)

{
  if (*param_1 != 0) {
    *(int *)(*param_1 + 4) = param_1[1];
  }
  if ((int *)param_1[1] != (int *)0x0) {
    *(int *)param_1[1] = *param_1;
    return;
  }
  DAT_009212dc = *param_1;
  return;
}

