/* Ghidra pseudocode, not original source.
 * ev_4aa7baba24777c7cef62b6758f8d176321ddee5c4eaac4ea92e033f295beb802
 * Entry: 0x44f670; label: FUN_0044f670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0044f670(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
     (*piVar2 != 0)) {
    iVar3 = *piVar2;
    puVar1 = (uint *)(iVar3 + 0xef8);
    *puVar1 = *puVar1 | 8;
    if ((param_5 != 0) && (iVar5 = 0, 0 < param_5)) {
      do {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"FALSE");
        if (iVar4 == 0) {
          puVar1 = (uint *)(iVar3 + 0xef8);
          *puVar1 = *puVar1 & 0xfffffff7;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
    }
  }
  return 1;
}

