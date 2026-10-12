/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x48c3f0; label: FUN_0048c3f0
 */

/* WARNING: Removing unreachable block (ram,0x0048c4d5) */

void FUN_0048c3f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 local_c [12];
  
  if ((((param_1 != 0) && (param_2 != 0)) && (iVar1 = FUN_005cfed0(param_1), iVar1 != 0)) &&
     (iVar6 = 0, 0 < iVar1)) {
    do {
      if (iVar6 == 0) {
        FUN_005cfef0(param_1,local_c,1);
      }
      else {
        FUN_005cff50(local_c);
      }
      FUN_005cfc00(local_c,*(uint *)(param_2 + iVar6 * 8) >> 0xb & 1);
      iVar2 = FUN_005cfa20(local_c);
      FUN_005ea570(local_c,iVar2);
      FUN_005ea660(local_c);
      if (((*(int *)(param_1 + 0x54) != 0) &&
          (puVar3 = (undefined4 *)FUN_005d0420(local_c), puVar3 != (undefined4 *)0x0)) &&
         (iVar5 = *(int *)(*(int *)(param_1 + 0x54) + (uint)*(ushort *)(puVar3 + 0x17) * 4),
         iVar5 != 0)) {
        puVar3[0x13] = (float)(*(uint *)(param_2 + iVar6 * 8) & 0x7ff);
        puVar3[0x14] = puVar3[0x14] ^ (*(uint *)(param_2 + iVar6 * 8) >> 0xc ^ puVar3[0x14]) & 1;
        uVar4 = (*(uint *)(param_2 + iVar6 * 8) >> 0xb ^ puVar3[0x14]) & 4 ^ puVar3[0x14];
        puVar3[0x14] = uVar4;
        puVar3[0x14] = (*(uint *)(param_2 + iVar6 * 8) >> 0xb ^ uVar4) & 8 ^ uVar4;
        puVar3[0x10] = *(undefined4 *)(param_2 + 4 + iVar6 * 8);
        puVar3[0x16] = puVar3[0x13];
        FUN_005f3390(iVar5,0,puVar3[0x13],puVar3);
        puVar7 = puVar3;
        puVar8 = (undefined4 *)
                 ((((int)puVar3 - *(int *)(param_1 + 0x4c)) / 0x60) * 0x40 +
                 *(int *)(param_1 + 0x50));
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        puVar3[0xc] = *(float *)(iVar2 + 0x30) + (float)puVar3[0xc];
        puVar3[0xd] = *(float *)(iVar2 + 0x34) + (float)puVar3[0xd];
        puVar3[0xe] = *(float *)(iVar2 + 0x38) + (float)puVar3[0xe];
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar1);
  }
  return;
}

