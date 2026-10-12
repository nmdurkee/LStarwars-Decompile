/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x54a5a0; label: FUN_0054a5a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_0054a5a0(void)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 0;
  pbVar1 = &DAT_0092540a;
  do {
    if ((*pbVar1 & 1) == 0) {
      *(ushort *)(&DAT_0092540a + iVar2 * 0x60) = *(ushort *)(&DAT_0092540a + iVar2 * 0x60) | 1;
      return &DAT_009253b0 + iVar2 * 0x18;
    }
    pbVar1 = pbVar1 + 0x60;
    iVar2 = iVar2 + 1;
  } while ((int)pbVar1 < 0x926c0a);
  return (undefined4 *)0x0;
}

