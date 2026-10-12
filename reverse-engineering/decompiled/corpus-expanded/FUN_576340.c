/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x576340; label: FUN_00576340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00576340(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char local_144;
  char local_143 [63];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_144;
  *param_2 = '\0';
  cVar1 = *param_1;
  do {
    if (cVar1 == '\0') {
      *param_2 = '\0';
      __security_check_cookie(local_4 ^ (uint)&local_144);
      return;
    }
    if (cVar1 == '[') {
      pcVar4 = param_1 + 1;
      cVar1 = *pcVar4;
      iVar5 = 1;
      local_104[0] = '[';
      if (cVar1 != '\0') {
        pcVar3 = pcVar4;
        do {
          if (cVar1 == ']') break;
          pcVar3[(int)(local_104 + -(int)param_1)] = cVar1;
          cVar1 = pcVar3[1];
          pcVar3 = pcVar3 + 1;
          iVar5 = iVar5 + 1;
        } while (cVar1 != '\0');
      }
      if (param_1[iVar5] != '\0') {
        local_104[iVar5] = ']';
        local_104[iVar5 + 1] = '\0';
        iVar5 = FUN_004f1ff0(local_104);
        if ((0 < iVar5) && (iVar2 = FUN_004015e0(local_104,&local_144), iVar2 != 0)) {
          pcVar4 = &local_144;
          cVar1 = local_144;
          while (cVar1 != '\0') {
            pcVar4 = pcVar4 + 1;
            *param_2 = cVar1;
            cVar1 = *pcVar4;
            param_2[1] = '\0';
            param_2 = param_2 + 1;
          }
          FUN_004f1e80(param_2,&local_144);
          pcVar4 = param_1 + iVar5;
          goto LAB_00576430;
        }
      }
      *param_2 = *param_1;
      param_2[1] = '\0';
      param_2 = param_2 + 1;
    }
    else {
      *param_2 = cVar1;
      param_2[1] = '\0';
      param_2 = param_2 + 1;
      pcVar4 = param_1 + 1;
    }
LAB_00576430:
    cVar1 = *pcVar4;
    param_1 = pcVar4;
  } while( true );
}

