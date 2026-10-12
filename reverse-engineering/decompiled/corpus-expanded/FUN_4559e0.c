/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x4559e0; label: FUN_004559e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_004559e0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar4 = 0;
  local_4 = 1;
  if (param_6 != 0) {
    if (param_3 != 0) {
      iVar4 = **(int **)(param_3 + 0xd0);
    }
    iVar1 = 1;
    if ((param_5 != 0) && (iVar3 = 0, 0 < param_5)) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"character");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"FALSE");
          if (iVar1 == 0) {
            local_4 = 0;
          }
        }
        else {
          iVar4 = FUN_004f8b10(iVar1 + 10,"myself");
          if ((iVar4 == 0) && (param_3 != 0)) {
            iVar4 = **(int **)(param_3 + 0xd0);
          }
          else if ((DAT_00923904 == (code *)0x0) ||
                  (piVar2 = (int *)(*DAT_00923904)(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),
                                                   iVar1 + 10), piVar2 == (int *)0x0)) {
            iVar4 = 0;
          }
          else {
            iVar4 = *piVar2;
          }
        }
        iVar3 = iVar3 + 1;
        iVar1 = local_4;
      } while (iVar3 < param_5);
    }
    if (iVar4 != 0) {
      *(uint *)(iVar4 + 0xef4) =
           *(uint *)(iVar4 + 0xef4) ^ (iVar1 << 0xd ^ *(uint *)(iVar4 + 0xef4)) & 0x2000;
    }
  }
  return 1;
}

