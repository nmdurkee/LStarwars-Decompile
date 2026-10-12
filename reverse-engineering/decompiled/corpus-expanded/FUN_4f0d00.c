/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f0d00; label: FUN_004f0d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f0d00(int param_1)

{
  int iVar1;
  
  iVar1 = (param_1 * 3 + -0x1800) * 0x10;
  if (*(int *)(&DAT_0297dc88 + iVar1) != 0) {
    return *(undefined4 *)(&DAT_0297dc7c + iVar1);
  }
  return *(undefined4 *)(&DAT_0297dc78 + iVar1);
}

