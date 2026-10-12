/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61a8c0; label: FUN_0061a8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061a8c0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int local_20;
  float local_1c;
  float local_18;
  float local_14;
  longlong local_10;
  
  piVar3 = *(int **)(param_1 + 0x4c);
  local_20 = 0;
  if (piVar3 != (int *)0x0) {
    piVar1 = (int *)(param_2 + 8);
    do {
      if (local_20 < param_3) {
        piVar1[-2] = piVar3[2];
        piVar1[-1] = piVar3[4];
        *piVar1 = piVar3[5];
        piVar1[1] = piVar3[6];
        FUN_00618180(piVar3[4],piVar3[5],piVar3[6],&local_1c);
        piVar1[2] = (int)local_1c;
        piVar1[3] = (int)local_18;
        piVar1[4] = (int)local_14;
        local_10._0_4_ = (int)(longlong)ROUND(local_14 * -255.0);
        iVar2 = (int)local_10 + 0x8000;
        local_10._0_4_ = (int)(longlong)ROUND(local_18 * -255.0);
        iVar2 = iVar2 * 0x100 + (int)local_10;
        local_10 = (longlong)ROUND(local_1c * 255.0);
        piVar1[5] = (int)local_10 + iVar2 * -0x100;
        piVar1[6] = piVar3[7];
      }
      piVar3 = (int *)*piVar3;
      local_20 = local_20 + 1;
      piVar1 = piVar1 + 9;
    } while (piVar3 != (int *)0x0);
  }
  return;
}

