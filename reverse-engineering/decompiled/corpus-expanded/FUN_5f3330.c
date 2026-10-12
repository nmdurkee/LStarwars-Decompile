/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f3330; label: FUN_005f3330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f3330(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      FUN_005e95b0(*(undefined4 *)(*(int *)(param_1 + 0xc) + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 4) != 0) {
    FUN_004ef280(*(int *)(param_1 + 4),"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x49e
                );
  }
  FUN_004ef280(param_1,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x4a0);
  return;
}

