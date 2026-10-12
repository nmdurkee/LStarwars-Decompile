/* Ghidra pseudocode, not original source.
 * ev_de7bd3aa239ec0c059aa1bbec058a25d35da9446e5dffd1cda86600a1f15d21b
 * Entry: 0x6585c0; label: FUN_006585c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006585c0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_4;
  
  iVar3 = 0;
  iVar4 = 0;
  local_4 = 0;
  if (0 < DAT_02962094) {
    piVar5 = (int *)(param_3 + param_5 * -4);
    iVar6 = -param_5;
    puVar2 = (undefined4 *)(param_2 + param_5 * -0xc + 8);
    iVar1 = DAT_029620a4;
    do {
      if ((*(short *)(iVar3 + 0x182 + iVar1) == param_1) &&
         ((param_6 == 0 || (*(short *)(iVar3 + 0x180 + iVar1) != 0)))) {
        if ((-1 < iVar6) && (iVar6 < param_4)) {
          if (param_2 != 0) {
            puVar2[-2] = *(undefined4 *)(iVar3 + 400 + iVar1);
            puVar2[-1] = *(undefined4 *)(iVar3 + 0x194 + DAT_029620a4);
            *puVar2 = *(undefined4 *)(iVar3 + 0x198 + DAT_029620a4);
            iVar1 = DAT_029620a4;
          }
          if (param_3 != 0) {
            *piVar5 = iVar4;
            iVar1 = DAT_029620a4;
          }
        }
        local_4 = local_4 + 1;
        puVar2 = puVar2 + 3;
        piVar5 = piVar5 + 1;
        iVar6 = iVar6 + 1;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x330;
    } while (iVar4 < DAT_02962094);
  }
  return local_4 - param_5;
}

