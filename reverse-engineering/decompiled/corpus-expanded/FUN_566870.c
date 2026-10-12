/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566870; label: FUN_00566870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00566870(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_3 + 0x50c0)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f1ff0(*(int *)(param_3 + 0x50c8) + 0xf2 + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x50c8) + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x114;
    } while (iVar2 < *(int *)(param_3 + 0x50c0));
  }
  return;
}

