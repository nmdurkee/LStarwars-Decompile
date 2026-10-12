/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cc9a0; label: FUN_004cc9a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

