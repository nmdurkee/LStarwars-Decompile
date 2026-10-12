/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f0ab0; label: FUN_004f0ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined8 FUN_004f0ab0(int param_1)

{
  int iVar1;
  
  iVar1 = (param_1 * 3 + -0x1800) * 0x10;
  return CONCAT44((*(int *)(&DAT_0297dc74 + iVar1) - *(int *)(&DAT_0297dc6c + iVar1)) -
                  (uint)(*(uint *)(&DAT_0297dc70 + iVar1) < *(uint *)(&DAT_0297dc68 + iVar1)),
                  *(uint *)(&DAT_0297dc70 + iVar1) - *(uint *)(&DAT_0297dc68 + iVar1));
}

