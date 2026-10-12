/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x573430; label: FUN_00573430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00573430(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < DAT_00951360) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f8b10(iVar3 + 0x40 + DAT_00951354,param_1);
      if (iVar1 == 0) {
        if (param_2 != (int *)0x0) {
          *param_2 = iVar2;
        }
        return iVar2 * 0x9c + DAT_00951354;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x9c;
    } while (iVar2 < DAT_00951360);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = -1;
  }
  return 0;
}

