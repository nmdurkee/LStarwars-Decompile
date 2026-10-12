/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f1340; label: FUN_004f1340
 */

void FUN_004f1340(int *param_1,int *param_2)

{
  *param_2 = *param_1;
  param_2[1] = 0;
  if (*param_1 != 0) {
    *(int **)(*param_1 + 4) = param_2;
  }
  *param_1 = (int)param_2;
  if (param_1[1] == 0) {
    param_1[1] = (int)param_2;
  }
  return;
}

