/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f91f0; label: FUN_004f91f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f91f0(void)

{
  char cVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined1 auStack_e4 [4];
  float local_e0;
  float local_dc;
  uint local_d8;
  int local_d4;
  int local_d0;
  uint local_cc;
  int local_c8;
  int local_c4 [2];
  int local_bc;
  undefined1 local_b8 [112];
  byte local_48;
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)auStack_e4;
  bVar2 = true;
  _memset(local_b8,0,0xa4);
  FUN_004ffb20(&local_d8,&local_d4);
  if (local_d4 < 0) {
    FUN_004ef790();
  }
  do {
    if (!bVar2) break;
    local_dc = 500.0;
    iVar8 = 0;
    FUN_004ffb20(&local_cc,&local_c8);
    iVar6 = local_c8;
    if (local_c8 < 0) {
      iVar6 = FUN_004ef790();
    }
    if (local_cc < local_d8) {
      local_bc = (iVar6 - local_d4) + -1;
    }
    else {
      local_bc = iVar6 - local_d4;
    }
    iVar6 = local_cc - local_d8;
    FUN_004ffb90(&local_d0,local_c4);
    fVar5 = (float)iVar6;
    if (iVar6 < 0) {
      fVar5 = fVar5 + 4.2949673e+09;
    }
    fVar3 = (float)local_c4[0];
    if (local_c4[0] < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    fVar4 = (float)local_d0;
    if (local_d0 < 0) {
      fVar4 = fVar4 + 4.2949673e+09;
    }
    local_e0 = ((fVar5 + (float)local_bc * 4.2949673e+09) / (fVar4 + fVar3 * 4.2949673e+09)) *
               1000.0;
    iVar6 = 0;
    if (DAT_0297dbe4 != 0) {
      iVar6 = FUN_004ef790();
    }
    DAT_0297dbe4 = iVar6 + 1;
    if (DAT_0297dbe4 < 1) {
      FUN_004ef790();
    }
    FUN_005d9030();
    FUN_005f9530();
    FUN_006d58a0();
    FUN_006d9340();
    FUN_005e8430();
    FUN_005d4290(0);
    FUN_005ebd80(0xb00,0xff00ffff,0x3f800000);
    FUN_005d0fb0(DAT_009738b8);
    FUN_005d0880(2);
    FUN_005d0a40(1);
    FUN_005d0fb0(DAT_009738b8);
    pcVar7 = (char *)FUN_004fea50(0);
    cVar1 = *pcVar7;
    while (cVar1 != '\0') {
      iVar8 = iVar8 + 1;
      FUN_005d1060(DAT_009738b8,0xff000000);
      FUN_005eabb0(DAT_009738b8,0x43fa0000,local_dc,0);
      FUN_005f3580(DAT_009738b8,pcVar7,0);
      local_dc = local_dc + 150.0;
      pcVar7 = (char *)FUN_004fea50(iVar8);
      cVar1 = *pcVar7;
    }
    FUN_005d0a70();
    FUN_005d08c0();
    FUN_005f3950();
    FUN_004f49b0(local_b8);
    if (((local_48 & 0x40) != 0) && (1000.0 < local_e0)) {
      bVar2 = false;
    }
    FUN_004fd050();
  } while (local_e0 < 5000.0);
  __security_check_cookie(local_c ^ (uint)auStack_e4);
  return;
}

