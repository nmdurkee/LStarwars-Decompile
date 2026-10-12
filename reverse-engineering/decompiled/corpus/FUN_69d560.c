/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69d560; label: FUN_0069d560
 */

undefined4 FUN_0069d560(int param_1,double param_2)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  float10 fVar4;
  undefined8 uVar5;
  double local_10;
  
  local_10 = 0.0;
  iVar2 = 0;
  if (*(int *)(param_1 + 0x58) < 2) {
    return 0xffffff7d;
  }
  if (*(int *)(param_1 + 4) == 0) {
    return 0xffffff76;
  }
  if (0.0 <= param_2) {
    bVar3 = *(int *)(param_1 + 0x34) == 0;
    if (0 < *(int *)(param_1 + 0x34)) {
      do {
        fVar4 = (float10)FUN_0069c720(param_1,iVar2);
        if ((float10)param_2 < fVar4 + (float10)local_10) break;
        local_10 = (double)(fVar4 + (float10)local_10);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 0x34));
      bVar3 = iVar2 == *(int *)(param_1 + 0x34);
    }
    if (!bVar3) {
      uVar5 = FUN_006e6bc6();
      uVar1 = FUN_0069d270(param_1,uVar5);
      return uVar1;
    }
  }
  return 0xffffff7d;
}

