/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c9f30; label: FUN_005c9f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c9f30(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) != 0) {
      if ((param_2 != 0) && (iVar3 = 0, '\0' < *(char *)(param_1 + 0xc))) {
        do {
          if (*(int *)(*(int *)(param_1 + 8) + iVar3 * 4) != 0) {
            iVar1 = *(int *)(*(int *)(param_1 + 8) + iVar3 * 4);
            iVar2 = *(int *)(iVar1 + 4);
            if (iVar2 != 0) {
              FUN_004ef280(iVar2,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x502);
            }
            FUN_004ef280(iVar1,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x503);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(char *)(param_1 + 0xc));
      }
      FUN_004ef280(*(undefined4 *)(param_1 + 8),
                   "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x518);
    }
    if (*(int *)(param_1 + 4) != 0) {
      FUN_004ef280(*(int *)(param_1 + 4),"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",
                   0x51c);
    }
    FUN_004ef280(param_1,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x51e);
  }
  return;
}

