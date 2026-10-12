/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x5598e0; label: FUN_005598e0
 */

int * FUN_005598e0(undefined4 param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint *extraout_ECX;
  uint *puVar5;
  int iVar6;
  int iVar7;
  
  piVar1 = (int *)0x0;
  if (DAT_0093b268 != (int *)0x0) {
    piVar1 = (int *)0x0;
    puVar5 = param_3;
    if ((param_2 == (int *)0x0) || (param_3 == (uint *)0x0)) {
      FUN_00559570();
    }
    else if (*param_2 + 0xcU < *param_3) {
      uVar2 = *param_2 + 0xf;
      piVar1 = (int *)(uVar2 & 0xfffffff0);
      *param_2 = (uVar2 & 0xfffffff0) + 0xc;
      *piVar1 = 0;
      piVar1[1] = 0;
      piVar1[2] = 0;
    }
    else {
      FUN_00559570();
      puVar5 = extraout_ECX;
    }
    if (piVar1 != (int *)0x0) {
      piVar3 = (int *)FUN_00559610(param_2,puVar5,*DAT_0093b268 * 0x14);
      *piVar1 = (int)piVar3;
      if (piVar3 != (int *)0x0) {
        iVar6 = DAT_0093b268[2];
        iVar7 = 0;
        if (0 < *DAT_0093b268) {
          do {
            *piVar3 = iVar6;
            if (*(code **)(iVar6 + 0x2c) != (code *)0x0) {
              iVar4 = (**(code **)(iVar6 + 0x2c))(param_1);
              piVar3[2] = iVar4;
            }
            if (piVar3[2] != 0) {
              iVar4 = FUN_00559610(param_2,param_3,piVar3[2] * 8);
              piVar3[3] = iVar4;
            }
            if (*(code **)(iVar6 + 0x88) != (code *)0x0) {
              iVar4 = (**(code **)(iVar6 + 0x88))(param_1);
              piVar3[4] = iVar4;
            }
            iVar7 = iVar7 + 1;
            piVar3 = piVar3 + 5;
            iVar6 = iVar6 + 0x9c;
          } while (iVar7 < *DAT_0093b268);
        }
      }
      if (DAT_00802724 != 0) {
        iVar6 = FUN_00559610(param_2,param_3,DAT_00802724);
        piVar1[1] = iVar6;
      }
    }
  }
  return piVar1;
}

