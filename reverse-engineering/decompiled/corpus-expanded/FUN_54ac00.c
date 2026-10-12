/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54ac00; label: FUN_0054ac00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054ac00(int param_1,float param_2,float param_3)

{
  int iVar1;
  float10 fVar2;
  float10 extraout_ST0;
  float10 fVar3;
  
  fVar2 = (float10)FUN_005b7d30(_DAT_0092505c + param_3,0x3fa00000);
  fVar3 = (float10)0;
  if (1.0 <= (float)fVar2) {
    param_3 = (float)fVar3;
  }
  else {
    iVar1 = FUN_006e6b90();
    param_3 = 1.0 - ABS((float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff]);
    fVar3 = extraout_ST0;
  }
  if (param_1 == 0) {
    FUN_0054a910(param_3 * param_2,(float)fVar3,0,0);
  }
  else if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
    FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),param_3 * param_2,0);
    return;
  }
  return;
}

