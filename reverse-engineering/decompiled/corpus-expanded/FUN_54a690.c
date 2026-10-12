/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54a690; label: FUN_0054a690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0054a690(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if (param_1 == DAT_0093d7f0) {
    iVar2 = 0;
  }
  else {
    if (param_1 != DAT_0093d7f4) {
      return (float10)0;
    }
    iVar2 = 1;
  }
  fVar3 = (float10)0;
  if (((fVar3 != (float10)*(float *)(*(int *)(param_1 + 0xca4) + 0x28)) &&
      (fVar3 != (float10)(float)(&DAT_00926bc4)[iVar2])) &&
     (fVar3 != (float10)(float)(&DAT_00926bb8)[iVar2])) {
    iVar1 = FUN_00550040((&DAT_009253a8)[iVar2],*(undefined2 *)(*(int *)(param_1 + 0xca4) + 0x26));
    iVar2 = FUN_00550040((&DAT_00926bc0)[iVar2],(&DAT_009253a8)[iVar2]);
    if ((((-1 < iVar1) || (-1 < iVar2)) || ((iVar1 < -0x1fff || (iVar2 < -0x1fff)))) &&
       (((iVar1 < 1 || (iVar2 < 1)) || ((0x1fff < iVar1 || (0x1fff < iVar2)))))) {
      return (float10)0;
    }
    fVar3 = (float10)(((float)iVar1 * 1.5258789e-05) / _DAT_00925018);
  }
  return fVar3;
}

