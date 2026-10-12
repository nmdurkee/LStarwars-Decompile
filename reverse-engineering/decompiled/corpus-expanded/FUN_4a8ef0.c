/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a8ef0; label: FUN_004a8ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a8ef0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x50) + 0xc);
  if (*(int *)(iVar1 + 0xac) != 0) {
    *(undefined2 *)(in_ECX + 0x42) = 0x2b;
    return;
  }
  *(ushort *)(in_ECX + 0x42) = (ushort)(*(int *)(iVar1 + 0x14) != 0) * 4 + 1;
  return;
}

