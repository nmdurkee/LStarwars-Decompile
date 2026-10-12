/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x58e980; label: FUN_0058e980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0058e980(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_1 + 0x46a8);
  if (piVar1 != (int *)0x0) {
    iVar4 = *piVar1;
    iVar3 = 0;
    if ((short)piVar1[1] != 0) {
      do {
        iVar2 = FUN_004f8b10(iVar4,param_2);
        if (iVar2 == 0) {
          return iVar4;
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x7c;
      } while (iVar3 < (int)(uint)*(ushort *)(*(int *)(param_1 + 0x46a8) + 4));
    }
  }
  return 0;
}

