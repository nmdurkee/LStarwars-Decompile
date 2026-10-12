/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b04b0; label: FUN_005b04b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b04b0(int *param_1,int param_2)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  
  pfVar2 = (float *)*param_1;
  if ((*(byte *)((int)pfVar2 + 10) & 2) == 0) {
    fVar1 = pfVar2[1];
  }
  else {
    iVar3 = FUN_0054fa60();
    fVar1 = (float)iVar3 * 1.5259022e-05 * pfVar2[1];
  }
  *pfVar2 = fVar1;
  if (param_2 != 0) {
    *(byte *)((int)pfVar2 + 10) = *(byte *)((int)pfVar2 + 10) | 1;
    return;
  }
  *(byte *)((int)pfVar2 + 10) = *(byte *)((int)pfVar2 + 10) & 0xfe;
  return;
}

