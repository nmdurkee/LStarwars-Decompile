/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cde50; label: FUN_004cde50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cde50(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  iVar1 = DAT_00880608;
  *(ushort *)(DAT_00880608 + 0x4c) = *(ushort *)(DAT_00880608 + 0x4c) | 2;
  *(float *)(iVar1 + 0x48) = (float)fVar2 * (float)fVar2;
  return;
}

