/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4df9b0; label: FUN_004df9b0
 */

void FUN_004df9b0(void)

{
  int iVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined1 local_1c;
  int local_1b;
  undefined2 local_17;
  undefined1 local_15;
  undefined2 local_14 [8];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_1c;
  iVar6 = FUN_0058a900(DAT_009553d4);
  uVar2 = local_1c;
  uVar3 = local_17;
  if (iVar6 != 0) goto switchD_004dfa40_default;
  uVar4 = 0;
  local_1c = 0;
  uVar5 = 0;
  local_17 = 0;
  local_15 = 0;
  uVar2 = local_1c;
  local_1b = iVar6;
  uVar3 = local_17;
  if (DAT_00951b50 != 0) {
    if (*DAT_00882b10 == 1) {
      switch(DAT_00882b10[1]) {
      case 1:
      case 2:
      case 3:
        local_1c = uVar4;
        local_17 = uVar5;
        FUN_004baad0(DAT_00882b10 + 4,DAT_00882b10 + 0xc,0,(int)DAT_00882b10[2]);
        __security_check_cookie(local_4 ^ (uint)&local_1c);
        return;
      case 4:
      case 5:
      case 6:
        local_1c = uVar4;
        local_17 = uVar5;
        FUN_004baad0(DAT_00882b10 + 4,DAT_00882b10 + 0xc,0,6);
        __security_check_cookie(local_4 ^ (uint)&local_1c);
        return;
      case 7:
        goto switchD_004dfbcf_caseD_7;
      default:
        break;
      }
    }
    goto switchD_004dfa40_default;
  }
  if (DAT_00951b54 != 0) {
    *DAT_00882b10 = DAT_00888ed6;
    DAT_00882b10[1] = DAT_00888ed4;
  }
  uVar2 = uVar4;
  uVar3 = uVar5;
  if (DAT_00888ed6 != 1) goto switchD_004dfa40_default;
  uVar2 = local_1c;
  uVar3 = local_17;
  switch(DAT_00888ed4) {
  case 1:
  case 2:
  case 3:
    if (DAT_00888ed2 == 0) {
      iVar6 = 1;
      if (DAT_00888ed4 == 1) {
        local_14[0] = DAT_007f19c8;
      }
      else if (DAT_00888ed4 == 2) {
        local_14[0] = DAT_007f19cc;
      }
      else if (DAT_00888ed4 == 3) {
        local_14[0] = DAT_007f19d0;
      }
    }
    else {
      iVar6 = (int)DAT_00888ed2;
      if (8 < iVar6) {
        iVar6 = 8;
      }
      iVar7 = 0;
      local_1c = uVar4;
      local_17 = uVar5;
      if (0 < iVar6) {
        piVar8 = &DAT_00888be4;
        do {
          iVar1 = *piVar8;
          local_14[iVar7] = (short)piVar8[-1];
          if (iVar1 == 0) {
            (&local_1c)[iVar7] = 1;
          }
          iVar7 = iVar7 + 1;
          piVar8 = piVar8 + 0x18;
        } while (iVar7 < iVar6);
      }
    }
    FUN_004baad0(local_14,&local_1c,0,iVar6);
    uVar2 = local_1c;
    uVar3 = local_17;
    if (DAT_00951b54 != 0) {
      FUN_004ef660(DAT_00882b10 + 4,local_14,iVar6 * 2);
      FUN_004ef660(DAT_00882b10 + 0xc,&local_1c,iVar6);
      DAT_00882b10[2] = (short)iVar6;
      uVar2 = local_1c;
      uVar3 = local_17;
    }
    break;
  case 4:
  case 5:
  case 6:
    local_1c = uVar4;
    local_17 = uVar5;
    FUN_004baad0(&DAT_00888f94,&DAT_00888fa0,0,6);
    uVar2 = local_1c;
    uVar3 = local_17;
    if (DAT_00951b54 != 0) {
      FUN_004ef660(DAT_00882b10 + 4,&DAT_00888f94,0xc);
      FUN_004ef660(DAT_00882b10 + 0xc,&DAT_00888fa0,6);
      __security_check_cookie(local_4 ^ (uint)&local_1c);
      return;
    }
    break;
  case 7:
    local_1c = uVar4;
    local_17 = uVar5;
    goto LAB_004dfb90;
  }
  goto switchD_004dfa40_default;
switchD_004dfbcf_caseD_7:
  local_1c = uVar4;
  local_17 = uVar5;
  if (DAT_00888fa8 != 0) goto LAB_004dfb94;
  DAT_00888fa8 = FUN_0055ce20((int)DAT_007f19e0,1,1,0,0);
LAB_004dfb90:
  uVar2 = local_1c;
  uVar3 = local_17;
  if (DAT_00888fa8 != 0) {
LAB_004dfb94:
    FUN_004ba2d0(DAT_00888fa8);
    __security_check_cookie(local_4 ^ (uint)&local_1c);
    return;
  }
switchD_004dfa40_default:
  local_17 = uVar3;
  local_1c = uVar2;
  __security_check_cookie(local_4 ^ (uint)&local_1c);
  return;
}

