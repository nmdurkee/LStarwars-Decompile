/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x516120; label: FUN_00516120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00516120(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  
  if ((param_3 != 0) && (param_6 != 0)) {
    *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) | 0x100;
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar2 * 4),"false");
        if (iVar1 == 0) {
          *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffeff;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_5);
    }
    if ((*(uint *)(param_3 + 0x1e8) & 0x100) != 0) {
      *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) | 0x80;
    }
  }
  return 1;
}

