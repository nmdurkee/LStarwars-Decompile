/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x594b70; label: FUN_00594b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00594b70(int *param_1,uint param_2,uint param_3,int param_4,int *param_5,int *param_6)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_4;
  
  local_4 = 0;
  if (param_5 != (int *)0x0) {
    *param_5 = -1;
  }
  if (param_6 != (int *)0x0) {
    *param_6 = -1;
  }
  iVar5 = 0;
  iVar6 = 0;
  if (*(short *)((int)param_1 + 6) != 0) {
    iVar4 = 0;
    do {
      sVar1 = *(short *)(*param_1 + iVar4);
      iVar6 = (int)sVar1;
      if (((*(uint *)(iVar6 * 0x4c + 4 + DAT_0093b274) & param_2) == param_3) &&
         (iVar2 = FUN_00594960(iVar6), iVar2 != 0)) {
        if (param_4 != 0) {
          *(short *)(param_4 + local_4 * 2) = sVar1;
        }
        local_4 = local_4 + 1;
        if ((param_5 != (int *)0x0) &&
           ((piVar3 = param_5, *param_5 == -1 ||
            ((param_6 != (int *)0x0 && (piVar3 = param_6, *param_6 == -1)))))) {
          *piVar3 = iVar6;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x1c;
      iVar6 = local_4;
    } while (iVar5 < (int)(uint)*(ushort *)((int)param_1 + 6));
  }
  if (param_4 != 0) {
    *(undefined2 *)(param_4 + iVar6 * 2) = 0xffff;
  }
  return iVar6;
}

