/* Ghidra analysis pseudocode, not original source.
 * ev_a85358c7a67f9df9af49bd13a9e5d6f2df9e1c4faca93f034535aa61df0d1386
 * Entry: 0x5f8470; label: FUN_005f8470
 */

void FUN_005f8470(int *param_1,uint param_2,uint param_3,uint param_4)

{
  int *piVar1;
  float fVar2;
  int local_8;
  
  if (param_1 != (int *)0x0) {
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
    piVar1 = (int *)param_1[10];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      param_1[10] = 0;
    }
    if ((int)param_4 < 1) {
      param_4 = (uint)*(ushort *)(param_1 + 3);
    }
    if ((int)param_3 < 1) {
      param_3 = (uint)*(ushort *)((int)param_1 + 6);
    }
    if ((int)param_2 < 1) {
      param_2 = (uint)*(ushort *)(param_1 + 1);
    }
    FUN_005f81f0(param_1,param_2,param_3,param_4,param_1[6],param_1[7],param_1[5]);
  }
  return;
}

