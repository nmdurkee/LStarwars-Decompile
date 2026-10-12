/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x516320; label: FUN_00516320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00516320(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) && (param_6 != 0)) {
    puVar1 = (uint *)(*(int *)(param_3 + 0xd0) + 0x1fc);
    *puVar1 = *puVar1 | 8;
    iVar3 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"false");
        if (iVar2 == 0) {
          puVar1 = (uint *)(*(int *)(param_3 + 0xd0) + 0x1fc);
          *puVar1 = *puVar1 & 0xfffffff7;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
  }
  return 1;
}

