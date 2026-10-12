/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d3590; label: FUN_005d3590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d3590(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0xe8) & 1) != 0)) {
    FUN_004ef280(iVar1,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutexanm.c",0x208);
  }
  if (*(char *)(param_1 + 0xe) != '\0') {
    FUN_004ef280(param_1,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutexanm.c",0x69a);
  }
  return;
}

