/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1410; label: FUN_004f1410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f1410(int *param_1,int *param_2)

{
  if (*param_2 == 0) {
    param_1[1] = param_2[1];
  }
  else {
    *(int *)(*param_2 + 4) = param_2[1];
  }
  if ((int *)param_2[1] != (int *)0x0) {
    *(int *)param_2[1] = *param_2;
    return;
  }
  *param_1 = *param_2;
  return;
}

