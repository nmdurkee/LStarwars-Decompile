/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46c690; label: FUN_0046c690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_0046c690(void)

{
  int iVar1;
  
  iVar1 = FUN_0054fa60();
  return (&DAT_007f9028)[(int)(iVar1 + (iVar1 >> 0x1f & 0x3fffU)) >> 0xe];
}

