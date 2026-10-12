/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a3510; label: FUN_005a3510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a3510(int param_1)

{
  int *in_EAX;
  
  if ((int *)in_EAX[1] == (int *)0x0) {
    *(int *)(param_1 + 8) = *in_EAX;
  }
  else {
    *(int *)in_EAX[1] = *in_EAX;
  }
  if (*in_EAX != 0) {
    *(int *)(*in_EAX + 4) = in_EAX[1];
    *in_EAX = (int)DAT_0095da38;
    DAT_0095da38 = in_EAX;
    return;
  }
  *in_EAX = (int)DAT_0095da38;
  DAT_0095da38 = in_EAX;
  return;
}

