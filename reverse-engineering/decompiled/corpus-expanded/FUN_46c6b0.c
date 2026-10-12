/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46c6b0; label: FUN_0046c6b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0046c6b0(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((byte)(&DAT_007f9028)[iVar1] == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  return 0;
}

