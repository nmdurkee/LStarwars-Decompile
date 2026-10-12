/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61bb10; label: FUN_0061bb10
 */

uint FUN_0061bb10(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (int)(param_5 + (param_5 >> 0x1f & 3U)) >> 2;
  *(undefined4 *)(param_2 + 0x1c) = param_3;
  *(int *)(param_2 + 0x20) = param_4;
  FUN_00618920(param_3,param_4,param_5,uVar4,0,0x3f800000);
  if (DAT_02912eb8 == 0) {
    iVar1 = (uVar4 & 0xfffffffe) + param_4 * 2;
    iVar2 = iVar1 * 4 + -8;
    iVar3 = FUN_006e6b90();
    FUN_005db5b0(iVar3 << 4,param_4 * 8,iVar3 << 4,iVar2,0x80ffffff,DAT_02900c70);
    if (DAT_02912eb8 == 0) {
      iVar3 = FUN_006e6b90();
      FUN_005db5b0(iVar3 << 4,param_4 * 8,iVar3 << 4,iVar2,0x80ffffff,DAT_02900c70);
      if (DAT_02912eb8 == 0) {
        iVar3 = FUN_006e6b90();
        FUN_005db5b0(iVar3 << 4,param_4 * 8,iVar3 << 4,iVar2,0x80ffffff,DAT_02900c70);
        if (DAT_02912eb8 == 0) {
          iVar2 = (param_4 + uVar4) * 8 + -8;
          iVar3 = FUN_006e6b90();
          iVar1 = iVar1 * 4;
          FUN_005db5b0(iVar3 << 4,iVar1,iVar3 << 4,iVar2,0x80000000,DAT_02900c70);
          if (DAT_02912eb8 == 0) {
            iVar3 = FUN_006e6b90();
            FUN_005db5b0(iVar3 << 4,iVar1,iVar3 << 4,iVar2,0x80000000,DAT_02900c70);
            if (DAT_02912eb8 == 0) {
              iVar3 = FUN_006e6b90();
              FUN_005db5b0(iVar3 << 4,iVar1,iVar3 << 4,iVar2,0x80000000,DAT_02900c70);
            }
          }
        }
      }
    }
  }
  return uVar4;
}

