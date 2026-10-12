/* Ghidra pseudocode, not original source.
 * ev_139f76d7dade80e5283f2bbc23e2b9031909e5f7cb36236e0c190b06f1e16beb
 * Entry: 0x6c1940; label: FUN_006c1940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1940(int *param_1)

{
  int *in_ECX;
  
  if (*param_1 == 0) {
    in_ECX[1] = param_1[1];
  }
  else {
    *(int *)(*param_1 + 4) = param_1[1];
  }
  if ((int *)param_1[1] == (int *)0x0) {
    *in_ECX = *param_1;
  }
  else {
    *(int *)param_1[1] = *param_1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  in_ECX[2] = in_ECX[2] + -1;
  return;
}

