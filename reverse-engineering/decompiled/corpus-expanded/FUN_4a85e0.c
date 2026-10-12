/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a85e0; label: FUN_004a85e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a85e0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  bool bVar3;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x50) + 0xc);
  bVar3 = piVar1[3] == 0;
  if (*piVar1 == 0) {
    if (!bVar3) {
      *(undefined2 *)(in_ECX + 0x42) = 3;
      return;
    }
  }
  else {
    if ((bVar3) ||
       (iVar2 = *(int *)(*(int *)(in_ECX + 0x54) + 0x24),
       *(float *)(*(int *)(in_ECX + 0xca4) + 0x28) <=
       (*(float *)(iVar2 + 0x1c) + *(float *)(iVar2 + 0x18)) * 0.5)) {
      *(undefined2 *)(in_ECX + 0x42) = 0;
      return;
    }
    *(undefined2 *)(in_ECX + 0x42) = 3;
  }
  return;
}

