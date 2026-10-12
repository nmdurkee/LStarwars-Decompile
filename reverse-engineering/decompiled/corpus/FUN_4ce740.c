/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4ce740; label: FUN_004ce740
 */

void FUN_004ce740(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  float10 fVar6;
  
  iVar1 = param_1;
  if ((*(char *)(param_1 + 0x7b5) == '\x0f') && (*(char *)(param_1 + 0x7b3) == '\0')) {
    param_1._0_2_ = ~(ushort)(*(int *)(param_1 + 0x7bc) << 5) & 0x8000 | 0x4000;
    iVar5 = 0;
    do {
      iVar3 = FUN_005cfac0(*(int *)(iVar1 + 0x798) + 0x5c + iVar5 * 0xc);
      if (iVar3 != 0) {
        uVar4 = FUN_005cf9e0(*(int *)(iVar1 + 0x798) + 0x5c + iVar5 * 0xc,0);
        fVar6 = (float10)FUN_005b3c50(iVar1 + 0x80,uVar4);
        if (fVar6 < (float10)0.36) {
          uVar2 = (ushort)param_1;
          if (iVar5 != 0) {
            uVar2 = -(ushort)param_1;
          }
          *(ushort *)(*(int *)(iVar1 + 0x798) + 0x78 + iVar5 * 2) = uVar2;
          if (((uint)*(ushort *)(iVar1 + 0x7a4) & 1 << ((byte)iVar5 & 0x1f)) == 0) {
            *(ushort *)(iVar1 + 0x7a4) =
                 (ushort)(1 << ((byte)iVar5 & 0x1f)) | *(ushort *)(iVar1 + 0x7a4);
            FUN_00681f40("env_door_flap",iVar1 + 0x80);
          }
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
  }
  return;
}

