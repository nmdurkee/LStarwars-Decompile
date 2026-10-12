/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bd840; label: FUN_006bd840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bd840(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  if (param_1 == 0) {
    in_ECX[1] = 0;
  }
  if (in_ECX[1] < *in_ECX) {
    while (in_ECX[1] < *in_ECX) {
      iVar1 = (**(code **)(*(int *)in_ECX[in_ECX[1] * 2 + 3] + 0x14))(param_1);
      if (iVar1 != 0) {
        return;
      }
      in_ECX[1] = in_ECX[1] + 1;
      param_1 = 0;
    }
  }
  return;
}

