/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e95b0; label: FUN_005e95b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e95b0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[4];
  iVar2 = 0;
  if (0 < *param_1) {
    do {
      if (*(int *)(param_1[2] + iVar2 * 4) != 0) {
        FUN_005c9f30(*(undefined4 *)(param_1[2] + iVar2 * 4),iVar1 == 0);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *param_1);
  }
  if (param_1[3] != 0) {
    FUN_004ef280(param_1[3],"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x4dc);
  }
  if (param_1[4] != 0) {
    FUN_004ef280(param_1[4],"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x4de);
  }
  if (param_1[2] != 0) {
    FUN_004ef280(param_1[2],"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x4e1);
  }
  FUN_004ef280(param_1,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x4e3);
  return;
}

