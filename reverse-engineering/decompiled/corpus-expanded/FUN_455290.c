/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x455290; label: FUN_00455290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00455290(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  
  bVar3 = false;
  if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
    iVar2 = **(int **)(param_3 + 0xd0);
    if ((param_6 != 0) && (iVar5 = 0, 0 < param_5)) {
      do {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757ebc);
        if (iVar4 == 0) {
          bVar3 = true;
        }
        else {
          iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"FALSE");
          if (iVar4 == 0) {
            bVar3 = false;
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
    }
    puVar1 = (uint *)(iVar2 + 0xef4);
    *puVar1 = *puVar1 ^ ((uint)!bVar3 << 5 ^ *(uint *)(iVar2 + 0xef4)) & 0x20;
  }
  return 1;
}

