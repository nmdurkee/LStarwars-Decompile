/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x5739f0; label: FUN_005739f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005739f0(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_2 + 300);
  if (((iVar4 != 0) && (iVar5 = *(int *)(iVar4 + 0x80), iVar5 != 0)) &&
     (iVar3 = 0, *(char *)(iVar4 + 0x7f) != '\0')) {
    do {
      iVar2 = 0;
      iVar4 = iVar5;
      if (*(short *)(iVar5 + 0x1e0) != 0) {
        do {
          if (((int)*(short *)(iVar4 + 0x2c) == *(int *)(param_2 + 0x11c)) &&
             (iVar1 = FUN_004f8b10(iVar4 + 0x14,param_1), iVar1 == 0)) {
            if (param_3 != (int *)0x0) {
              *param_3 = iVar4;
            }
            return iVar5;
          }
          iVar2 = iVar2 + 1;
          iVar4 = iVar4 + 0x30;
        } while (iVar2 < (int)(uint)*(ushort *)(iVar5 + 0x1e0));
      }
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x1e8;
    } while (iVar3 < (int)(uint)*(byte *)(*(int *)(param_2 + 300) + 0x7f));
  }
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  return 0;
}

