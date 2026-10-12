/* Ghidra pseudocode, not original source.
 * ev_cf2ac3d06457ecccb228c84c214202b97dbe51dc177c28ee443aaf4c995f45e9
 * Entry: 0x5f8110; label: FUN_005f8110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f8110(int *param_1)

{
  int *piVar1;
  float fVar2;
  int local_8;
  
  if (*(short *)((int)param_1 + 10) == 1) {
    fVar2 = 1.0;
  }
  else {
    fVar2 = 1.5;
  }
  local_8 = (int)(longlong)
                 ROUND((float)(int)((uint)*(ushort *)((int)param_1 + 6) *
                                    (uint)*(ushort *)(param_1 + 1) * -4) * fVar2);
  DAT_02854bc0 = DAT_02854bc0 + local_8;
  if ((param_1[0xb] == -1) && (piVar1 = (int *)*param_1, piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *param_1 = 0;
  }
  *(undefined2 *)(param_1 + 1) = 0;
  *(undefined2 *)((int)param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 3) = 0;
  param_1[4] = 1;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *param_1 = 0;
  param_1[0xb] = -1;
  param_1[9] = 0;
  param_1[8] = (int)&DAT_012449d0;
  piVar1 = (int *)param_1[10];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[10] = 0;
  }
  return;
}

