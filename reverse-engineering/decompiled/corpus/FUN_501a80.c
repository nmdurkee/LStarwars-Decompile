/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x501a80; label: FUN_00501a80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00501a80(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  ushort uVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  float local_60;
  undefined4 local_5c;
  undefined1 local_58 [24];
  undefined1 local_40 [48];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar2 = *(ushort *)(*(int *)(in_ECX + 4) + 6 + (uint)*(byte *)(in_EAX + 0x59) * 0xc);
  if ((uVar2 == 0xffff) || (uVar5 = (uint)uVar2, *(int *)(DAT_0296209c + uVar5 * 4) == 0)) {
    return;
  }
  if (*(int *)(in_EAX + 0x50) != 0) {
    FUN_005c9c40(*(int *)(in_EAX + 0x50),param_2,local_58);
  }
  iVar3 = FUN_005010f0();
  if (iVar3 != 0) {
    if ((local_60 < 0.0) && ((*(byte *)(in_EAX + 0x58) & 0x10) == 0)) {
      local_60 = (float)(int)*(short *)(*(int *)(DAT_0296209c + uVar5 * 4) + 0x16) *
                 (0.0 - local_60);
    }
    if (0.1 < local_60) {
      if (((*(byte *)(in_EAX + 0x58) & 0x10) != 0) && (param_1[1] != 0)) {
        return;
      }
      FUN_00500e50();
      if ((*(byte *)(in_EAX + 0x58) & 4) != 0) {
        FUN_005b4960(local_40,in_EAX + 0x40);
      }
      if (param_3 != 0) {
        FUN_005b5430(local_40,local_40,param_3);
      }
      if ((*(byte *)(in_EAX + 0x58) & 0x10) == 0) {
        if ((*(byte *)(in_EAX + 0x58) & 0x20) == 0) {
          uVar4 = FUN_006e6b90(_DAT_008108e4,local_40,0,local_5c);
          FUN_00684d80(uVar5,&local_10,uVar4);
          return;
        }
        piVar1 = param_1 + 1;
        if (param_1[1] == -1) {
          FUN_00684ee0(piVar1,uVar5,local_10,local_c,local_8);
          FUN_00685340(*piVar1,0);
        }
        iVar3 = *piVar1;
        if (-1 < iVar3) {
          if (DAT_009213d0 == 1) {
            FUN_00655940(iVar3,local_10,local_c,local_8);
          }
          else if (DAT_009213d0 == 2) {
            FUN_00655ad0(iVar3,local_40);
          }
          else {
            FUN_00655a40(iVar3,local_40);
          }
        }
        if (DAT_009213cc <= 0.0) {
          return;
        }
        FUN_005dd230(local_40,DAT_009213cc,0);
        return;
      }
      local_60 = -NAN;
      FUN_00690490(&local_60,uVar5,&local_10,0,0,1,local_5c);
      FUN_00655b30(local_60,local_40);
      param_1[1] = 1;
      return;
    }
  }
  if ((*(byte *)(in_EAX + 0x58) & 0x20) == 0) {
    param_1[1] = 0;
  }
  else if (-1 < (int)param_1[1]) {
    FUN_00684400(param_1 + 1);
    *param_1 = 0;
    return;
  }
  *param_1 = 0;
  return;
}

