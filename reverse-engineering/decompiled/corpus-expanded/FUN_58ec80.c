/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x58ec80; label: FUN_0058ec80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0058ec80(int param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = *(int **)(param_1 + 0x46a8);
  if (piVar2 != (int *)0x0) {
    iVar3 = *piVar2;
    iVar4 = 0;
    if (*(ushort *)(piVar2 + 1) != 0) {
      do {
        uVar1 = *(ushort *)(iVar3 + 0x7a);
        if (((((uVar1 & 2) != 0) && ((uVar1 & 4) != 0)) && (*(char *)(iVar3 + 0x6e) == '\0')) &&
           ((uVar1 & 1) != 0)) {
          return iVar3;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x7c;
      } while (iVar4 < (int)(uint)*(ushort *)(piVar2 + 1));
    }
  }
  return 0;
}

