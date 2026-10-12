/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x4553f0; label: FUN_004553f0
 */

void FUN_004553f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  float10 fVar8;
  undefined1 *local_bc;
  int local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  int local_a0;
  int local_9c;
  undefined4 local_98;
  float afStack_94 [4];
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_bc;
  iVar7 = 0;
  local_b4 = param_1;
  local_a4 = param_2;
  local_bc = (undefined1 *)0x0;
  local_9c = 0;
  local_a0 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_b8 = 0;
  if ((param_6 == 0) || (param_5 < 1)) {
    __security_check_cookie(local_4 ^ (uint)&local_bc);
    return;
  }
  puVar6 = local_84;
  do {
    iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"script=");
    if (iVar2 == 0) {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"name=");
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"area=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"locator_set=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"locator=");
            if (iVar2 == 0) {
              iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),&DAT_00757700);
              if (iVar2 == 0) {
                iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"spline=");
                if (iVar2 == 0) {
                  iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"param");
                  if ((iVar2 != 0) && (local_b8 < 4)) {
                    FUN_004f1f40(puVar6,iVar2 + 6,0x20);
                    puVar4 = (undefined1 *)FUN_004f8a70(puVar6,&DAT_00758460);
                    if (puVar4 != (undefined1 *)0x0) {
                      fVar8 = (float10)FUN_005147c0(local_a4,puVar4 + 1);
                      afStack_94[local_b8] = (float)fVar8;
                      local_b8 = local_b8 + 1;
                      *puVar4 = 0;
                      puVar6 = puVar6 + 0x20;
                    }
                  }
                }
                else {
                  local_a8 = FUN_005d0690(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),iVar2 + 7);
                }
              }
              else {
                FUN_005147c0(local_a4,iVar2 + 4);
                local_bc = (undefined1 *)FUN_006e6b90();
                if (((int)local_bc < 0) || (0x10 < (int)local_bc)) {
                  local_bc = (undefined1 *)0x0;
                }
              }
            }
            else {
              local_98 = FUN_0051ac10(local_b4,iVar2 + 8);
            }
          }
          else {
            local_b0 = FUN_0051ac70(local_b4,iVar2 + 0xc);
          }
        }
        else {
          local_ac = FUN_0051acd0(local_b4,iVar2 + 5);
        }
      }
      else {
        local_a0 = iVar2 + 5;
      }
    }
    else {
      iVar3 = FUN_00513010(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar2 + 7,0,1,1);
      if (iVar3 != 0) {
        local_9c = iVar2 + 7;
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < param_5);
  if ((local_9c != 0) && (*(int *)(PTR_DAT_00802c54 + 0x2aec) < 0x20)) {
    puVar1 = PTR_DAT_00802c54 + *(int *)(PTR_DAT_00802c54 + 0x2aec) * 0xdc + 0x2b00;
    FUN_00514640(local_b4,0,puVar1,0,local_9c,0,0,0,0);
    *(undefined4 *)(puVar1 + 0xa8) = local_b0;
    puVar1[0xb0] = local_bc._0_1_;
    *(undefined4 *)(puVar1 + 0xa4) = local_98;
    *(undefined4 *)(puVar1 + 0xa0) = local_ac;
    *(undefined4 *)(puVar1 + 0xac) = local_a8;
    if (local_a0 != 0) {
      FUN_004f1f10(PTR_DAT_00802c54 + *(int *)(PTR_DAT_00802c54 + 0x2aec) * 0xdc + 0x2af0,local_a0);
    }
    FUN_0048a310(PTR_DAT_00802c54,
                 PTR_DAT_00802c54 + *(int *)(PTR_DAT_00802c54 + 0x2aec) * 0xdc + 0x2af0);
    if (((local_b8 != 0) && (*(int *)(puVar1 + 4) != 0)) && (iVar7 = 0, 0 < local_b8)) {
      local_bc = local_84;
      do {
        iVar2 = 0;
        iVar3 = 0x18;
        do {
          iVar5 = FUN_004f8b10(local_bc,*(undefined4 *)(iVar3 + *(int *)(puVar1 + 4)));
          if (iVar5 == 0) {
            *(float *)(puVar1 + iVar2 * 4 + 0x14) = afStack_94[iVar7];
            break;
          }
          iVar3 = iVar3 + 8;
          iVar2 = iVar2 + 1;
        } while (iVar3 < 0x38);
        local_bc = local_bc + 0x20;
        iVar7 = iVar7 + 1;
      } while (iVar7 < local_b8);
    }
    *(int *)(PTR_DAT_00802c54 + 0x2aec) = *(int *)(PTR_DAT_00802c54 + 0x2aec) + 1;
    FUN_0055af20(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),
                 *(undefined4 *)(PTR_DAT_00802c54 + 0x2acc),PTR_DAT_00802c54);
  }
  __security_check_cookie(local_4 ^ (uint)&local_bc);
  return;
}

