/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f8420; label: FUN_004f8420
 */

void FUN_004f8420(void)

{
  float fVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *in_ECX;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  undefined4 *extraout_ECX_02;
  undefined4 *puVar7;
  code *extraout_EDX;
  code *pcVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 extraout_ST1;
  float10 fVar13;
  float local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  cVar2 = *(char *)(in_ECX[2] + in_ECX[3]);
  while( true ) {
    if (cVar2 == '\0') {
      *in_ECX = 6;
      __security_check_cookie(local_4 ^ (uint)&local_108);
      return;
    }
    pcVar5 = (char *)(in_ECX[2] + in_ECX[3]);
    if ((*pcVar5 != ' ') && (*pcVar5 != '\t')) break;
    *pcVar5 = *pcVar5 + '\x01';
    cVar2 = *(char *)(in_ECX[2] + in_ECX[3]);
  }
  iVar6 = in_ECX[3];
  iVar4 = in_ECX[2];
  switch(*(undefined1 *)(iVar4 + iVar6)) {
  case 0x28:
    *in_ECX = 4;
    in_ECX[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)&local_108);
    return;
  case 0x29:
    *in_ECX = 5;
    in_ECX[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)&local_108);
    return;
  case 0x2a:
    *in_ECX = 2;
    in_ECX[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)&local_108);
    return;
  case 0x2b:
    *in_ECX = 0;
    in_ECX[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)&local_108);
    return;
  case 0x2d:
    *in_ECX = 1;
    in_ECX[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)&local_108);
    return;
  case 0x2e:
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
    fVar13 = (float10)0;
    *in_ECX = 7;
    in_ECX[1] = (float)fVar13;
    local_108 = (float)fVar13;
    fVar10 = (float10)0.1;
    fVar11 = (float10)10.0;
    fVar12 = (float10)local_108;
    while( true ) {
      iVar6 = in_ECX[3];
      cVar2 = *(char *)(iVar4 + iVar6);
      if (((cVar2 < '0') || ('9' < cVar2)) && (cVar2 != '.')) break;
      if (cVar2 == '.') {
        if (fVar13 != fVar12) {
          fVar11 = (float10)FUN_004ef790();
          in_ECX = extraout_ECX;
          fVar10 = extraout_ST1;
        }
        local_108 = (float)fVar10;
        in_ECX[3] = iVar6 + 1;
        fVar12 = (float10)local_108;
      }
      else if (fVar13 == fVar12) {
        fVar1 = (float)in_ECX[1];
        in_ECX[1] = (float)((float10)fVar1 * fVar11);
        local_108 = (float)(*(char *)(iVar4 + iVar6) + -0x30);
        in_ECX[3] = iVar6 + 1;
        in_ECX[1] = (float)((float10)fVar1 * fVar11) + (float)(int)local_108;
      }
      else {
        in_ECX[3] = iVar6 + 1;
        in_ECX[1] = (float)((float10)(cVar2 + -0x30) * fVar12 + (float10)(float)in_ECX[1]);
        local_108 = (float)(fVar12 / fVar11);
        fVar12 = (float10)local_108;
      }
    }
    break;
  case 0x2f:
    *in_ECX = 3;
    in_ECX[3] = iVar6 + 1;
    __security_check_cookie(local_4 ^ (uint)&local_108);
    return;
  case 0x3b:
    *in_ECX = 6;
    __security_check_cookie(local_4 ^ (uint)&local_108);
    return;
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
  case 0x5f:
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
    iVar9 = 0;
    iVar6 = FUN_004f2770(CONCAT31((int3)((uint)in_ECX[3] >> 8),*(undefined1 *)(iVar4 + iVar6)));
    puVar7 = extraout_ECX_00;
    while (iVar6 != 0) {
      uVar3 = *(undefined1 *)(iVar4 + puVar7[3]);
      puVar7[3] = puVar7[3] + 1;
      local_104[iVar9] = uVar3;
      iVar9 = iVar9 + 1;
      iVar6 = FUN_004f2770(*(undefined1 *)(iVar4 + puVar7[3]));
      puVar7 = extraout_ECX_01;
    }
    pcVar8 = (code *)puVar7[4];
    local_104[iVar9] = 0;
    if (pcVar8 == (code *)0x0) {
      FUN_004ef790(local_104);
      puVar7 = extraout_ECX_02;
      pcVar8 = extraout_EDX;
    }
    puVar7[1] = 0;
    *puVar7 = 7;
    (*pcVar8)(local_104,puVar7 + 1,0);
    __security_check_cookie(local_4 ^ (uint)&local_108);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

