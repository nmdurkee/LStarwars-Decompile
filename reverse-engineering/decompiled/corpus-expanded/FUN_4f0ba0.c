/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f0ba0; label: FUN_004f0ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f0ba0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 * 3 + -0x1800;
  iVar2 = iVar1 * 0x10;
  if (-1 < *(int *)(&DAT_0297dc80 + iVar2)) {
    *(undefined4 *)(*(int *)(&DAT_0297dc80 + iVar2) * 0x10 + 0x34 + *(int *)(&DAT_0297dc60 + iVar2))
         = 0xffffffff;
  }
  (&DAT_0297dc84)[iVar1 * 4] = 0;
  return;
}

