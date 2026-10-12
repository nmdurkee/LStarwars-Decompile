/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x522100; label: FUN_00522100
 */

void FUN_00522100(int param_1)

{
  undefined4 *puVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  float local_24 [2];
  float local_1c;
  undefined4 local_18 [2];
  undefined4 local_10;
  undefined1 local_c [12];
  
  for (iVar5 = FUN_004f1440(DAT_009238e4 + 0x3cbd8); iVar5 != 0;
      iVar5 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar5)) {
    if ((*(int *)(iVar5 + 0x30) == param_1) || (*(int *)(iVar5 + 0x34) == param_1)) {
      FUN_005b3800(local_18,*(int *)(iVar5 + 0x34) + 0x18,*(int *)(iVar5 + 0x30) + 0x18);
      FUN_005b3b30(local_24,local_18);
      if (*(float *)(iVar5 + 0x38) <= 1.0) {
        if (0.0 <= *(float *)(iVar5 + 0x38)) {
          fVar2 = *(float *)(*(int *)(iVar5 + 0x34) + 0x24) * *(float *)(iVar5 + 0x38) +
                  (1.0 - *(float *)(iVar5 + 0x38)) * *(float *)(*(int *)(iVar5 + 0x30) + 0x24);
        }
        else {
          fVar2 = *(float *)(*(int *)(iVar5 + 0x30) + 0x24);
        }
      }
      else {
        fVar2 = *(float *)(*(int *)(iVar5 + 0x34) + 0x24);
      }
      puVar1 = (undefined4 *)(iVar5 + 0x18);
      fVar4 = fVar2 * local_1c;
      local_1c = -local_24[0] * fVar2;
      iVar3 = *(int *)(iVar5 + 0x30);
      *puVar1 = *(undefined4 *)(iVar3 + 0x18);
      *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
      *(undefined4 *)(iVar5 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
      local_24[0] = fVar4;
      FUN_005b3830(local_c,local_18,*(undefined4 *)(iVar5 + 0x38));
      FUN_005b37d0(puVar1,puVar1,local_c);
      FUN_005b3830(local_c,local_24,*(undefined4 *)(iVar5 + 0x3c));
      FUN_005b37d0(puVar1,puVar1,local_c);
      FUN_005bfe00(local_18[0],local_10);
      uVar6 = FUN_006e6b90();
      uVar6 = FUN_005be590(uVar6,*(undefined4 *)(iVar5 + 0x40));
      *(undefined4 *)(iVar5 + 0x24) = uVar6;
    }
  }
  return;
}

