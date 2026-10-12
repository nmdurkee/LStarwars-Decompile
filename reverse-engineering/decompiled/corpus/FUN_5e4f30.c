/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e4f30; label: FUN_005e4f30
 */

void FUN_005e4f30(undefined4 *param_1,int *param_2,int param_3)

{
  short *psVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  if (0 < param_3) {
    do {
      iVar3 = FUN_005e4ee0(*param_2);
      if (iVar3 == 0) {
        piVar4 = (int *)thunk_FUN_005471c0(DAT_00973ff8);
        puVar5 = (undefined4 *)FUN_005e4b20(1);
        *piVar4 = (int)puVar5;
        piVar4[1] = (int)param_1;
        piVar4[2] = *param_2;
        uVar6 = puVar5[10];
        uVar2 = puVar5[0xb];
        puVar7 = param_1;
        for (iVar3 = 0xb1; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar5 = puVar5 + 1;
        }
        *(undefined2 *)(*piVar4 + 0x1f6) = 0;
        *(undefined2 *)(*piVar4 + 500) = 0;
        *(undefined4 *)(*piVar4 + 0x2c) = uVar2;
        *(undefined4 *)(*piVar4 + 0x28) = uVar6;
        *(ushort *)*piVar4 = *(ushort *)*piVar4 | 1;
        *(int *)(*piVar4 + 0x1f0) = *param_2;
        uVar6 = FUN_007418c0(*(undefined4 *)(*piVar4 + 0x1f0));
        *(undefined4 *)(*piVar4 + 700) = uVar6;
        iVar3 = *piVar4;
        FUN_00601030(iVar3);
        psVar1 = (short *)(iVar3 + 0x2c0);
        *psVar1 = *psVar1 + 1;
      }
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

