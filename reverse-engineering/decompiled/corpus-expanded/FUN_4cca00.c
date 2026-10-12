/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cca00; label: FUN_004cca00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

