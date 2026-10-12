/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5ca500; label: FUN_005ca500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005ca500(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x54) + (uint)*(ushort *)(param_2 + 0x5c) * 4);
    if (iVar1 != 0) {
      fVar3 = (float10)FUN_005ca4b0(iVar1);
      return fVar3;
    }
    uVar2 = *(uint *)(param_2 + 0x50) >> 0x16;
    if ((uVar2 != 0) && (*(int *)(param_1 + 0x1e0) != 0)) {
      return (float10)*(ushort *)(*(int *)(param_1 + 0x1e0) + -10 + uVar2 * 0xc);
    }
  }
  return (float10)0;
}

