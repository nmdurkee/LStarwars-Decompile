/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x55a020; label: FUN_0055a020
 */

int FUN_0055a020(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int local_4;
  
  if (((DAT_0093b268 != (int *)0x0) && (param_1 != (int *)0x0)) && (param_3 != 0)) {
    if ((param_2 < 0) || (*DAT_0093b268 < param_2)) {
      local_4 = 0;
      if (0 < *DAT_0093b268) {
        piVar9 = (int *)(*param_1 + 4);
        piVar5 = (int *)(DAT_0093b268[2] + 0x44);
        piVar3 = DAT_0093b268;
        do {
          if (*piVar5 != 0) {
            iVar7 = piVar9[2];
            iVar6 = 0;
            if (0 < *piVar9) {
              do {
                uVar1 = (*(code *)*piVar5)(iVar7);
                iVar8 = FUN_004f8b10(uVar1,param_3);
                if (iVar8 == 0) {
                  return iVar7;
                }
                iVar6 = iVar6 + 1;
                iVar7 = iVar7 + 8;
                piVar3 = DAT_0093b268;
              } while (iVar6 < *piVar9);
            }
          }
          local_4 = local_4 + 1;
          piVar5 = piVar5 + 0x27;
          piVar9 = piVar9 + 5;
        } while (local_4 < *piVar3);
        return 0;
      }
    }
    else {
      iVar6 = param_2 * 0x9c + DAT_0093b268[2];
      iVar7 = *param_1 + param_2 * 0x14;
      if ((*(int *)(iVar6 + 0x44) != 0) && (iVar8 = *(int *)(iVar7 + 0xc), 0 < *(int *)(iVar7 + 4)))
      {
        iVar4 = 0;
        do {
          uVar1 = (**(code **)(iVar6 + 0x44))(iVar8);
          iVar2 = FUN_004f8b10(uVar1,param_3);
          if (iVar2 == 0) {
            return iVar8;
          }
          iVar4 = iVar4 + 1;
          iVar8 = iVar8 + 8;
        } while (iVar4 < *(int *)(iVar7 + 4));
      }
    }
  }
  return 0;
}

