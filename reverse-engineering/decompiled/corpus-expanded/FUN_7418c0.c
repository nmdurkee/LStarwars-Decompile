/* Ghidra pseudocode, not original source.
 * ev_d6810b63b1adbb1cff68d70c4de6dcedf5c7ec9f8161f7a4b49c43fe0c68c9ee
 * Entry: 0x7418c0; label: FUN_007418c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_007418c0(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char local_e5;
  short local_e4 [2];
  undefined1 local_e0 [4];
  short local_dc [2];
  undefined1 local_d8 [4];
  short asStack_d4 [2];
  undefined1 auStack_d0 [172];
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint *local_14;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  iVar2 = DAT_0297cc70;
  local_e5 = '\0';
  local_14 = param_1;
  local_10 = 0;
  local_14 = (uint *)FUN_00741860(&local_14,&DAT_0297cc78,DAT_0297cc70,&local_e5);
  if (local_e5 != '\0') {
    return local_14[1];
  }
  FUN_004ef660(local_14 + 2,local_14,(iVar2 - ((int)(local_14 + -0xa5f31e) >> 3)) * 8);
  puVar1 = local_14;
  DAT_0297cc70 = DAT_0297cc70 + 1;
  if ((((uint)param_1 & 8) == 0) && (((uint)param_1 & 0x880000) == 0)) {
    uVar5 = (uint)param_1 >> 2 & 1;
  }
  else {
    uVar5 = 2;
  }
  if ((((uint)param_1 & 0x20) == 0) && (((uint)param_1 & 0x1000000) == 0)) {
    uVar7 = (uint)param_1 >> 4 & 1;
  }
  else {
    uVar7 = 2;
  }
  if (((char)param_1 < '\0') || (((uint)param_1 & 0x2000000) != 0)) {
    local_20 = 2;
  }
  else {
    local_20 = (uint)param_1 >> 6 & 1;
  }
  local_8 = (uint)param_1 >> 8 & 1;
  if (((uint)param_1 >> 0x1b & 1) == 0) {
    uVar6 = (uint)param_1 >> 0xb & 7;
    local_18 = 0;
  }
  else {
    uVar6 = 0;
    local_18 = (uint)param_1 >> 0xb & 7;
  }
  if (((uint)param_1 & 0x8000) == 0) {
    local_1c = (uint)param_1 >> 0xe & 1;
  }
  else {
    local_1c = 2;
  }
  if (((uint)param_1 & 0x20000) == 0) {
    local_24 = (uint)param_1 >> 0x10 & 1;
  }
  else {
    local_24 = 2;
  }
  local_c = (uint)param_1 >> 0x1a & 1;
  local_4 = (uint)param_1 >> 0x16 & 1;
  iVar2 = 1;
  local_e4[0] = 0;
  local_e4[1] = 0;
  local_e0[0] = 2;
  local_e0[1] = 0;
  local_e0[2] = 0;
  local_e0[3] = 0;
  sVar4 = 0xc;
  if (uVar5 == 1) {
    iVar2 = 2;
    local_dc[1] = 0xc;
    local_dc[0] = 0;
    local_d8[0] = 2;
    local_d8[1] = 0;
    local_d8[2] = 3;
    local_d8[3] = 0;
    sVar4 = 0x18;
  }
  else if (uVar5 == 2) {
    local_dc[0] = 0;
    local_dc[1] = 0xc;
    local_d8[1] = 0;
    local_d8[2] = 3;
    local_d8[3] = 0;
    iVar2 = 2;
    local_d8[0] = 8;
    if (DAT_02974d1c < 2) {
      local_d8[0] = 4;
    }
    sVar4 = 0x10;
  }
  if (uVar7 == 1) {
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 2;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 6;
    local_e0[iVar2 * 8 + 3] = 0;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 0xc;
  }
  else if (uVar7 == 2) {
    local_e4[iVar2 * 4] = 0;
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 6;
    local_e0[iVar2 * 8 + 3] = 0;
    if (DAT_02974d1c < 2) {
      local_e0[iVar2 * 8] = 4;
      iVar2 = iVar2 + 1;
      sVar4 = sVar4 + 4;
    }
    else {
      local_e0[iVar2 * 8] = 8;
      iVar2 = iVar2 + 1;
      sVar4 = sVar4 + 4;
    }
  }
  if (local_20 == 1) {
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 2;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 6;
    local_e0[iVar2 * 8 + 3] = 1;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 0xc;
  }
  else if (local_20 == 2) {
    local_e4[iVar2 * 4] = 0;
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 6;
    local_e0[iVar2 * 8 + 3] = 1;
    if (DAT_02974d1c < 2) {
      local_e0[iVar2 * 8] = 4;
      iVar2 = iVar2 + 1;
      sVar4 = sVar4 + 4;
    }
    else {
      local_e0[iVar2 * 8] = 8;
      iVar2 = iVar2 + 1;
      sVar4 = sVar4 + 4;
    }
  }
  if (local_8 != 0) {
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 4;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 10;
    local_e0[iVar2 * 8 + 3] = 0;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 4;
  }
  if (((uint)param_1 & 0x600) != 0) {
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 4;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 10;
    local_e0[iVar2 * 8 + 3] = 1;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 4;
  }
  switch(uVar6) {
  case 1:
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 1;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 5;
    local_e0[iVar2 * 8 + 3] = 0;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 8;
    break;
  case 2:
    local_e0[iVar2 * 8 + 3] = 0;
    goto LAB_00741ca0;
  case 3:
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 3;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 5;
    local_e0[iVar2 * 8 + 3] = 0;
    iVar3 = iVar2 + 1;
    *(short *)(local_e0 + iVar3 * 8 + -2) = sVar4 + 0x10;
    local_e4[iVar3 * 4] = 0;
    local_e0[iVar3 * 8] = 1;
    local_e0[iVar3 * 8 + 1] = 0;
    local_e0[iVar3 * 8 + 2] = 5;
    local_e0[iVar3 * 8 + 3] = 1;
    iVar2 = iVar2 + 2;
    sVar4 = sVar4 + 0x18;
    break;
  case 4:
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 3;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 5;
    local_e0[iVar2 * 8 + 3] = 0;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 0x10;
    local_e0[iVar2 * 8 + 3] = 1;
LAB_00741ca0:
    local_e4[iVar2 * 4] = 0;
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e0[iVar2 * 8] = 3;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 5;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 0x10;
  }
  switch(local_18) {
  case 1:
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 0xf;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 5;
    local_e0[iVar2 * 8 + 3] = 0;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 4;
    break;
  case 2:
    local_e0[iVar2 * 8 + 3] = 0;
    goto LAB_00741d6e;
  case 3:
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 0x10;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 5;
    local_e0[iVar2 * 8 + 3] = 0;
    iVar3 = iVar2 + 1;
    *(short *)(local_e0 + iVar3 * 8 + -2) = sVar4 + 8;
    local_e4[iVar3 * 4] = 0;
    local_e0[iVar3 * 8] = 0xf;
    local_e0[iVar3 * 8 + 1] = 0;
    local_e0[iVar3 * 8 + 2] = 5;
    local_e0[iVar3 * 8 + 3] = 1;
    iVar2 = iVar2 + 2;
    sVar4 = sVar4 + 0xc;
    break;
  case 4:
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 0x10;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 5;
    local_e0[iVar2 * 8 + 3] = 0;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 8;
    local_e0[iVar2 * 8 + 3] = 1;
LAB_00741d6e:
    local_e4[iVar2 * 4] = 0;
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e0[iVar2 * 8] = 0x10;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 5;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 8;
  }
  if (local_1c == 1) {
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 1;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 1;
    local_e0[iVar2 * 8 + 3] = 0;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 8;
  }
  else if (local_1c == 2) {
    local_e4[iVar2 * 4] = 0;
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 1;
    local_e0[iVar2 * 8 + 3] = 0;
    if (DAT_02974d1c < 2) {
      local_e0[iVar2 * 8] = 4;
      iVar2 = iVar2 + 1;
      sVar4 = sVar4 + 4;
    }
    else {
      local_e0[iVar2 * 8] = 8;
      iVar2 = iVar2 + 1;
      sVar4 = sVar4 + 4;
    }
  }
  if (local_24 == 1) {
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e4[iVar2 * 4] = 0;
    local_e0[iVar2 * 8] = 2;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 2;
    local_e0[iVar2 * 8 + 3] = 0;
    iVar2 = iVar2 + 1;
    sVar4 = sVar4 + 0xc;
  }
  else if (local_24 == 2) {
    local_e4[iVar2 * 4] = 0;
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 2;
    local_e0[iVar2 * 8 + 3] = 0;
    if (DAT_02974d1c < 2) {
      local_e0[iVar2 * 8] = 4;
      iVar2 = iVar2 + 1;
      sVar4 = sVar4 + 4;
    }
    else {
      local_e0[iVar2 * 8] = 5;
      iVar2 = iVar2 + 1;
      sVar4 = sVar4 + 4;
    }
  }
  if (local_c != 0) {
    local_e4[iVar2 * 4] = 0;
    *(short *)(local_e0 + iVar2 * 8 + -2) = sVar4;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 5;
    local_e0[iVar2 * 8 + 3] = 6;
    if (DAT_02974d1c < 2) {
      local_e0[iVar2 * 8] = 4;
    }
    else {
      local_e0[iVar2 * 8] = 8;
    }
    iVar3 = iVar2 + 1;
    local_e4[iVar3 * 4] = 0;
    *(short *)(local_e0 + iVar3 * 8 + -2) = sVar4 + 4;
    local_e0[iVar3 * 8] = 4;
    local_e0[iVar3 * 8 + 1] = 0;
    local_e0[iVar3 * 8 + 2] = 5;
    local_e0[iVar3 * 8 + 3] = 7;
    iVar2 = iVar2 + 2;
  }
  if (local_4 == 1) {
    local_e4[iVar2 * 4] = 1;
    *(undefined2 *)(local_e0 + iVar2 * 8 + -2) = 0;
    local_e0[iVar2 * 8] = 2;
    local_e0[iVar2 * 8 + 1] = 0;
    local_e0[iVar2 * 8 + 2] = 0;
    local_e0[iVar2 * 8 + 3] = 1;
    iVar2 = iVar2 + 1;
  }
  iVar3 = iVar2 * 8;
  local_e4[iVar2 * 4] = 0xff;
  *(undefined2 *)(local_e0 + iVar3 + -2) = 0;
  local_e0[iVar3] = 0x11;
  local_e0[iVar3 + 1] = 0;
  local_e0[iVar3 + 2] = 0;
  local_e0[iVar3 + 3] = 0;
  *local_14 = (uint)param_1;
  FUN_006e4850(local_e4,local_14 + 1);
  return puVar1[1];
}

