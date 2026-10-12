/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44caf0; label: FUN_0044caf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044caf0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
      (*piVar2 != 0)) && (iVar3 = *piVar2, param_6 != 0)) {
    puVar1 = (uint *)(iVar3 + 0xef0);
    *puVar1 = *puVar1 | 0x10000000;
    iVar5 = 0;
    if (0 < param_5) {
      do {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"FALSE");
        if (iVar4 == 0) {
          puVar1 = (uint *)(iVar3 + 0xef0);
          *puVar1 = *puVar1 & 0xefffffff;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
    }
  }
  return 1;
}

