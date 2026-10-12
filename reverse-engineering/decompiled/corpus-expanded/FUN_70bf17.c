/* Ghidra pseudocode, not original source.
 * ev_3d36383f96f3bc0df86ca3b0bd2be0f2b31f3818026a757d33379a6c98cf77a3
 * Entry: 0x70bf17; label: __Strftime_l
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __Strftime_l
   
   Library: Visual Studio 2005 Release */

int __Strftime_l(char *param_1,uint param_2,char *param_3,int param_4,int *param_5,
                localeinfo_struct *param_6)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  localeinfo_struct local_24;
  int local_1c;
  char local_18;
  char *local_14;
  int *local_10;
  int local_c;
  uint local_8;
  
  local_c = 0;
  local_14 = param_1;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_24,param_6);
  if (param_1 == (char *)0x0) {
    puVar2 = (undefined4 *)FUN_006ead5f();
    *puVar2 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    if (local_18 != '\0') {
      *(uint *)(local_1c + 0x70) = *(uint *)(local_1c + 0x70) & 0xfffffffd;
    }
    return 0;
  }
  if (param_2 == 0) {
    puVar2 = (undefined4 *)FUN_006ead5f();
    *puVar2 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    if (local_18 != '\0') {
      *(uint *)(local_1c + 0x70) = *(uint *)(local_1c + 0x70) & 0xfffffffd;
    }
    return 0;
  }
  *param_1 = '\0';
  if (param_3 != (char *)0x0) {
    if (param_5 == (int *)0x0) {
      param_5 = local_24.locinfo[1].lc_category[0].wrefcount;
    }
    local_8 = param_2;
    local_10 = param_5;
    if (param_2 != 0) {
      do {
        cVar1 = *param_3;
        if (cVar1 == '\0') break;
        if (cVar1 == '%') {
          if (param_4 == 0) {
            puVar2 = (undefined4 *)FUN_006ead5f();
            *puVar2 = 0x16;
            goto LAB_0070c0b3;
          }
          pcVar4 = param_3 + 1;
          cVar1 = *pcVar4;
          if (cVar1 == '#') {
            pcVar4 = param_3 + 2;
          }
          iVar3 = FUN_0070b6d4(&local_24,&local_8,local_10,cVar1 == '#');
          if (iVar3 == 0) {
            if (local_8 != 0) {
              local_c = 1;
            }
            goto LAB_0070c064;
          }
        }
        else {
          iVar3 = __isleadbyte_l((int)cVar1,&local_24);
          pcVar4 = param_3;
          if ((iVar3 != 0) && (1 < local_8)) {
            pcVar4 = param_3 + 1;
            if (*pcVar4 == '\0') {
              local_c = 1;
              goto LAB_0070c064;
            }
            *param_1 = *param_3;
            param_1 = param_1 + 1;
            local_8 = local_8 - 1;
          }
          *param_1 = *pcVar4;
          param_1 = param_1 + 1;
          local_8 = local_8 - 1;
        }
        param_3 = pcVar4 + 1;
      } while (local_8 != 0);
      if (local_8 != 0) {
        *param_1 = '\0';
        if (local_18 == '\0') {
          return param_2 - local_8;
        }
        *(uint *)(local_1c + 0x70) = *(uint *)(local_1c + 0x70) & 0xfffffffd;
        return param_2 - local_8;
      }
    }
LAB_0070c064:
    *local_14 = '\0';
    if ((local_c == 0) && (local_8 == 0)) {
      puVar2 = (undefined4 *)FUN_006ead5f();
      *puVar2 = 0x22;
      goto LAB_0070c0b3;
    }
  }
  puVar2 = (undefined4 *)FUN_006ead5f();
  *puVar2 = 0x16;
  FUN_006e9fc2(0,0,0,0,0);
LAB_0070c0b3:
  if (local_18 != '\0') {
    *(uint *)(local_1c + 0x70) = *(uint *)(local_1c + 0x70) & 0xfffffffd;
  }
  return 0;
}

