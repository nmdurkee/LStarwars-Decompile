/* Ghidra pseudocode, not original source.
 * ev_8db479debe006dcb1d0ae53ec943fbf75b60233db5d397d4c7fbd4646b77bfb6
 * Entry: 0x516bf0; label: FUN_00516bf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00516bf0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  if (((param_3 != 0) && (param_6 != 0)) && (*(int *)(param_3 + 0xd0) != 0)) {
    puVar1 = (uint *)(*(int *)(param_3 + 0xd0) + 0x1f8);
    *puVar1 = *puVar1 | 0x2000;
    iVar3 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"false");
        if (iVar2 == 0) {
          puVar1 = (uint *)(*(int *)(param_3 + 0xd0) + 0x1f8);
          *puVar1 = *puVar1 & 0xffffdfff;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
  }
  return 1;
}

