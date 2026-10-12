/* Ghidra pseudocode, not original source.
 * ev_d0ee5b940732101f19a6f5ed1cc5d22784960ef3dbbb4fefd6b0cd8a13c6d459
 * Entry: 0x740e90; label: FUN_00740e90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00740e90(void)

{
  char *in_ECX;
  
  if ((*in_ECX != '\0') && (*(int *)(in_ECX + 0xc) != 0)) {
    FUN_006e85b0(*(int *)(in_ECX + 0xc));
  }
  return;
}

