/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e7820; label: FUN_005e7820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e7820(void)

{
  char *in_ECX;
  
  if ((*in_ECX != '\0') && (in_ECX[1] != '\0')) {
    *(undefined1 *)(*(int *)(in_ECX + 0x154) + 0x10) = 0;
  }
  return;
}

