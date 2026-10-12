/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d9610; label: FUN_006d9610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d9610(void)

{
  int iVar1;
  
  iVar1 = DAT_02975144;
  FUN_006d8760();
  FUN_006d4c10();
  *(undefined4 *)(iVar1 + 0x4e04) = 0;
  *(undefined1 *)(iVar1 + 0x4e10) = 0;
  *(undefined1 *)(iVar1 + 0x4e11) = 0;
  *(undefined1 *)(iVar1 + 0x6574) = 0;
  return;
}

