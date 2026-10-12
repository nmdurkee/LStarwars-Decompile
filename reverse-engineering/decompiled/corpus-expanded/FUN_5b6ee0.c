/* Ghidra pseudocode, not original source.
 * ev_5f8bd7f02bbfa9819b1ea6d4f28ed7de24e0304b6779d959c9b1888bbc6517da
 * Entry: 0x5b6ee0; label: FUN_005b6ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b6ee0(int param_1,float param_2,float param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)(&DAT_029899a0)[param_1 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[param_1 + 0x4000 >> 1 & 0x7fff];
  *param_4 = param_2 * fVar2 - param_3 * fVar1;
  *param_5 = fVar2 * param_3 + fVar1 * param_2;
  return;
}

