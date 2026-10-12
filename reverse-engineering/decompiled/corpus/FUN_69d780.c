/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69d780; label: FUN_0069d780
 */

float10 FUN_0069d780(int param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint *puVar6;
  int iVar7;
  float10 fVar8;
  longlong lVar9;
  uint local_18;
  int local_14;
  undefined8 local_10;
  
  fVar8 = (float10)0;
  iVar7 = 0;
  if (*(int *)(param_1 + 0x58) < 2) {
    return (float10)-131.0;
  }
  lVar3 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    lVar9 = FUN_0069c6b0(param_1,0xffffffff);
    fVar8 = (float10)FUN_0069c720(param_1,0xffffffff);
    iVar7 = *(int *)(param_1 + 0x34) + -1;
    lVar3 = lVar9;
    if (-1 < iVar7) {
      puVar6 = (uint *)(*(int *)(param_1 + 0x44) + 8 + iVar7 * 0x10);
      do {
        local_14 = (int)((ulonglong)lVar9 >> 0x20);
        local_18 = (uint)lVar9;
        local_10 = (double)fVar8;
        uVar2 = *puVar6;
        iVar1 = (local_14 - puVar6[1]) - (uint)(local_18 < uVar2);
        lVar5 = lVar9 - *(longlong *)puVar6;
        lVar4 = lVar9 - *(longlong *)puVar6;
        lVar3 = lVar9 - *(longlong *)puVar6;
        lVar9 = lVar9 - *(longlong *)puVar6;
        fVar8 = (float10)FUN_0069c720(param_1,iVar7);
        fVar8 = (float10)local_10 - fVar8;
        if ((iVar1 < *(int *)(param_1 + 0x54)) ||
           ((iVar1 <= *(int *)(param_1 + 0x54) &&
            (lVar3 = lVar4, local_18 - uVar2 <= *(uint *)(param_1 + 0x50))))) break;
        iVar7 = iVar7 + -1;
        puVar6 = puVar6 + -4;
        lVar3 = lVar5;
      } while (-1 < iVar7);
    }
  }
  local_10 = (double)CONCAT44((*(int *)(param_1 + 0x54) - (int)((ulonglong)lVar3 >> 0x20)) -
                              (uint)(*(uint *)(param_1 + 0x50) < (uint)lVar3),
                              *(uint *)(param_1 + 0x50) - (uint)lVar3);
  return (float10)(longlong)local_10 /
         (float10)*(int *)(*(int *)(param_1 + 0x48) + 8 + iVar7 * 0x20) + fVar8;
}

