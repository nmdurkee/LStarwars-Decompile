/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e5340; label: FUN_006e5340
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e5340(undefined4 param_1,int param_2)

{
  short sVar1;
  
  if (DAT_008282b4 != '\0') {
    switch(param_1) {
    case 7:
      sVar1 = 4;
      break;
    default:
      goto switchD_006e5362_caseD_8;
    case 0xe:
      sVar1 = 5;
      break;
    case 0xf:
      sVar1 = 8;
      break;
    case 0x13:
      sVar1 = 10;
      break;
    case 0x14:
      sVar1 = 0xb;
      break;
    case 0x16:
      sVar1 = 7;
      break;
    case 0x17:
      sVar1 = 6;
      break;
    case 0x1b:
      sVar1 = 9;
      break;
    case 0xa8:
      sVar1 = 0;
      break;
    case 0xbe:
      sVar1 = 1;
      break;
    case 0xbf:
      sVar1 = 2;
      break;
    case 0xc0:
      sVar1 = 3;
    }
    if ((&DAT_0297c098)[sVar1] == param_2) {
      return;
    }
    (&DAT_0297c098)[sVar1] = param_2;
  }
switchD_006e5362_caseD_8:
  _DAT_0297c094 = 0xffffffff;
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0xe4))(DAT_029765cc,param_1,param_2);
  return;
}

