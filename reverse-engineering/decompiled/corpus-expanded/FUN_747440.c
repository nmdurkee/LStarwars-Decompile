/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x747440; label: FUN_00747440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00747440(void)

{
  char cVar1;
  void *_Dst;
  undefined *puVar2;
  byte bVar3;
  int iVar4;
  char *_Src;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int in_ECX;
  uint *puVar8;
  uint uVar9;
  undefined1 auStack_9c [3];
  byte local_99;
  uint *local_98;
  undefined4 *local_94;
  undefined1 *local_90;
  int local_8c;
  char *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_9c;
  local_8c = 0;
  if (0 < *(int *)(in_ECX + 0x89c)) {
    local_94 = (undefined4 *)(in_ECX + 0x4b4);
    do {
      puVar8 = (uint *)*local_94;
      local_98 = puVar8;
      if (((*(char *)(in_ECX + 0x969) != '\0') && (uVar9 = *puVar8, (uVar9 & 0x4020) == 0x4020)) ||
         ((uVar9 = *puVar8, (uVar9 >> 5 & 1) != 0 &&
          ((0 < (int)puVar8[8] && (iVar4 = FUN_00746bb0(puVar8[3]), iVar4 == 0)))))) {
        if (*(int *)(in_ECX + 0x97c) == 0) {
          bVar3 = (byte)(uVar9 >> 0xd);
        }
        else {
          bVar3 = (byte)(uVar9 >> 0xc);
        }
        local_99 = ~bVar3 & 1;
        _Src = (char *)FUN_00746a00(puVar8);
        FUN_007486b0("#define ");
        FUN_007486b0(_Src);
        FUN_007486b0(&DAT_0076aa4c);
        iVar4 = FUN_00746bb0(_Src);
        if (iVar4 == 0) {
          pcVar5 = _Src;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          _Dst = *(void **)(in_ECX + 0x948);
          *(char **)(in_ECX + 0x948) = pcVar5 + (int)_Dst + (1 - (int)(_Src + 1));
          _memcpy(_Dst,_Src,(size_t)(pcVar5 + (1 - (int)(_Src + 1))));
          puVar6 = *(undefined4 **)(in_ECX + 0x948);
          *(undefined4 **)(in_ECX + 0x948) = puVar6 + 3;
          if (puVar6 == (undefined4 *)0x0) {
            puVar6 = (undefined4 *)0x0;
          }
          else {
            *puVar6 = _Dst;
            puVar6[1] = 0;
            *(undefined1 *)(puVar6 + 2) = 0;
          }
          *(undefined4 **)(in_ECX + *(int *)(in_ECX + 0x4b0) * 4) = puVar6;
          *(int *)(in_ECX + 0x4b0) = *(int *)(in_ECX + 0x4b0) + 1;
          puVar8 = local_98;
        }
        else {
          *(undefined4 *)(iVar4 + 4) = 0;
          *(undefined1 *)(iVar4 + 8) = 0;
        }
        if (puVar8[1] != 0x15) {
          if (((local_99 == 0) && (*(char *)(in_ECX + 0x967) != '\0')) &&
             ((*puVar8 & 0x4020) == 0x4020)) {
            local_88 = "shared ";
          }
          else {
            local_88 = "";
          }
          uVar9 = puVar8[2];
          if ((int)uVar9 < 0) {
            if (uVar9 == 0xfffffffe) {
              uVar7 = FUN_007467a0(puVar8[3]);
              _sprintf(local_84,"[%d] ",uVar7);
            }
            else {
              local_84[0] = '\0';
            }
          }
          else {
            _sprintf(local_84,"[%d] ",uVar9);
          }
          if (*(char *)(in_ECX + 0x968) == '\0') {
            local_90 = &DAT_007516c0;
            local_98 = (uint *)&DAT_007516c0;
          }
          else {
            local_90 = &DAT_00759700;
            local_98 = (uint *)FUN_00746590();
          }
          if ((local_99 == 0) && ((*puVar8 >> 5 & 1) != 0)) {
            if (*(int *)(in_ECX + 0x97c) == 0) {
              uVar9 = puVar8[6];
            }
            else {
              uVar9 = puVar8[7];
            }
            iVar4 = FUN_00744160(puVar8[3]);
            if (iVar4 != 0) {
              uVar9 = *(uint *)(iVar4 + 0x14);
            }
            if (((int)uVar9 < 0) ||
               ((*(int *)(in_ECX + 0x974) != 4 && (*(int *)(in_ECX + 0x974) != 5))))
            goto LAB_007476a1;
            _sprintf(local_44,*(char **)(in_ECX + 0x96c),uVar9);
          }
          else {
LAB_007476a1:
            local_44[0] = '\0';
          }
          puVar2 = (&PTR_s_undefined_008543d0)[puVar8[1]];
          FUN_007486b0(local_88);
          FUN_007486b0("uniform ");
          FUN_007486b0(puVar2);
          FUN_007486b0(&DAT_007596f8);
          FUN_007486b0(puVar8[3]);
          FUN_007486b0(local_84);
          FUN_007486b0(local_90);
          FUN_007486b0(local_98);
          FUN_007486b0(local_44);
          FUN_007486b0(&DAT_007e9630);
        }
      }
      local_94 = local_94 + 1;
      local_8c = local_8c + 1;
    } while (local_8c < *(int *)(in_ECX + 0x89c));
  }
  __security_check_cookie(local_4 ^ (uint)auStack_9c);
  return;
}

