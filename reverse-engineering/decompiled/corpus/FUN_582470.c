/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x582470; label: FUN_00582470
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00582470(int *param_1,int *param_2)

{
  float *pfVar1;
  float fVar2;
  uint uVar3;
  code *pcVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  float fVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  float10 fVar14;
  float local_f4;
  short local_f0 [2];
  float fStack_ec;
  float local_e8;
  undefined *local_e4;
  float local_e0;
  int local_dc;
  int local_d8 [3];
  float fStack_cc;
  int local_c8;
  int local_c4;
  int iStack_c0;
  int iStack_bc;
  undefined1 auStack_b8 [4];
  float fStack_b4;
  undefined1 auStack_ac [12];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined1 auStack_94 [12];
  int iStack_88;
  int iStack_84;
  int iStack_80;
  undefined1 auStack_7c [12];
  undefined1 auStack_70 [12];
  undefined1 local_64 [36];
  int local_40 [16];
  
  if (param_2[1] != 0) {
    FUN_004ef660(local_f0,param_2[2] + param_2[1],2);
    if (*param_2 != 0) {
      FUN_00621180(local_f0);
    }
    param_2[2] = param_2[2] + 2;
  }
  if (param_2[1] != 0) {
    FUN_004ef660(&local_c4,param_2[2] + param_2[1],0xc);
    if (*param_2 != 0) {
      piVar12 = &local_c4;
      iVar9 = 3;
      do {
        FUN_00621190(piVar12);
        piVar12 = piVar12 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    param_2[2] = param_2[2] + 0xc;
  }
  if (param_2[1] != 0) {
    FUN_004ef660(local_40,param_2[2] + param_2[1],0x40);
    if (*param_2 != 0) {
      piVar12 = local_40;
      iVar9 = 0x10;
      do {
        FUN_00621190(piVar12);
        piVar12 = piVar12 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    param_2[2] = param_2[2] + 0x40;
  }
  if (param_2[1] != 0) {
    FUN_004ef660(&local_dc,param_2[2] + param_2[1],4);
    if (*param_2 != 0) {
      FUN_00621190(&local_dc);
    }
    param_2[2] = param_2[2] + 4;
  }
  if (param_2[1] != 0) {
    FUN_004ef660(local_d8,param_2[2] + param_2[1],4);
    if (*param_2 != 0) {
      FUN_00621190(local_d8);
    }
    param_2[2] = param_2[2] + 4;
  }
  if (local_f0[0] < 0) {
    fVar10 = 0.0;
  }
  else {
    fVar10 = (float)(local_f0[0] * 0x10d8 + DAT_0093d504);
  }
  if ((local_dc < 0) || (*(int *)(PTR_PTR_008040bc + 4) <= local_dc)) {
    if ((PTR_DAT_00802c54 == (undefined *)0x0) ||
       ((iVar9 = *(int *)(PTR_PTR_008040bc + 4), local_dc < iVar9 || (iVar9 + 8 <= local_dc)))) {
      puVar5 = (undefined *)0x0;
    }
    else {
      puVar5 = PTR_DAT_00802c54 + (local_dc - iVar9) * 0xa4 + 0x4b14;
    }
  }
  else {
    puVar5 = (undefined *)(local_dc * 0xa4 + *(int *)PTR_PTR_008040bc);
  }
  local_a0 = DAT_0095e5c8;
  local_9c = DAT_0095e5cc;
  local_98 = DAT_0095e5d0;
  local_e8 = fVar10;
  local_e4 = puVar5;
  local_c8 = FUN_0055f450();
  iVar9 = DAT_009543ec;
  local_e0 = (float)DAT_009543e8;
  DAT_009543e8 = 0;
  DAT_009543ec = 0;
  DAT_00951cbc = -1;
  if (puVar5 == (undefined *)0x0) {
    DAT_00951cbc = -1;
    DAT_009543e8 = 0;
    DAT_009543ec = 0;
    return;
  }
  iVar6 = FUN_005cfac0(puVar5 + 0x68);
  if (iVar6 == 0) {
    return;
  }
  if ((char)param_1[0x40] != '\0') {
    FUN_0057fab0();
    (**(code **)(PTR_PTR_008040bc + 0xc))(param_1,local_64,0xffffffff,0,0);
  }
  *param_1 = (int)puVar5;
  *(undefined1 *)((int)param_1 + 0x101) = (undefined1)local_dc;
  if ((_DAT_009543f4 == 0.0) || (_DAT_009543f8 == 0.0)) {
    param_1[0x33] = *(int *)(puVar5 + 0x10);
    fVar2 = *(float *)(puVar5 + 0x14);
  }
  else {
    param_1[0x33] = (int)_DAT_009543f4;
    fVar2 = _DAT_009543f8;
  }
  param_1[0x34] = (int)fVar2;
  piVar12 = param_1 + -0x25473a;
  param_1[0x3b] = *(int *)(puVar5 + 0x18);
  param_1[0x35] = *(int *)(puVar5 + 0x1c);
  param_1[0x31] = *(int *)(puVar5 + 0x20);
  *(undefined2 *)(param_1 + 0x3f) = *(undefined2 *)(puVar5 + 0x2e);
  *(undefined2 *)((int)param_1 + 0xfe) = *(undefined2 *)(puVar5 + 0x38);
  *(char *)((int)param_1 + 0x103) =
       (char)((ulonglong)((longlong)(int)piVar12 * 0xd20d20d3) >> 0x28) -
       ((char)((int)piVar12 / -0x64000000) + (char)((int)piVar12 >> 0x1f));
  if (local_d8[0] == 0) {
    local_d8[0] = FUN_0058b720(fVar10);
  }
  *(short *)(param_1 + 0x3e) = (short)local_d8[0];
  *(ushort *)(param_1 + 0x3e) = *(ushort *)(param_1 + 0x3e) | 0x80;
  uVar8 = *(uint *)(puVar5 + 0x60);
  if (fVar10 == 0.0) {
LAB_00582856:
    DAT_00951cbc = (int)*(short *)(puVar5 + 100);
  }
  else {
    uVar3 = uVar8;
    if ((*(byte *)((int)fVar10 + 0x1fc) & 0x80) != 0) {
      if (*(char *)((int)fVar10 + 0x280) == '\0') {
        uVar3 = uVar8 | 0x29;
      }
      else {
        uVar3 = uVar8 | 0x28;
        if (*(char *)((int)fVar10 + 0x280) == '\x01') {
          uVar3 = uVar8 | 0x2a;
        }
      }
    }
    uVar8 = uVar3;
    if (((((DAT_009543f0 != (code *)0x0) &&
          (iVar6 = (*DAT_009543f0)(param_1,fVar10,&local_a0), iVar6 != 0)) ||
         (uVar3 = *(uint *)(*(int *)((int)fVar10 + 0x54) + 4), (uVar3 & 0x4000000) != 0)) ||
        (((*(byte *)((int)fVar10 + 0x1fc) & 0x80) != 0 && ((uVar3 & 0x2000) != 0)))) && (iVar9 == 0)
       ) {
      local_f4 = *(float *)((int)fVar10 + 0xf30) * *(float *)((int)fVar10 + 0x68) +
                 *(float *)((int)fVar10 + 0xf38) * *(float *)((int)fVar10 + 0x70);
      if (local_f4 < 0.0) {
        local_f4 = 0.0;
      }
      param_1[0x33] = (int)((float)param_1[0x33] + local_f4);
    }
    if (*(int *)((int)fVar10 + 0xcd0) != 0) {
      uVar8 = uVar8 | 0x40000;
    }
    if (((DAT_009543fc == (code *)0x0) ||
        (DAT_00951cbc = (*DAT_009543fc)(fVar10), DAT_00951cbc == -1)) &&
       (DAT_00951cbc = (int)*(short *)(*(int *)(*(int *)((int)fVar10 + 0x54) + 0x24) + 0xe4),
       DAT_00951cbc == -1)) goto LAB_00582856;
  }
  if ((local_e0 == 0.0) && (DAT_00951cbc != -1)) {
    FUN_005478a0(DAT_00951cbc,&local_c4,0,0);
  }
  DAT_00951cd8 = local_c4;
  DAT_00951cdc = iStack_c0;
  DAT_00951ce0 = iStack_bc;
  param_1[0x32] = 0;
  param_1[0x22] = local_c4;
  param_1[0x25] = local_c4;
  param_1[0x39] = 0x49f42400;
  param_1[0x23] = iStack_c0;
  param_1[0x3a] = 0x49f42400;
  param_1[0x26] = iStack_c0;
  param_1[1] = (int)fVar10;
  param_1[0x24] = iStack_bc;
  param_1[0x27] = iStack_bc;
  param_1[0x3c] = uVar8;
  *(undefined1 *)(param_1 + 0x40) = 1;
  *(undefined1 *)((int)param_1 + 0x102) = 0;
  *(undefined2 *)((int)param_1 + 0xfa) = 0xffff;
  *(undefined1 *)((int)param_1 + 0x105) = 0xff;
  if (fVar10 != 0.0) {
    if (*(float *)((int)fVar10 + 0x21c) != 2e+06) {
      param_1[0x39] = *(int *)((int)fVar10 + 0x21c);
      *(undefined2 *)(param_1 + 0x3d) = *(undefined2 *)((int)fVar10 + 0x1052);
      *(undefined2 *)((int)param_1 + 0xf6) = *(undefined2 *)((int)fVar10 + 0x1054);
    }
    if ((*(float *)((int)fVar10 + 0x1014) != 2e+06) && (*(char *)((int)fVar10 + 0x107b) == '\x02'))
    {
      param_1[0x3a] = *(int *)((int)fVar10 + 0x1014);
    }
  }
  if ((uVar8 & 0x200) == 0) {
    fVar10 = (float)param_1[0x35] * 0.33333334;
  }
  else {
    fVar10 = (float)param_1[0x35];
  }
  param_1[0x36] = (int)fVar10;
  piVar12 = param_1 + 0x28;
  param_1[0x35] = (int)((float)param_1[0x35] * (float)param_1[0x31]);
  param_1[0x36] = (int)((float)param_1[0x31] * (float)param_1[0x36]);
  param_1[0x29] = 0;
  *piVar12 = 0;
  param_1[0x2a] = param_1[0x33];
  FUN_005b45f0(param_1 + 0x12,0x4000);
  piVar11 = local_40;
  piVar13 = param_1 + 2;
  for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
    *piVar13 = *piVar11;
    piVar11 = piVar11 + 1;
    piVar13 = piVar13 + 1;
  }
  FUN_005b3200(piVar12,piVar12,param_1 + 2);
  FUN_005b37d0(piVar12,piVar12,&local_a0);
  piVar11 = param_1 + 0x2b;
  FUN_005b3b30(piVar11,piVar12);
  if ((param_1[0x3c] & 0x1000U) == 0) {
    FUN_005b5700(param_1 + 0x12,param_1 + 0x12,param_1 + 2);
  }
  else {
    FUN_0057fb30();
  }
  iStack_88 = param_1[0x22];
  iStack_84 = param_1[0x23];
  iStack_80 = param_1[0x24];
  pfVar1 = (float *)(param_1 + 0x22);
  if ((param_1[0x3c] & 0x200U) == 0) {
    local_d8[2] = 0;
    local_d8[1] = 0;
    fStack_cc = (float)param_1[0x36] + (float)param_1[0x36];
    FUN_005b3200(local_d8 + 1,local_d8 + 1,param_1 + 2);
    FUN_005b3800(auStack_94,pfVar1,local_d8 + 1);
    FUN_005b37d0(auStack_7c,pfVar1,local_d8 + 1);
  }
  param_1[0x42] = (int)(*pfVar1 - (float)param_1[0x35]);
  param_1[0x43] = (int)((float)param_1[0x23] - (float)param_1[0x35]);
  param_1[0x44] = (int)((float)param_1[0x24] - (float)param_1[0x35]);
  param_1[0x45] = (int)((float)param_1[0x35] + *pfVar1);
  param_1[0x46] = (int)((float)param_1[0x35] + (float)param_1[0x23]);
  param_1[0x47] = (int)((float)param_1[0x35] + (float)param_1[0x24]);
  fStack_ec = (float)param_1[0x34] * (float)param_1[0x33];
  local_e0 = (float)param_1[0x33] * 0.2;
  FUN_005b3830(auStack_b8,piVar11,local_e0);
  if ((float)param_1[0x3b] != 0.0) {
    fStack_b4 = (float)param_1[0x29] * 0.2 + (float)param_1[0x3b] * 0.5 * 0.040000003;
  }
  if (local_e8 == 0.0) {
    fVar10 = 0.01;
  }
  else if (((*(uint *)(*(int *)((int)local_e8 + 0x54) + 4) & 0x2000) == 0) &&
          ((*(byte *)(*(int *)(*(int *)((int)local_e8 + 0x54) + 0x24) + 0x90) & 0x80) == 0)) {
    fVar10 = *(float *)((int)local_e8 + 0xac) * 3.0;
  }
  else {
    fVar10 = *(float *)((int)local_e8 + 0xac);
  }
  FUN_005b3830(auStack_70,piVar11,fVar10);
  FUN_005b3800(auStack_ac,pfVar1,auStack_70);
  FUN_005b37d0(auStack_b8,auStack_b8,auStack_70);
  param_1[0x38] = param_1[0x36];
  param_1[0x37] = 0x3e4ccccd;
  if (((*(byte *)(param_1 + 0x3c) & 4) != 0) || (iVar9 = FUN_0057f9a0(auStack_ac), iVar9 == 0))
  goto LAB_00582e4b;
  local_e8 = (fVar10 / fStack_ec) * (float)param_1[0x34];
  param_1[0x34] = (int)((float)param_1[0x37] + local_e8);
  fVar14 = (float10)FUN_0067b200();
  fStack_ec = (float)(fVar14 * (float10)(float)param_1[0x34]) - local_e8;
  param_1[0x34] = (int)fStack_ec;
  if (0.0 < fStack_ec) goto LAB_00582e4b;
  FUN_005b37d0(auStack_ac,auStack_ac,auStack_b8);
  iVar9 = local_c8;
  FUN_0062c560(*(undefined4 *)(local_c8 + 0x134),(int)(short)param_1[0x3f],auStack_ac);
  FUN_0062c560(*(undefined4 *)(iVar9 + 0x134),(int)(short)param_1[0x3f],pfVar1);
  *(undefined1 *)(param_1 + 0x40) = 0;
  if ((*param_1 != 0) && (pcVar4 = *(code **)(*param_1 + 0x4c), pcVar4 != (code *)0x0)) {
    (*pcVar4)(param_1);
  }
  if (((param_1[0x3c] & 0x10000U) != 0) ||
     (iVar6 = FUN_00582270(param_1,auStack_94,param_1 + 0x42,param_1 + 0x45,param_1[0x36],0),
     iVar6 != 0)) goto LAB_00582e4b;
  if (((*(byte *)(param_1 + 0x3c) & 0x13) == 0) &&
     ((iVar6 = param_1[1], iVar6 == 0 ||
      (((*(uint *)(iVar6 + 0xeec) & 0x10000000) == 0 && (*(char *)(iVar6 + 0xf00) != '\x05')))))) {
LAB_00582e1c:
    FUN_0057fe80(param_1);
  }
  else if (((*(short *)((int)param_1 + 0xfa) == -1) || (iVar6 = FUN_00580f50(0), iVar6 == 0)) &&
          (iVar9 = FUN_0046a6d0(*(undefined4 *)(iVar9 + 0x2ac8),iVar9,param_1,auStack_94,
                                param_1 + 0x42,param_1 + 0x45,param_1[0x36],0), iVar9 == 0)) {
    iVar9 = FUN_00581110(param_1 + 0x42,param_1 + 0x45,param_1[0x36]);
    if (iVar9 == 0) {
      uVar7 = FUN_005809e0(param_1);
      iVar9 = FUN_00580a10(param_1,auStack_94,param_1 + 0x42,param_1 + 0x45,param_1[0x36],uVar7);
      if (iVar9 == 0) goto LAB_00582e1c;
    }
  }
  if (((*(int *)(PTR_PTR_008040bc + 8) != 0) && (iVar9 = param_1[1], iVar9 != 0)) &&
     ((*(byte *)(iVar9 + 0x1fc) & 0x80) != 0)) {
    (**(code **)(PTR_PTR_008040bc + 8))(iVar9,pfVar1);
  }
LAB_00582e4b:
  if (*(code **)(local_e4 + 0x44) != (code *)0x0) {
    (**(code **)(local_e4 + 0x44))(param_1);
  }
  return;
}

