/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x414340; label: FUN_00414340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00414340(int *param_1)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined **ppuVar7;
  undefined4 *puVar8;
  
  iVar6 = 0;
  if (0 < DAT_0093b278) {
    iVar3 = 0;
    iVar5 = 0;
    do {
      ppuVar7 = &PTR_FUN_00802968;
      puVar8 = (undefined4 *)(iVar5 + DAT_0093b284);
      for (iVar4 = 0x48; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *ppuVar7;
        ppuVar7 = ppuVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      if (*(int *)(iVar3 + DAT_0093b274) == -1) {
        *(int *)(iVar3 + DAT_0093b274) = (int)DAT_008806a0;
      }
      if (*(int *)(iVar3 + 0x18 + DAT_0093b274) == 0) {
        *(code **)(iVar3 + 0x18 + DAT_0093b274) = FUN_004b4ac0;
      }
      if (*(int *)(iVar3 + 0x1c + DAT_0093b274) == 0) {
        *(code **)(iVar3 + 0x1c + DAT_0093b274) = FUN_004a8f20;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x120;
      iVar3 = iVar3 + 0x4c;
    } while (iVar6 < DAT_0093b278);
  }
  if (param_1 != (int *)0x0) {
    iVar6 = *param_1;
    while (iVar6 != 0) {
      if (param_1[1] != 0) {
        uVar2 = FUN_0055b1c0(iVar6);
        *(undefined2 *)param_1[1] = uVar2;
      }
      piVar1 = param_1 + 2;
      param_1 = param_1 + 2;
      iVar6 = *piVar1;
    }
  }
  return;
}

