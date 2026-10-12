/* Ghidra analysis pseudocode, not original source.
 * ev_7b35a8fafa232ee0b9a0913c200a618a9d6b1b7e21f700964d68a0258798e3f5
 * Entry: 0x7144d7; label: strtoxq
 */

/* WARNING: Removing unreachable block (ram,0x00714650) */
/* WARNING: Removing unreachable block (ram,0x007146e6) */
/* Library Function - Single Match
    unsigned __int64 __cdecl strtoxq(struct localeinfo_struct *,char const *,char const * *,int,int)
   
   Library: Visual Studio 2005 Release */

__uint64 __cdecl
strtoxq(localeinfo_struct *param_1,char *param_2,char **param_3,int param_4,int param_5)

{
  ushort uVar1;
  char *pcVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint extraout_ECX;
  pthreadlocinfo ptVar7;
  byte *pbVar8;
  byte *pbVar9;
  longlong lVar10;
  localeinfo_struct local_3c;
  int local_34;
  char local_30;
  int local_28;
  uint local_24;
  int local_20;
  ulonglong local_1c;
  undefined8 local_14;
  byte *local_c;
  byte local_5;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_3c,param_1);
  if (param_3 != (char **)0x0) {
    *param_3 = param_2;
  }
  if ((param_2 == (char *)0x0) || ((param_4 != 0 && ((param_4 < 2 || (0x24 < param_4)))))) {
    puVar4 = (undefined4 *)FUN_006ead5f();
    *puVar4 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    if (local_30 != '\0') {
      *(uint *)(local_34 + 0x70) = *(uint *)(local_34 + 0x70) & 0xfffffffd;
    }
    return 0;
  }
  local_14._0_4_ = 0;
  local_14._4_4_ = 0;
  ptVar7 = local_3c.locinfo;
  pbVar9 = (byte *)param_2;
  do {
    pbVar8 = pbVar9;
    local_5 = *pbVar8;
    pbVar9 = pbVar8 + 1;
    if ((int)ptVar7->locale_name[3] < 2) {
      uVar5 = (byte)ptVar7[1].lc_category[0].locale[(uint)local_5 * 2] & 8;
    }
    else {
      uVar5 = __isctype_l((uint)local_5,8,&local_3c);
      ptVar7 = local_3c.locinfo;
    }
  } while (uVar5 != 0);
  if (local_5 == 0x2d) {
    param_5 = param_5 | 2;
LAB_00714595:
    local_5 = *pbVar9;
    pbVar9 = pbVar8 + 2;
  }
  else if (local_5 == 0x2b) goto LAB_00714595;
  local_c = pbVar9;
  if (param_4 == 0) {
    if (local_5 != 0x30) {
      param_4 = 10;
      goto LAB_007145ea;
    }
    if ((*pbVar9 != 0x78) && (*pbVar9 != 0x58)) {
      param_4 = 8;
      goto LAB_007145ea;
    }
    param_4 = 0x10;
  }
  if (((param_4 == 0x10) && (local_5 == 0x30)) && ((*pbVar9 == 0x78 || (*pbVar9 == 0x58)))) {
    local_5 = pbVar9[1];
    local_c = pbVar9 + 2;
  }
LAB_007145ea:
  local_28 = param_4 >> 0x1f;
  local_1c = __aulldvrm(0xffffffff,0xffffffff,param_4,local_28);
  local_20 = 0;
  pcVar2 = ptVar7[1].lc_category[0].locale;
  local_24 = extraout_ECX;
  do {
    uVar1 = *(ushort *)(pcVar2 + (uint)local_5 * 2);
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 0x103) == 0) {
LAB_0071467d:
        local_c = local_c + -1;
        if ((param_5 & 8U) == 0) {
          if (param_3 != (char **)0x0) {
            local_c = (byte *)param_2;
          }
          uVar3 = 0;
        }
        else if (((param_5 & 4U) != 0) ||
                ((uVar3 = local_14, (param_5 & 1U) == 0 &&
                 ((((param_5 & 2U) != 0 && (0x8000000000000000 < local_14)) ||
                  (((param_5 & 2U) == 0 &&
                   ((0x7ffffffeffffffff < local_14 && (0x7fffffffffffffff < local_14)))))))))) {
          puVar4 = (undefined4 *)FUN_006ead5f();
          *puVar4 = 0x22;
          if ((param_5 & 1U) == 0) {
            if ((param_5 & 2U) == 0) {
              uVar3 = 0x7fffffffffffffff;
            }
            else {
              uVar3 = 0x8000000000000000;
            }
          }
          else {
            uVar3 = 0xffffffffffffffff;
          }
        }
        local_14._4_4_ = (int)(uVar3 >> 0x20);
        local_14._0_4_ = (int)uVar3;
        if (param_3 != (char **)0x0) {
          *param_3 = (char *)local_c;
        }
        if ((param_5 & 2U) != 0) {
          uVar3 = CONCAT44(-(local_14._4_4_ + (uint)((int)local_14 != 0)),-(int)local_14);
        }
        if (local_30 != '\0') {
          *(uint *)(local_34 + 0x70) = *(uint *)(local_34 + 0x70) & 0xfffffffd;
        }
        return uVar3;
      }
      iVar6 = (int)(char)local_5;
      if ((byte)(local_5 + 0x9f) < 0x1a) {
        iVar6 = iVar6 + -0x20;
      }
      uVar5 = iVar6 - 0x37;
    }
    else {
      uVar5 = (int)(char)local_5 - 0x30;
    }
    if ((uint)param_4 <= uVar5) goto LAB_0071467d;
    if ((local_14 < local_1c) ||
       ((local_1c == local_14 && ((local_20 != 0 || (uVar5 <= local_24)))))) {
      lVar10 = __allmul(param_4,local_28,local_14);
      local_14 = lVar10 + (ulonglong)uVar5;
      param_5 = param_5 | 8;
    }
    else {
      param_5 = param_5 | 0xc;
      if (param_3 == (char **)0x0) goto LAB_0071467d;
    }
    local_5 = *local_c;
    local_c = local_c + 1;
  } while( true );
}

