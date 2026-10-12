/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f3bf0; label: FUN_004f3bf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f3bf0(int *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_2;
  uVar2 = *param_3;
  if (uVar2 <= uVar1) {
    *param_1 = uVar1 - uVar2;
    param_1[1] = param_2[1] - param_3[1];
    return;
  }
  *param_1 = uVar1 - uVar2;
  param_1[1] = (param_2[1] - param_3[1]) + -1;
  return;
}

