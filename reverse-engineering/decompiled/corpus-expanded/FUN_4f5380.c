/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5380; label: FUN_004f5380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f5380(void)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int extraout_ECX;
  int extraout_ECX_00;
  code *extraout_ECX_01;
  code *pcVar7;
  undefined4 *unaff_ESI;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  cVar1 = *(char *)(unaff_ESI[2] + unaff_ESI[3]);
  while( true ) {
    if (cVar1 == '\0') {
      *unaff_ESI = 7;
      __security_check_cookie(local_4 ^ (uint)local_104);
      return;
    }
    iVar4 = unaff_ESI[2];
    cVar1 = *(char *)(unaff_ESI[3] + iVar4);
    pcVar3 = (char *)(unaff_ESI[3] + iVar4);
    if ((cVar1 != ' ') && (cVar1 != '\t')) break;
    *pcVar3 = *pcVar3 + '\x01';
    cVar1 = *(char *)(unaff_ESI[2] + unaff_ESI[3]);
  }
  iVar6 = unaff_ESI[3];
  iVar5 = unaff_ESI[2];
  switch(*(undefined1 *)(iVar5 + iVar6)) {
  case 0x21:
    *unaff_ESI = 0xf;
    unaff_ESI[3] = iVar6 + 1;
    if (*(char *)(iVar6 + 1 + iVar5) == '=') {
      *unaff_ESI = 0x11;
      unaff_ESI[3] = iVar6 + 2;
      __security_check_cookie(local_4 ^ (uint)local_104);
      return;
    }
    break;
  case 0x24:
    iVar6 = iVar6 + 1;
    unaff_ESI[3] = iVar6;
    *unaff_ESI = 8;
    unaff_ESI[1] = 0;
    iVar4 = FUN_004f52a0();
    while (iVar4 != 0) {
      iVar4 = unaff_ESI[1];
      unaff_ESI[1] = iVar4 * 0x10;
      iVar5 = FUN_004f5310();
      unaff_ESI[1] = iVar5 + iVar4 * 0x10;
      iVar6 = iVar6 + 1;
      unaff_ESI[3] = iVar6;
      iVar4 = FUN_004f52a0();
    }
    break;
  case 0x25:
    *unaff_ESI = 4;
    unaff_ESI[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  case 0x26:
    *unaff_ESI = 10;
    unaff_ESI[3] = iVar6 + 1;
    if (*(char *)(iVar6 + 1 + iVar5) == '&') {
      *unaff_ESI = 0xe;
      unaff_ESI[3] = iVar6 + 2;
      __security_check_cookie(local_4 ^ (uint)local_104);
      return;
    }
    break;
  case 0x28:
    *unaff_ESI = 5;
    unaff_ESI[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  case 0x29:
    *unaff_ESI = 6;
    unaff_ESI[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  case 0x2a:
    *unaff_ESI = 2;
    unaff_ESI[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  case 0x2b:
    *unaff_ESI = 0;
    unaff_ESI[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  case 0x2d:
    *unaff_ESI = 1;
    unaff_ESI[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  case 0x2f:
    *unaff_ESI = 3;
    unaff_ESI[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    *unaff_ESI = 8;
    unaff_ESI[1] = 0;
    while (iVar4 = unaff_ESI[3], (byte)(*(char *)(iVar5 + iVar4) - 0x30U) < 10) {
      iVar6 = unaff_ESI[1];
      unaff_ESI[1] = iVar6 * 10;
      unaff_ESI[1] = *(char *)(iVar5 + iVar4) + -0x30 + iVar6 * 10;
      unaff_ESI[3] = iVar4 + 1;
    }
    break;
  case 0x3b:
    *unaff_ESI = 7;
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  case 0x3c:
    *unaff_ESI = 0x12;
    unaff_ESI[3] = iVar6 + 1;
    if (*(char *)(iVar6 + 1 + iVar5) == '=') {
      unaff_ESI[3] = iVar6 + 2;
      *unaff_ESI = 0x14;
      __security_check_cookie(local_4 ^ (uint)local_104);
      return;
    }
    break;
  case 0x3d:
    *unaff_ESI = 0x10;
    unaff_ESI[3] = iVar6 + 1;
    if (*(char *)(iVar6 + 1 + iVar5) == '=') {
      unaff_ESI[3] = iVar6 + 2;
      __security_check_cookie(local_4 ^ (uint)local_104);
      return;
    }
    break;
  case 0x3e:
    *unaff_ESI = 0x13;
    unaff_ESI[3] = iVar6 + 1;
    if (*(char *)(iVar6 + 1 + iVar5) == '=') {
      unaff_ESI[3] = iVar6 + 2;
      *unaff_ESI = 0x15;
      __security_check_cookie(local_4 ^ (uint)local_104);
      return;
    }
    break;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
    iVar6 = FUN_004f2770(CONCAT31((int3)((uint)iVar4 >> 8),*(undefined1 *)(iVar5 + iVar6)));
    iVar4 = extraout_ECX;
    while (iVar6 != 0) {
      uVar2 = *(undefined1 *)(iVar5 + unaff_ESI[3]);
      unaff_ESI[3] = unaff_ESI[3] + 1;
      iVar6 = unaff_ESI[2];
      local_104[iVar4] = uVar2;
      iVar6 = FUN_004f2770(*(undefined1 *)(iVar6 + unaff_ESI[3]));
      iVar4 = extraout_ECX_00;
    }
    local_104[iVar4] = 0;
    pcVar7 = (code *)unaff_ESI[4];
    if (pcVar7 == (code *)0x0) {
      FUN_004ef790(local_104);
      pcVar7 = extraout_ECX_01;
    }
    unaff_ESI[1] = 0;
    *unaff_ESI = 8;
    (*pcVar7)(local_104,0,unaff_ESI + 1);
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  case 0x5e:
    *unaff_ESI = 0xc;
    unaff_ESI[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  case 0x7c:
    *unaff_ESI = 9;
    unaff_ESI[3] = iVar6 + 1;
    if (*(char *)(iVar6 + 1 + iVar5) == '|') {
      *unaff_ESI = 0xd;
      unaff_ESI[3] = iVar6 + 2;
      __security_check_cookie(local_4 ^ (uint)local_104);
      return;
    }
    break;
  case 0x7e:
    *unaff_ESI = 0xb;
    unaff_ESI[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

