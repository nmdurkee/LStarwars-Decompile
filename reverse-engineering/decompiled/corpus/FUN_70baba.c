/* Ghidra analysis pseudocode, not original source.
 * ev_aee1a4f0943f0e53edaf0cbac59fb891b878b74e3aefed4690394b4ea17c7eca
 * Entry: 0x70baba; label: FUN_0070baba
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_0070baba(_locale_t param_1,int param_2,undefined2 *param_3,int *param_4,uint *param_5,
                 int param_6)

{
  code cVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  code *_Str1;
  code *pcVar7;
  char *pcVar8;
  char *pcVar9;
  short local_24;
  short local_22;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  int local_14;
  code *local_10;
  undefined4 *local_c;
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  if (param_2 == 0) {
    _Str1 = *(code **)(param_6 + 0xa0);
  }
  else if (param_2 == 1) {
    _Str1 = *(code **)(param_6 + 0xa4);
  }
  else {
    _Str1 = *(code **)(param_6 + 0xa8);
  }
  if (*(int *)(param_6 + 0xb0) != 1) {
    local_10 = GetDateFormatA_exref;
    if (param_2 == 2) {
      local_10 = GetTimeFormatA_exref;
    }
    local_24 = param_3[10] + 0x76c;
    local_22 = param_3[8] + 1;
    local_1e = param_3[6];
    local_1c = param_3[4];
    local_1a = param_3[2];
    local_18 = *param_3;
    local_16 = 0;
    local_14 = (*local_10)(*(undefined4 *)(param_6 + 0xac),0,&local_24,_Str1,0,0);
    if (local_14 != 0) {
      if ((int)(local_14 + 8U) < 0x401) {
        puVar2 = (undefined4 *)&stack0xffffffd0;
        puVar6 = (undefined4 *)&stack0xffffffd0;
        if (&stack0x00000000 != (undefined1 *)0x30) {
LAB_0070bb9a:
          puVar6 = puVar2 + 2;
        }
      }
      else {
        puVar2 = _malloc(local_14 + 8U);
        puVar6 = (undefined4 *)0x0;
        if (puVar2 != (undefined4 *)0x0) {
          *puVar2 = 0xdddd;
          goto LAB_0070bb9a;
        }
      }
      local_c = puVar6;
      if (puVar6 != (undefined4 *)0x0) {
        iVar3 = (*local_10)(*(undefined4 *)(param_6 + 0xac),0,&local_24,_Str1,puVar6,local_14);
        while ((iVar3 = iVar3 + -1, 0 < iVar3 && (*param_5 != 0))) {
          local_14 = iVar3;
          *(undefined1 *)*param_4 = *(undefined1 *)puVar6;
          *param_4 = *param_4 + 1;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          *param_5 = *param_5 - 1;
        }
        __freea(local_c);
LAB_0070bbec:
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
  cVar1 = *_Str1;
joined_r0x0070bc02:
  if ((cVar1 == (code)0x0) || (*param_5 == 0)) goto LAB_0070bbec;
  local_c = (undefined4 *)0x0;
  local_10 = _Str1;
  uVar5 = 0;
  do {
    uVar4 = uVar5;
    local_10 = local_10 + 1;
    uVar5 = uVar4 + 1;
  } while (*local_10 == cVar1);
  iVar3 = (int)(char)cVar1;
  if (iVar3 < 0x65) {
    if (iVar3 == 100) {
      if (uVar4 == 0) {
        local_c = (undefined4 *)0x1;
      }
      else {
joined_r0x0070bd85:
        if ((uVar4 != 1) && (uVar4 != 2)) {
joined_r0x0070bd8b:
          if (uVar4 != 3) goto LAB_0070bc56;
        }
      }
      goto LAB_0070beed;
    }
    if (iVar3 != 0x27) {
      if (iVar3 == 0x41) {
LAB_0070bcde:
        iVar3 = ___ascii_stricmp((char *)_Str1,"am/pm");
        if (iVar3 == 0) {
          local_10 = _Str1 + 5;
        }
        else {
          iVar3 = ___ascii_stricmp((char *)_Str1,"a/p");
          if (iVar3 == 0) {
            local_10 = _Str1 + 3;
          }
        }
      }
      else if (iVar3 == 0x48) {
        if (uVar4 != 0) goto joined_r0x0070bedd;
        local_c = (undefined4 *)0x1;
      }
      else {
        if (iVar3 != 0x4d) {
          if (iVar3 != 0x61) goto LAB_0070bc56;
          goto LAB_0070bcde;
        }
        if (uVar4 != 0) goto joined_r0x0070bd85;
        local_c = (undefined4 *)0x1;
      }
      goto LAB_0070beed;
    }
    _Str1 = _Str1 + uVar5;
    if ((uVar5 & 1) != 0) {
      cVar1 = *_Str1;
      if (cVar1 == (code)0x0) goto LAB_0070bbec;
      do {
        if (*param_5 == 0) break;
        if (cVar1 == (code)0x27) {
          _Str1 = _Str1 + 1;
          break;
        }
        iVar3 = __isleadbyte_l((int)(char)cVar1,param_1);
        pcVar7 = _Str1;
        if ((iVar3 != 0) && (1 < *param_5)) {
          pcVar7 = _Str1 + 1;
          if (*pcVar7 == (code)0x0) goto LAB_0070bbec;
          *(code *)*param_4 = *_Str1;
          *param_4 = *param_4 + 1;
          *param_5 = *param_5 - 1;
        }
        *(code *)*param_4 = *pcVar7;
        *param_4 = *param_4 + 1;
        _Str1 = pcVar7 + 1;
        *param_5 = *param_5 - 1;
        cVar1 = *_Str1;
      } while (cVar1 != (code)0x0);
    }
  }
  else {
    if (iVar3 == 0x68) {
      if (uVar4 == 0) {
        local_c = (undefined4 *)0x1;
      }
      else {
joined_r0x0070bedd:
        if (uVar5 != 2) {
LAB_0070bc56:
          iVar3 = __isleadbyte_l(iVar3,param_1);
          pcVar7 = _Str1;
          if ((iVar3 != 0) && (1 < *param_5)) {
            pcVar7 = _Str1 + 1;
            if (*pcVar7 == (code)0x0) goto LAB_0070bbec;
            *(code *)*param_4 = *_Str1;
            *param_4 = *param_4 + 1;
            *param_5 = *param_5 - 1;
          }
          *(code *)*param_4 = *pcVar7;
          *param_4 = *param_4 + 1;
          *param_5 = *param_5 - 1;
          _Str1 = pcVar7 + 1;
          goto LAB_0070bc8d;
        }
      }
    }
    else if (iVar3 == 0x6d) {
      if (uVar4 != 0) goto joined_r0x0070bedd;
      local_c = (undefined4 *)0x1;
    }
    else if (iVar3 == 0x73) {
      if (uVar4 != 0) goto joined_r0x0070bedd;
      local_c = (undefined4 *)0x1;
    }
    else {
      if (iVar3 == 0x74) {
        if (*(int *)(param_3 + 4) < 0xc) {
          pcVar9 = *(char **)(param_6 + 0x98);
        }
        else {
          pcVar9 = *(char **)(param_6 + 0x9c);
        }
        if ((uVar5 == 1) && (*param_5 != 0)) {
          iVar3 = __isleadbyte_l((int)*pcVar9,param_1);
          pcVar8 = pcVar9;
          if ((iVar3 != 0) && (1 < *param_5)) {
            pcVar8 = pcVar9 + 1;
            if (*pcVar8 == '\0') goto LAB_0070bbec;
            *(char *)*param_4 = *pcVar9;
            *param_4 = *param_4 + 1;
            *param_5 = *param_5 - 1;
          }
          *(char *)*param_4 = *pcVar8;
          *param_4 = *param_4 + 1;
          *param_5 = *param_5 - 1;
          _Str1 = local_10;
          goto LAB_0070bc8d;
        }
        while ((_Str1 = local_10, *pcVar9 != '\0' && (*param_5 != 0))) {
          iVar3 = __isleadbyte_l((int)*pcVar9,param_1);
          pcVar8 = pcVar9;
          if ((iVar3 != 0) && (1 < *param_5)) {
            pcVar8 = pcVar9 + 1;
            if (*pcVar8 == '\0') goto LAB_0070bbec;
            *(char *)*param_4 = *pcVar9;
            *param_4 = *param_4 + 1;
            *param_5 = *param_5 - 1;
          }
          *(char *)*param_4 = *pcVar8;
          *param_4 = *param_4 + 1;
          pcVar9 = pcVar8 + 1;
          *param_5 = *param_5 - 1;
        }
        goto LAB_0070bc8d;
      }
      if (iVar3 != 0x79) goto LAB_0070bc56;
      if (uVar4 != 1) goto joined_r0x0070bd8b;
    }
LAB_0070beed:
    iVar3 = FUN_0070b6d4(param_1,param_5,param_6,local_c);
    _Str1 = local_10;
    if (iVar3 == 0) goto LAB_0070bbec;
  }
LAB_0070bc8d:
  cVar1 = *_Str1;
  goto joined_r0x0070bc02;
}

