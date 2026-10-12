/* Ghidra pseudocode, not original source.
 * ev_7628bb02d4360686842aba648e3e8351ab050d06c55da9366e8a0a89d745bc47
 * Entry: 0x6a3d70; label: FUN_006a3d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006a3d70(int *param_1)

{
  uint uVar1;
  
  if (*param_1 < param_1[4]) {
    uVar1 = *(byte *)param_1[3] >> (7U - (char)param_1[1] & 0x1f) & 1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  param_1[1] = param_1[1] + 1;
  if (7 < param_1[1]) {
    param_1[3] = param_1[3] + 1;
    param_1[1] = 0;
    *param_1 = *param_1 + 1;
  }
  return uVar1;
}

