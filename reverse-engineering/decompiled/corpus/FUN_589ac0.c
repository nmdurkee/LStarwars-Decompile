/* Ghidra analysis pseudocode, not original source.
 * ev_4597a773e0370c09a0c234dc3483b3ea71e6a654f79adb326cefb52c3abac04d
 * Entry: 0x589ac0; label: FUN_00589ac0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00589ac0(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_ECX;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined *puVar10;
  int local_41c;
  int local_418;
  int local_414;
  undefined4 local_410;
  undefined4 *local_40c;
  int local_408;
  undefined1 local_404 [256];
  undefined1 local_304 [256];
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_41c;
  iVar6 = 0;
  local_410 = param_2;
  DAT_009553c8 = param_1;
  if ((DAT_009553cc == 0) || (param_1 == 0)) {
    local_414 = 0;
  }
  else {
    local_408 = DAT_009248ac + -0x100000;
    local_414 = FUN_004fd9f0("chars\\charstxt.fpk",&local_408,DAT_009248ac,4);
  }
  if (0 < DAT_0093b278) {
    puVar9 = (undefined4 *)(DAT_0093b274 + 0xc);
    do {
      if ((param_1 == 0) &&
         (local_40c = puVar9, *(short *)(*(int *)(DAT_029130e4 + 0x1c) + iVar6 * 2) == -1))
      goto LAB_00589f00;
      local_40c = puVar9;
      FUN_004f1f10(local_404,"chars\\");
      FUN_004f1e80(local_404,puVar9[-1]);
      FUN_004f1e80(local_404,&DAT_0075a204);
      FUN_004f1f10(local_204,local_404);
      FUN_004f1e80(local_404,*puVar9);
      FUN_004f1e80(local_404,&DAT_0075d39c);
      FUN_004f1f10(local_304,*puVar9);
      FUN_004f1e80(local_304,&DAT_0075d39c);
      FUN_004f1f10(local_104,local_404);
      iVar4 = local_414;
      if (local_414 == 0) {
        if (param_1 == 0) {
          puVar9 = (undefined4 *)0x0;
        }
        else {
          puVar9 = &DAT_00924878;
        }
        iVar4 = FUN_00589410(iVar6,local_204,local_304,puVar9,param_1 != 0,0,0,1);
LAB_00589df7:
        iVar2 = local_414;
        if (iVar4 == 2) {
          if (local_414 == 0) {
            iVar4 = 0;
            puVar10 = (undefined *)0x0;
            if (param_1 == 0) {
              uVar3 = 0;
              puVar9 = (undefined4 *)0x0;
              puVar8 = local_304;
              puVar7 = local_204;
            }
            else {
              uVar3 = 1;
              puVar9 = &DAT_00924878;
              puVar8 = local_304;
              puVar7 = local_204;
            }
LAB_00589ef3:
            _DAT_009553d0 = 1;
            FUN_00589410(iVar6,puVar7,puVar8,puVar9,uVar3,puVar10,iVar4,0);
          }
          else {
            iVar4 = FUN_004f9de0(local_414,local_104);
            if (((iVar4 != 0) &&
                (iVar4 = FUN_004f0f30(iVar2,iVar4,&local_418,&local_41c), iVar2 = local_41c,
                iVar4 != 0)) && (0 < local_41c)) {
              uVar1 = *(undefined1 *)(local_418 + local_41c);
              *(undefined1 *)(local_418 + local_41c) = 0;
              iVar4 = FUN_0054be70(local_418,&DAT_0092b0c8,1);
              *(undefined1 *)(iVar2 + local_418) = uVar1;
              local_41c = iVar4;
              if (0 < iVar4) {
                puVar10 = &DAT_0092b0c8;
                uVar3 = 0;
                puVar9 = &DAT_00924878;
                puVar8 = (undefined1 *)0x0;
                puVar7 = (undefined1 *)0x0;
                goto LAB_00589ef3;
              }
            }
          }
        }
      }
      else {
        FUN_005845b0(local_404);
        iVar2 = FUN_004f9de0(iVar4,extraout_ECX);
        if (iVar2 == 0) {
          FUN_005845b0(local_404);
        }
        else {
          uVar3 = FUN_005845b0();
          iVar2 = FUN_004f0f30(iVar4,uVar3,&local_418,&local_41c);
          iVar4 = local_41c;
          if ((iVar2 == 0) || (local_41c < 1)) {
            FUN_005845b0();
          }
          else {
            uVar1 = *(undefined1 *)(local_418 + local_41c);
            *(undefined1 *)(local_418 + local_41c) = 0;
            local_41c = FUN_0054be70(local_418,&DAT_0092b0c8,1);
            *(undefined1 *)(iVar4 + local_418) = uVar1;
            if (0 < local_41c) {
              iVar4 = FUN_00584640(local_304,0x40);
              if (iVar4 == 0) {
LAB_00589d64:
                if (local_41c < 1) goto LAB_00589df7;
              }
              else {
                FUN_004f1e80(local_304,&DAT_0075d39c);
                FUN_004f1f10(local_404,local_204);
                FUN_004f1e80(local_404,local_304);
                iVar2 = local_414;
                iVar5 = FUN_004f9de0(local_414,local_404);
                if (((iVar5 == 0) ||
                    (iVar5 = FUN_004f0f30(iVar2,iVar5,&local_418,&local_41c), iVar2 = local_41c,
                    iVar5 == 0)) || (local_41c < 1)) {
                  iVar4 = 0;
                  goto LAB_00589d64;
                }
                uVar1 = *(undefined1 *)(local_418 + local_41c);
                *(undefined1 *)(local_418 + local_41c) = 0;
                local_41c = FUN_0054be70(local_418,&DAT_0092b0c8,1);
                *(undefined1 *)(iVar2 + local_418) = uVar1;
                if (local_41c < 1) {
                  iVar4 = 0;
                  goto LAB_00589d64;
                }
              }
              FUN_00589410(iVar6,0,0,&DAT_00924878,1,&DAT_0092b0c8,local_41c,0);
              goto LAB_00589df7;
            }
          }
        }
      }
LAB_00589f00:
      iVar6 = iVar6 + 1;
      puVar9 = local_40c + 0x13;
      local_40c = puVar9;
    } while (iVar6 < DAT_0093b278);
  }
  __security_check_cookie(local_4 ^ (uint)&local_41c);
  return;
}

