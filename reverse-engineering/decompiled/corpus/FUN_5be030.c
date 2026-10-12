/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5be030; label: FUN_005be030
 */

short FUN_005be030(float param_1,float param_2)

{
  int iVar1;
  
  if (param_2 < param_1) {
    iVar1 = FUN_006e6b90();
    return 0x4000 - *(short *)(&DAT_008066c8 + iVar1 * 2);
  }
  iVar1 = FUN_006e6b90();
  return *(short *)(&DAT_008066c8 + iVar1 * 2);
}

