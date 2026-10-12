/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4f9d80; label: FUN_004f9d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f9d80(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0x34);
  iVar2 = 8;
  do {
    if (piVar1[-1] != 0) {
      FUN_004f99e0(piVar1[-1]);
    }
    if (-1 < *piVar1) {
      (&DAT_0297dc84)[*piVar1 * 0xc] = 0;
    }
    piVar1 = piVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*(short *)(param_1 + 0xb0) != 0) {
    FUN_004ef280(param_1,"d:\\projects\\legosagapc\\nu2api.saga\\nucore\\nufile.c",0xd22);
  }
  return;
}

