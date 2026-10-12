/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x60f500; label: FUN_0060f500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060f500(uint *param_1)

{
  uint *in_ECX;
  uint uVar1;
  
  uVar1 = *in_ECX;
  if (*in_ECX <= *param_1) {
    uVar1 = *param_1;
  }
  *in_ECX = uVar1;
  uVar1 = in_ECX[1];
  if (in_ECX[1] <= param_1[1]) {
    uVar1 = param_1[1];
  }
  in_ECX[1] = uVar1;
  uVar1 = in_ECX[2];
  if (in_ECX[2] <= param_1[2]) {
    uVar1 = param_1[2];
  }
  in_ECX[2] = uVar1;
  if (param_1[3] < in_ECX[3]) {
    in_ECX[3] = in_ECX[3];
    return;
  }
  in_ECX[3] = param_1[3];
  return;
}

