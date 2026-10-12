/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a7840; label: FUN_004a7840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a7840(void)

{
  int in_ECX;
  
  if ((0.0 < *(float *)(*(int *)(in_ECX + 0xca4) + 0x28)) &&
     (*(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + 0x394) != 0)) {
    *(undefined2 *)(in_ECX + 0x7aa) = 0xe5;
    return;
  }
  *(undefined2 *)(in_ECX + 0x7aa) = 0x8e;
  return;
}

