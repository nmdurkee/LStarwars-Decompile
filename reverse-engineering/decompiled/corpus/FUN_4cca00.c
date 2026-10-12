/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cca00; label: FUN_004cca00
 */

undefined ** FUN_004cca00(int param_1)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = 0;
  psVar1 = &DAT_007fcfcc;
  do {
    if (*psVar1 == param_1) {
      return &PTR_s_batman_007fcfb8 + iVar2 * 6;
    }
    psVar1 = psVar1 + 0xc;
    iVar2 = iVar2 + 1;
  } while ((int)psVar1 < 0x7fd0bc);
  return (undefined **)0x0;
}

