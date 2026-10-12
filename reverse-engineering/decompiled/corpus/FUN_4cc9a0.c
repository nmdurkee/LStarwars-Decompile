/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cc9a0; label: FUN_004cc9a0
 */

undefined ** FUN_004cc9a0(int param_1,int param_2)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = 9;
  psVar1 = &DAT_007fd0a4;
  while (((param_2 != 0 && ((DAT_0087aa8c & 1 << ((byte)iVar2 & 0x1f)) == 0)) ||
         (*psVar1 != param_1))) {
    psVar1 = psVar1 + -0xc;
    iVar2 = iVar2 + -1;
    if ((int)psVar1 < 0x7fcfcc) {
      return (undefined **)0x0;
    }
  }
  return &PTR_s_batman_007fcfb8 + iVar2 * 6;
}

