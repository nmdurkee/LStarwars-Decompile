/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54e820; label: FUN_0054e820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0054e820(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int in_ECX;
  float10 fVar4;
  
  iVar1 = *(int *)(in_ECX + 0x798);
  fVar2 = *(float *)(in_ECX + 0x194) - *(float *)(in_ECX + 0x1a0);
  fVar3 = *(float *)(iVar1 + 0x40) - (*(float *)(iVar1 + 0x28) + fVar2 + 0.1);
  if ((*(byte *)(iVar1 + 0x1e) & 4) == 0) {
    return (float10)fVar3;
  }
  fVar2 = *(float *)(iVar1 + 0x50) - (fVar2 * 0.5 + 0.1);
  fVar4 = (float10)fVar3;
  if ((float10)fVar2 < fVar4) {
    return (float10)fVar2;
  }
  return fVar4;
}

