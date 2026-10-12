/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x5734a0; label: FUN_005734a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005734a0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != (int *)0x0) {
    iVar4 = *param_1;
    while (iVar4 != 0) {
      if (param_1[1] != 0) {
        iVar3 = 0;
        if (0 < DAT_00951360) {
          iVar5 = 0;
          do {
            iVar2 = FUN_004f8b10(iVar5 + 0x40 + DAT_00951354,iVar4);
            if (iVar2 == 0) {
              iVar4 = iVar3 * 0x9c + DAT_00951354;
              goto LAB_005734ef;
            }
            iVar3 = iVar3 + 1;
            iVar5 = iVar5 + 0x9c;
          } while (iVar3 < DAT_00951360);
        }
        iVar4 = 0;
LAB_005734ef:
        *(int *)param_1[1] = iVar4;
      }
      piVar1 = param_1 + 2;
      param_1 = param_1 + 2;
      iVar4 = *piVar1;
    }
  }
  return;
}

