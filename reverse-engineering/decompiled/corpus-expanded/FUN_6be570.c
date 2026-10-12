/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6be570; label: FUN_006be570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006be570(void)

{
  uint uVar1;
  int in_ECX;
  int unaff_ESI;
  
  if ((*(uint *)(unaff_ESI + 0x1c) & 0x400000) == 0) {
    uVar1 = *(uint *)(in_ECX + 4) & 0x10000000;
  }
  else {
    uVar1 = *(uint *)(in_ECX + 4) & 0x400000;
  }
  return uVar1 == 0;
}

