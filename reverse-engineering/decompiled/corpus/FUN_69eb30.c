/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69eb30; label: FUN_0069eb30
 */

int FUN_0069eb30(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  float10 fVar6;
  longlong lVar7;
  longlong local_8;
  
  if (*(int *)(param_1 + 0x58) < 2) {
    return -0x83;
  }
  iVar3 = *(int *)(param_1 + 0x34);
  while( true ) {
    if (iVar3 <= param_2) {
      return -0x83;
    }
    if (*(int *)(param_1 + 4) != 0) break;
    if (param_2 == 0) goto LAB_0069ebf6;
    param_2 = 0;
  }
  if (param_2 < 0) {
    local_8 = 0;
    if (0 < iVar3) {
      puVar5 = *(uint **)(param_1 + 0x3c);
      puVar2 = *(uint **)(param_1 + 0x38);
      do {
        uVar1 = puVar2[2];
        lVar7 = __allmul(uVar1 - *puVar5,(puVar2[3] - puVar5[1]) - (uint)(uVar1 < *puVar5),8,0);
        local_8 = lVar7 + local_8;
        puVar5 = puVar5 + 2;
        iVar3 = iVar3 + -1;
        puVar2 = puVar2 + 2;
      } while (iVar3 != 0);
    }
    fVar6 = (float10)FUN_0069c720(param_1,0xffffffff);
    FUN_006eafc0((double)((float)((float10)local_8 / fVar6) + 0.5));
    iVar3 = FUN_006e6b90();
    return iVar3;
  }
LAB_0069ebf6:
  if (*(int *)(param_1 + 4) != 0) {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x38) + 8 + param_2 * 8);
    puVar5 = (uint *)(*(int *)(param_1 + 0x3c) + param_2 * 8);
    local_8 = __allmul(uVar1 - *puVar5,
                       (*(int *)(*(int *)(param_1 + 0x38) + 0xc + param_2 * 8) -
                       *(int *)(*(int *)(param_1 + 0x3c) + 4 + param_2 * 8)) -
                       (uint)(uVar1 < *puVar5),8,0);
    fVar6 = (float10)FUN_0069c720(param_1,param_2);
    FUN_006eafc0((double)((float10)local_8 / fVar6 + (float10)0.5));
    iVar3 = FUN_006e6b90();
    return iVar3;
  }
  param_2 = param_2 * 0x20;
  iVar3 = *(int *)(*(int *)(param_1 + 0x48) + 0x10 + param_2);
  iVar4 = *(int *)(param_1 + 0x48) + param_2;
  if (iVar3 < 1) {
    iVar3 = *(int *)(iVar4 + 0xc);
    if (iVar3 < 1) {
      iVar3 = -1;
    }
    else if (0 < *(int *)(iVar4 + 0x14)) {
      return (*(int *)(param_2 + 0x14 + *(int *)(param_1 + 0x48)) +
             *(int *)(param_2 + 0xc + *(int *)(param_1 + 0x48))) / 2;
    }
  }
  return iVar3;
}

