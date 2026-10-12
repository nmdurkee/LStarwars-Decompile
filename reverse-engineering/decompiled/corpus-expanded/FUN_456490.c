/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x456490; label: FUN_00456490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00456490(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
      (*piVar2 != 0)) && (iVar3 = *piVar2, param_6 != 0)) {
    puVar1 = (uint *)(iVar3 + 0xef4);
    *puVar1 = *puVar1 | 0x40000;
    iVar5 = 0;
    if (0 < param_5) {
      do {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"FALSE");
        if (iVar4 == 0) {
          puVar1 = (uint *)(iVar3 + 0xef4);
          *puVar1 = *puVar1 & 0xfffbffff;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
    }
  }
  return 1;
}

