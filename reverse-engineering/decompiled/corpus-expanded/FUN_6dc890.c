/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dc890; label: FUN_006dc890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dc890(undefined4 param_1)

{
  LANGID LVar1;
  LSTATUS LVar2;
  GEOID GVar3;
  bool bVar4;
  undefined4 uVar5;
  uint local_110;
  HKEY local_10c;
  DWORD local_108;
  CHAR local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_110;
  local_108 = 4;
  FUN_004f1f10(local_104,"SOFTWARE\\");
  FUN_004f1e80(local_104,param_1);
  LVar2 = RegOpenKeyExA((HKEY)0x80000002,local_104,0,1,&local_10c);
  if (LVar2 == 0) {
    RegQueryValueExA(local_10c,"LanguageVal",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_110,&local_108
                    );
    RegCloseKey(local_10c);
  }
  else {
    LVar1 = GetUserDefaultLangID();
    local_110 = (uint)LVar1;
  }
  if ((DAT_02975c54 == 0) && (local_110 == 0x409)) {
    local_110 = 0x809;
  }
  FUN_004f5270(3);
  if (0x807 < local_110) {
    if (0xc07 < local_110) {
      if (0x2009 < local_110) {
        if (local_110 < 0x340a) {
          if (local_110 == 0x3409) goto switchD_006dca0e_caseD_809;
          if (0x280a < local_110) {
            if (local_110 < 0x300a) {
              if ((local_110 == 0x3009) || (local_110 == 0x2c09)) goto switchD_006dca0e_caseD_809;
              bVar4 = local_110 == 0x2c0a;
            }
            else {
              bVar4 = local_110 == 0x300a;
            }
            goto LAB_006dcbc4;
          }
          if (local_110 != 0x280a) {
            if (local_110 < 0x240b) {
              if ((local_110 == 0x240a) || (local_110 == 0x200a)) goto switchD_006dc96b_caseD_40a;
              if (local_110 != 0x2409) goto switchD_006dc96b_caseD_40d;
            }
            else if (local_110 != 0x2809) goto switchD_006dc96b_caseD_40d;
            goto switchD_006dca0e_caseD_809;
          }
        }
        else if (local_110 < 0x440b) {
          if (local_110 != 0x440a) {
            if (local_110 < 0x3c0b) {
              if ((local_110 == 0x3c0a) || (local_110 == 0x340a)) goto switchD_006dc96b_caseD_40a;
              bVar4 = local_110 == 0x380a;
            }
            else {
              bVar4 = local_110 == 0x400a;
            }
LAB_006dcbc4:
            if (!bVar4) {
switchD_006dc96b_caseD_40d:
              switch(local_110 & 0x3ff) {
              case 6:
                __security_check_cookie(local_4 ^ (uint)&local_110);
                return;
              case 7:
                __security_check_cookie(local_4 ^ (uint)&local_110);
                return;
              default:
                __security_check_cookie(local_4 ^ (uint)&local_110);
                return;
              case 10:
                __security_check_cookie(local_4 ^ (uint)&local_110);
                return;
              case 0xc:
                __security_check_cookie(local_4 ^ (uint)&local_110);
                return;
              case 0x10:
                __security_check_cookie(local_4 ^ (uint)&local_110);
                return;
              case 0x15:
                __security_check_cookie(local_4 ^ (uint)&local_110);
                return;
              case 0x19:
                __security_check_cookie(local_4 ^ (uint)&local_110);
                return;
              }
            }
          }
        }
        else if ((local_110 != 0x480a) && (local_110 != 0x4c0a)) {
          bVar4 = local_110 == 0x500a;
          goto LAB_006dcbc4;
        }
        goto switchD_006dc96b_caseD_40a;
      }
      if (local_110 != 0x2009) {
        if (local_110 < 0x1408) {
          if (local_110 != 0x1407) {
            if (local_110 < 0x1008) {
              if (local_110 == 0x1007) goto switchD_006dc96b_caseD_407;
              if (local_110 == 0xc09) goto switchD_006dca0e_caseD_809;
              if (local_110 != 0xc0a) {
                if (local_110 == 0xc0c) {
                  FUN_004f5250(2);
                  FUN_004f5270(2);
                  goto LAB_006dccbf;
                }
                goto switchD_006dc96b_caseD_40d;
              }
            }
            else {
              if (local_110 == 0x1009) goto switchD_006dca0e_caseD_809;
              if (local_110 != 0x100a) {
                if (local_110 != 0x100c) goto switchD_006dc96b_caseD_40d;
                goto switchD_006dc96b_caseD_40c;
              }
            }
switchD_006dc96b_caseD_40a:
            uVar5 = 3;
            goto LAB_006dccb7;
          }
          goto switchD_006dc96b_caseD_407;
        }
        if (local_110 < 0x180b) {
          if (local_110 == 0x180a) goto switchD_006dc96b_caseD_40a;
          if (local_110 < 0x140d) {
            if (local_110 == 0x140c) goto switchD_006dc96b_caseD_40c;
            if (local_110 != 0x1409) {
              bVar4 = local_110 == 0x140a;
              goto LAB_006dcbc4;
            }
          }
          else if (local_110 != 0x1809) goto switchD_006dc96b_caseD_40d;
        }
        else {
          if (local_110 == 0x180c) {
switchD_006dc96b_caseD_40c:
            uVar5 = 2;
            goto LAB_006dccb7;
          }
          if (local_110 != 0x1c09) {
            bVar4 = local_110 == 0x1c0a;
            goto LAB_006dcbc4;
          }
        }
      }
switchD_006dca0e_caseD_809:
      uVar5 = 1;
      goto LAB_006dccb7;
    }
    if (local_110 != 0xc07) {
      switch(local_110) {
      case 0x809:
        goto switchD_006dca0e_caseD_809;
      case 0x80a:
        FUN_004f5250(3);
        FUN_004f5270(2);
        goto LAB_006dccbf;
      default:
        goto switchD_006dc96b_caseD_40d;
      case 0x80c:
        goto switchD_006dc96b_caseD_40c;
      case 0x810:
        goto switchD_006dc96b_caseD_410;
      case 0x813:
        goto switchD_006dc96b_caseD_413;
      case 0x816:
        uVar5 = 7;
        goto LAB_006dccb7;
      }
    }
switchD_006dc96b_caseD_407:
    uVar5 = 4;
    goto LAB_006dccb7;
  }
  if (local_110 == 0x807) goto switchD_006dc96b_caseD_407;
  switch(local_110) {
  case 0x405:
    uVar5 = 10;
    break;
  case 0x406:
    uVar5 = 8;
    break;
  case 0x407:
    goto switchD_006dc96b_caseD_407;
  case 0x408:
    uVar5 = 9;
    break;
  case 0x409:
    FUN_004f5250(0x12);
    FUN_004f5270(2);
    goto LAB_006dccbf;
  case 0x40a:
    goto switchD_006dc96b_caseD_40a;
  case 0x40b:
    uVar5 = 0x11;
    break;
  case 0x40c:
    goto switchD_006dc96b_caseD_40c;
  default:
    goto switchD_006dc96b_caseD_40d;
  case 0x40e:
    uVar5 = 0x14;
    break;
  case 0x410:
switchD_006dc96b_caseD_410:
    uVar5 = 5;
    break;
  case 0x411:
    FUN_004f5250(0);
    FUN_004f5270(1);
    goto LAB_006dccbf;
  case 0x412:
    uVar5 = 0xd;
    break;
  case 0x413:
switchD_006dc96b_caseD_413:
    uVar5 = 6;
    break;
  case 0x414:
    uVar5 = 0xf;
    break;
  case 0x415:
    uVar5 = 0xb;
    break;
  case 0x416:
    uVar5 = 0x10;
    break;
  case 0x419:
    uVar5 = 0xc;
    break;
  case 0x41d:
    uVar5 = 0xe;
  }
LAB_006dccb7:
  FUN_004f5250(uVar5);
LAB_006dccbf:
  if (DAT_02975c58 != 0) {
    GVar3 = GetUserGeoID(0x10);
    switch(GVar3) {
    case 0x27:
    case 0xa6:
    case 0xf4:
      uVar5 = 2;
      break;
    default:
      uVar5 = 3;
      break;
    case 0x7a:
      uVar5 = 1;
    }
    FUN_004f5270(uVar5);
  }
  FUN_004f5240();
  __security_check_cookie(local_4 ^ (uint)&local_110);
  return;
}

