/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52a2f0; label: FUN_0052a2f0
 */

void FUN_0052a2f0(int param_1)

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
  
  for (iVar5 = FUN_004f1440(DAT_009238e4 + 0x371a4); iVar5 != 0;
      iVar5 = FUN_004f1460(DAT_009238e4 + 0x371a4,iVar5)) {
    if ((*(int *)(iVar5 + 0x40) == param_1) || (*(int *)(iVar5 + 0x44) == param_1)) {
      FUN_005b3800(local_18,*(int *)(iVar5 + 0x44) + 0x18,*(int *)(iVar5 + 0x40) + 0x18);
      FUN_005b3b30(local_24,local_18);
      if (*(float *)(iVar5 + 0x48) <= 1.0) {
        if (0.0 <= *(float *)(iVar5 + 0x48)) {
          fVar2 = *(float *)(*(int *)(iVar5 + 0x44) + 0x24) * *(float *)(iVar5 + 0x48) +
                  (1.0 - *(float *)(iVar5 + 0x48)) * *(float *)(*(int *)(iVar5 + 0x40) + 0x24);
        }
        else {
          fVar2 = *(float *)(*(int *)(iVar5 + 0x40) + 0x24);
        }
      }
      else {
        fVar2 = *(float *)(*(int *)(iVar5 + 0x44) + 0x24);
      }
      puVar1 = (undefined4 *)(iVar5 + 0x28);
      fVar4 = fVar2 * local_1c;
      local_1c = -local_24[0] * fVar2;
      iVar3 = *(int *)(iVar5 + 0x40);
      fVar2 = *(float *)(iVar5 + 0x2c);
      *puVar1 = *(undefined4 *)(iVar3 + 0x18);
      *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(iVar3 + 0x1c);
      *(undefined4 *)(iVar5 + 0x30) = *(undefined4 *)(iVar3 + 0x20);
      local_24[0] = fVar4;
      FUN_005b3830(local_c,local_18,*(undefined4 *)(iVar5 + 0x48));
      FUN_005b37d0(puVar1,puVar1,local_c);
      FUN_005b3830(local_c,local_24,*(undefined4 *)(iVar5 + 0x4c));
      FUN_005b37d0(puVar1,puVar1,local_c);
      if (1.5 < ABS(fVar2 - *(float *)(iVar5 + 0x2c))) {
        *(float *)(iVar5 + 0x2c) = fVar2;
      }
      FUN_005bfe00(local_18[0],local_10);
      uVar6 = FUN_006e6b90();
      uVar6 = FUN_005be590(uVar6,*(undefined4 *)(iVar5 + 0x50));
      *(undefined4 *)(iVar5 + 0x34) = uVar6;
    }
  }
  return;
}

