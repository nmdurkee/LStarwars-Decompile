/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x444630; label: FUN_00444630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00444630(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
      (*piVar2 != 0)) && (iVar3 = *piVar2, param_6 != 0)) {
    puVar1 = (uint *)(iVar3 + 0xef4);
    *puVar1 = *puVar1 | 1;
    iVar5 = 0;
    if (0 < param_5) {
      do {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"false");
        if (iVar4 == 0) {
          puVar1 = (uint *)(iVar3 + 0xef4);
          *puVar1 = *puVar1 & 0xfffffffe;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
    }
  }
  return 1;
}

