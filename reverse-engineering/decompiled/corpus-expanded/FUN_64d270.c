/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64d270; label: FUN_0064d270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0064d270(undefined4 *param_1)

{
  float fVar1;
  undefined1 uVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 auStack_40 [16];
  
  local_4c = 0;
  local_48 = 0;
  local_44 = 0xbf800000;
  if (param_1[9] == 0) {
    if ((param_1[10] != -1) && (param_1[10] != 9999)) {
      return (undefined4 *)0x0;
    }
  }
  else {
    iVar5 = FUN_005cfac0(param_1[9]);
    if (iVar5 == 0) {
      return (undefined4 *)0x0;
    }
  }
  iVar5 = DAT_008102d8 * 0x220 + DAT_0291f664;
  iVar7 = 0;
  if ((*(byte *)(iVar5 + 0x144) & 1) != 0) {
    iVar7 = 0;
    do {
      if (((*(uint *)(iVar5 + 0x108) & 0x200) == 0) || (DAT_0081020c <= iVar7)) break;
      DAT_008102d8 = DAT_008102d8 + 1;
      if (DAT_008102d8 == DAT_0081020c) {
        DAT_008102d8 = 0;
      }
      iVar5 = DAT_008102d8 * 0x220 + DAT_0291f664;
      iVar7 = iVar7 + 1;
    } while ((*(byte *)(iVar5 + 0x144) & 1) != 0);
  }
  if (iVar7 == DAT_0081020c) {
    return (undefined4 *)0x0;
  }
  puVar9 = (undefined4 *)(DAT_008102d8 * 0x220 + DAT_0291f664);
  if ((*(byte *)(puVar9 + 0x51) & 1) != 0) {
    if ((code *)puVar9[0x73] != (code *)0x0) {
      (*(code *)puVar9[0x73])(puVar9);
    }
    FUN_0064ac90(puVar9,0);
  }
  if ((undefined4 *)*param_1 == (undefined4 *)0x0) {
    if (param_1[1] == 0) {
      return (undefined4 *)0x0;
    }
    FUN_005b4500(puVar9,param_1[1]);
  }
  else {
    puVar10 = (undefined4 *)*param_1;
    puVar11 = puVar9;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    puVar10 = (undefined4 *)*param_1;
    puVar11 = auStack_40;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    FUN_005b3200(&local_4c,&local_4c,auStack_40);
    uVar3 = FUN_005be2d0(local_4c,local_44);
    *(ushort *)((int)puVar9 + 0x13a) = uVar3;
    FUN_005b3620(&local_4c,&local_4c,-(uint)uVar3);
    sVar4 = FUN_005be2d0(local_48,local_44);
    *(short *)(puVar9 + 0x4e) = -sVar4;
  }
  puVar9[0x32] = puVar9[0xc];
  puVar9[0x33] = puVar9[0xd];
  puVar9[0x34] = puVar9[0xe];
  puVar9[0x35] = param_1[3];
  puVar9[0x36] = param_1[4];
  puVar10 = (undefined4 *)param_1[2];
  puVar9[0x20] = *puVar10;
  puVar9[0x21] = puVar10[1];
  puVar9[0x22] = puVar10[2];
  uVar6 = param_1[0x29];
  uVar8 = puVar9[0x51];
  *(undefined1 *)((int)puVar9 + 0x206) = 0xff;
  puVar9[0x41] = uVar6;
  *(undefined1 *)((int)puVar9 + 0x20b) = 0xff;
  puVar9[0x40] = uVar6;
  puVar9[0x3f] = 0;
  puVar9[0x3e] = param_1[0x23];
  puVar9[0x51] = uVar8 & 0xffffffbf | 0x20;
  fVar1 = (float)param_1[5];
  puVar9[0x37] = fVar1;
  puVar9[0x38] = ((float)puVar9[0x3e] / _DAT_008102e4) * fVar1;
  puVar9[0x39] = param_1[6];
  puVar9[0x85] = param_1[0x30];
  puVar9[0x3a] = param_1[7];
  puVar9[0x3b] = param_1[8];
  puVar9[0x3c] = param_1[0x22];
  *(undefined2 *)((int)puVar9 + 0x13e) = *(undefined2 *)(param_1 + 10);
  puVar9[0x51] = uVar8 & 0xffffffbd | 0x21;
  puVar9[0x42] = param_1[0xb];
  *(undefined1 *)((int)puVar9 + 0x20a) = *(undefined1 *)(param_1 + 0x31);
  puVar9[0x51] = uVar8 & 0xffffbfbd | 0x21;
  iVar5 = param_1[0x25];
  if (iVar5 == 0) {
    puVar9[0x51] = uVar8 & 0xffffbfb5 | 0x21;
    if ((((float)param_1[0x26] == 1.0) && ((float)param_1[0x27] == 1.0)) &&
       ((float)param_1[0x28] == 1.0)) {
      uVar8 = uVar8 & 0xffff9fb5 | 0x21;
    }
    else {
      puVar9[0x68] = param_1[0x26];
      puVar9[0x69] = param_1[0x27];
      puVar9[0x6a] = param_1[0x28];
      uVar8 = uVar8 & 0xffffbfb5 | 0x2021;
    }
  }
  else {
    puVar9[0x56] = *(undefined4 *)(iVar5 + 0x78);
    puVar9[0x57] = *(undefined4 *)(iVar5 + 0x7c);
    puVar9[0x58] = *(undefined4 *)(iVar5 + 0x80);
    iVar5 = param_1[0x25];
    puVar9[0x5f] = *(undefined4 *)(iVar5 + 0x9c);
    puVar9[0x60] = *(undefined4 *)(iVar5 + 0xa0);
    puVar9[0x61] = *(undefined4 *)(iVar5 + 0xa4);
    iVar5 = param_1[0x25];
    puVar9[0x59] = *(undefined4 *)(iVar5 + 0x84);
    puVar9[0x5a] = *(undefined4 *)(iVar5 + 0x88);
    puVar9[0x5b] = *(undefined4 *)(iVar5 + 0x8c);
    iVar5 = param_1[0x25];
    puVar9[0x62] = *(undefined4 *)(iVar5 + 0xa8);
    puVar9[99] = *(undefined4 *)(iVar5 + 0xac);
    puVar9[100] = *(undefined4 *)(iVar5 + 0xb0);
    iVar5 = param_1[0x25];
    puVar9[0x5c] = *(undefined4 *)(iVar5 + 0x90);
    puVar9[0x5d] = *(undefined4 *)(iVar5 + 0x94);
    puVar9[0x5e] = *(undefined4 *)(iVar5 + 0x98);
    iVar5 = param_1[0x25];
    puVar9[0x65] = *(undefined4 *)(iVar5 + 0xb4);
    puVar9[0x66] = *(undefined4 *)(iVar5 + 0xb8);
    puVar9[0x67] = *(undefined4 *)(iVar5 + 0xbc);
    iVar5 = param_1[0x25];
    puVar9[0x68] = *(undefined4 *)(iVar5 + 0xc0);
    puVar9[0x69] = *(undefined4 *)(iVar5 + 0xc4);
    puVar9[0x6a] = *(undefined4 *)(iVar5 + 200);
    uVar8 = uVar8 & 0xffffbfbd | 0x29;
  }
  puVar9[0x51] = uVar8;
  puVar10 = (undefined4 *)param_1[9];
  puVar9[0x55] = puVar10;
  if (puVar10 == (undefined4 *)0x0) {
    uVar6 = 0;
    puVar9[0x52] = 0;
    puVar9[0x53] = 0;
  }
  else {
    puVar9[0x52] = *puVar10;
    puVar9[0x53] = puVar10[1];
    uVar6 = puVar10[2];
  }
  puVar9[0x54] = uVar6;
  puVar9[0x3d] = 0;
  puVar9[0x51] = puVar9[0x51] & 0xffffffeb;
  puVar9[0x23] = (float)puVar9[0xc] - (float)puVar9[0x37];
  puVar9[0x26] = (float)puVar9[0x37] + (float)puVar9[0xc];
  puVar9[0x24] = (float)puVar9[0xd] - (float)puVar9[0x37];
  puVar9[0x27] = (float)puVar9[0x37] + (float)puVar9[0xd];
  puVar9[0x25] = (float)puVar9[0xe] - (float)puVar9[0x37];
  puVar9[0x28] = (float)puVar9[0x37] + (float)puVar9[0xe];
  puVar9[0x6b] = param_1[0xc];
  puVar9[0x6c] = param_1[0xd];
  puVar9[0x6d] = param_1[0xe];
  puVar9[0x6e] = param_1[0xf];
  puVar9[0x6f] = param_1[0x10];
  puVar9[0x70] = param_1[0x11];
  puVar9[0x71] = param_1[0x12];
  puVar9[0x72] = param_1[0x13];
  puVar9[0x73] = param_1[0x14];
  puVar9[0x74] = param_1[0x15];
  puVar9[0x43] = param_1[0x2a];
  puVar9[0x44] = param_1[0x2b];
  puVar9[0x45] = param_1[0x2c];
  puVar9[0x46] = param_1[0x2d];
  puVar9[0x47] = param_1[0x2e];
  puVar9[0x48] = param_1[0x2f];
  puVar9[0x49] = 0;
  puVar9[0x4a] = 0;
  puVar9[0x4b] = 0;
  puVar9[0x4c] = 0;
  puVar9[0x4d] = 0;
  if ((*(byte *)(puVar9 + 0x42) & 0x80) != 0) {
    FUN_0064a740(puVar9);
  }
  if ((puVar9[0x42] & 0x100000) != 0) {
    FUN_0064a7c0(puVar9);
  }
  if (param_1[0x16] == -1) {
    puVar9[0x76] = param_1[0x17];
  }
  else {
    puVar9[0x75] = 0xffffffff;
    puVar9[0x76] = puVar9 + 0x75;
    if ((float)param_1[0x1f] == 1.0) {
      uVar6 = param_1[0x16];
    }
    else {
      uVar6 = FUN_00684790(param_1[0x16],param_1[0x1f]);
    }
    FUN_00684ee0(puVar9[0x76],uVar6,puVar9[0xc],puVar9[0xd],puVar9[0xe]);
    FUN_00685340(*(undefined4 *)puVar9[0x76],0);
  }
  puVar9[0x78] = param_1[0x18];
  puVar9[0x7a] = param_1[0x1a];
  puVar9[0x79] = param_1[0x19];
  puVar9[0x7b] = param_1[0x1b];
  puVar9[0x7c] = param_1[0x1c];
  puVar9[0x7e] = param_1[0x1d];
  puVar9[0x7d] = param_1[0x1e];
  puVar9[0x7f] = param_1[0x1f];
  puVar10 = puVar9;
  puVar11 = puVar9 + 0x10;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar11 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar11 = puVar11 + 1;
  }
  puVar9[0x84] = 0;
  *(undefined1 *)(puVar9 + 0x82) = 1;
  puVar9[0x86] = 0;
  puVar9[0x87] = 0;
  uVar2 = *(undefined1 *)(param_1 + 0x24);
  puVar9[0x51] = puVar9[0x51] | 0x1800;
  *(undefined1 *)((int)puVar9 + 0x207) = uVar2;
  *(undefined2 *)(puVar9 + 0x81) = 1;
  if ((((puVar9[0x42] & 0x2000) != 0) && (param_1[0x20] != 0)) && (DAT_02920a8c != 0)) {
    puVar9[0x77] = param_1[0x20];
    uVar6 = FUN_00635790(DAT_02920a8c,param_1[0x21]);
    *(undefined4 *)param_1[0x20] = uVar6;
  }
  DAT_008102d8 = DAT_008102d8 + 1;
  if (DAT_008102d8 == DAT_0081020c) {
    DAT_008102d8 = 0;
  }
  return puVar9;
}

