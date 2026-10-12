/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x464c50; label: FUN_00464c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00464c50(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_24 [3];
  char local_21;
  int local_20;
  int local_1c;
  int local_18;
  undefined1 local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_24;
  iVar6 = 0;
  iVar5 = 0;
  local_1c = 0;
  local_20 = 0;
  local_21 = -1;
  if (0 < param_4) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar6 * 4),"techno=");
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar6 * 4),"target=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8b10(0,"Move_Waggle");
          if (iVar2 == 0) {
            local_21 = '\x01';
          }
          else {
            iVar2 = FUN_004f8b10(0,"Move_Spin");
            if (iVar2 == 0) {
              local_21 = '\x02';
            }
            else {
              iVar2 = FUN_004f8b10(0,"Move_Horizontal");
              if (iVar2 == 0) {
                local_21 = '\b';
              }
              else {
                iVar2 = FUN_004f8b10(0,"Move_Vertical");
                if (iVar2 == 0) {
                  local_21 = '\x04';
                }
                else {
                  iVar2 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar6 * 4),"GIZMO");
                  if (iVar2 == 0) {
                    local_20 = 3;
                  }
                  else {
                    iVar2 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar6 * 4),"HSPECIAL");
                    if (iVar2 == 0) {
                      local_20 = 2;
                    }
                    else {
                      iVar2 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar6 * 4),"CREATURE");
                      if (iVar2 == 0) {
                        local_20 = 1;
                      }
                      else {
                        iVar2 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar6 * 4),"NO_TARGET");
                        if (iVar2 == 0) {
                          local_20 = -1;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else {
          local_1c = FUN_004f1ff0("target=");
          local_1c = local_1c + iVar2;
        }
      }
      else {
        iVar5 = FUN_004f1ff0("techno=");
        iVar5 = iVar5 + iVar2;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_4);
    if ((iVar5 != 0) && ((local_1c != 0 || (local_20 == -1)))) {
      uVar3 = FUN_00559e20(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),"Techno",iVar5);
      piVar4 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),uVar3);
      if ((piVar4 != (int *)0x0) && (iVar5 = *piVar4, iVar5 != 0)) {
        if (local_21 != -1) {
          *(char *)(iVar5 + 0x36) = local_21;
        }
        if (local_20 == -1) {
          FUN_004cd9a0(*(undefined4 *)(iVar5 + 0x6c),0,&local_18);
          *(undefined4 *)(iVar5 + 0x6c) = 0;
          FUN_004f1f10(iVar5 + 0x3d,&DAT_007516c0);
          *(byte *)(iVar5 + 0x3c) = *(byte *)(iVar5 + 0x3c) & 0xf7;
          *(undefined1 *)(iVar5 + 0x37) = 0;
          if (local_18 != 0) {
            *(undefined1 *)(local_18 + 0x7b5) = 0xff;
          }
        }
        uVar3 = *(undefined4 *)(iVar5 + 0x6c);
        iVar6 = iVar5 + 0x3d;
        FUN_004f1f10(local_14,iVar6);
        bVar1 = *(byte *)(iVar5 + 0x3c);
        *(undefined4 *)(iVar5 + 0x6c) = 0;
        FUN_004f1f40(iVar6,local_1c,0x10);
        *(byte *)(iVar5 + 0x3c) = *(byte *)(iVar5 + 0x3c) & 0xf7;
        *(undefined1 *)(iVar5 + 0x37) = (undefined1)local_20;
        FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
        iVar2 = FUN_004ccad0(iVar5);
        if (iVar2 == 0) {
          *(undefined1 *)(iVar5 + 0x37) = 0;
          iVar2 = FUN_004ccad0(iVar5);
          if (iVar2 == 0) {
            FUN_004f1f10(iVar6,local_14);
            *(byte *)(iVar5 + 0x3c) =
                 *(byte *)(iVar5 + 0x3c) ^ ((bVar1 >> 3 & 1) << 3 ^ *(byte *)(iVar5 + 0x3c)) & 8;
            *(undefined1 *)(iVar5 + 0x37) = (undefined1)local_20;
            *(undefined4 *)(iVar5 + 0x6c) = uVar3;
          }
        }
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)auStack_24);
  return;
}

