/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x632a60; label: FUN_00632a60
 */

undefined4 FUN_00632a60(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *unaff_ESI;
  int *unaff_retaddr;
  int in_stack_00000024;
  undefined4 uVar5;
  undefined4 **ppuVar6;
  undefined4 *local_8;
  int *piStack_4;
  
  if ((uint)param_1[7] < (uint)param_1[10]) {
    piVar1 = *(int **)(param_1[0x12] + param_1[7] * 4);
    ppuVar6 = &local_8;
    uVar5 = 0;
    iVar2 = (**(code **)(*piVar1 + 0x4c))
                      (piVar1,0,ppuVar6,0,-(uint)(in_stack_00000024 != 0) & 0x2000);
    if (-1 < iVar2) {
      if (unaff_ESI != (int *)0x0) {
        *unaff_ESI = (int)ppuVar6;
      }
      if (local_8 != (undefined4 *)0x0) {
        *local_8 = uVar5;
      }
      if (piStack_4 != (int *)0x0) {
        *piStack_4 = param_1[2];
      }
      uVar4 = (uint)(param_1[0xd] != 0) + param_1[0xb];
      uVar3 = (uint)param_1[7] / uVar4;
      uVar4 = param_1[7] - uVar3 * uVar4;
      if (unaff_retaddr != (int *)0x0) {
        *unaff_retaddr = param_1[0x11] * uVar4;
      }
      if (param_1 != (int *)0x0) {
        *param_1 = param_1[0x11] * uVar3;
      }
      if (param_2 != (int *)0x0) {
        if (uVar4 < (uint)param_1[0xb]) {
          iVar2 = param_1[0x11];
        }
        else {
          iVar2 = param_1[0xd];
        }
        *param_2 = iVar2;
      }
      if (param_3 != (int *)0x0) {
        if ((uint)param_1[0xc] <= uVar3) {
          *param_3 = param_1[0xe];
          param_1[7] = param_1[7] + 1;
          return 1;
        }
        *param_3 = param_1[0x11];
      }
      param_1[7] = param_1[7] + 1;
      return 1;
    }
  }
  param_1[7] = 0;
  return 0;
}

