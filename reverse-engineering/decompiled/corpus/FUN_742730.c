/* Ghidra analysis pseudocode, not original source.
 * ev_22c3a398bc6b82f0935d4925f42062b7808fee9576bfee9324dc2ce76fb66214
 * Entry: 0x742730; label: FUN_00742730
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00742730(int param_1,int param_2)

{
  float fVar1;
  short sVar2;
  short *psVar3;
  uint uVar4;
  short sVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  float10 fVar10;
  undefined4 uVar11;
  int local_1b8;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  float local_198;
  float local_194;
  undefined4 local_190;
  float local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  float local_164;
  float local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  float local_144;
  float local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  float local_128;
  undefined4 local_124;
  float local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  float local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_d4;
  undefined4 local_c4;
  undefined4 local_40 [16];
  
  psVar3 = *(short **)(param_1 + 0x10);
  iVar8 = DAT_0297dc38;
  do {
    if (psVar3 == (short *)0x0) {
      DAT_0297dc38 = iVar8;
      return;
    }
    uVar11 = 0x3f800000;
    sVar5 = psVar3[3];
    DAT_0297dc38 = iVar8;
    switch((int)(char)sVar5) {
    case 0:
      uVar11 = FUN_00742120();
      FUN_00742380(uVar11);
      break;
    default:
      break;
    case 2:
      uVar11 = FUN_00742120();
      local_d4 = *(undefined4 *)(param_2 + 0x1b4);
      FUN_00742380(uVar11);
      break;
    case 9:
      if (*(char *)(param_2 + 0xfb) != '\0') {
        uVar11 = 0xbf800000;
      }
      FUN_00742310(uVar11);
      break;
    case 10:
      local_130 = *(undefined4 *)(param_2 + 0x134);
      local_12c = 0x3f800000;
      local_128 = *(float *)(param_2 + 0x138) * 0.035;
      local_124 = *(undefined4 *)(param_2 + 0x14c);
      FUN_00742380(&local_130);
      break;
    case 0xb:
      local_190 = *(undefined4 *)(param_2 + 0xf0);
      local_18c = *(float *)(param_2 + 0x284) / *(float *)(param_2 + 0x274);
      local_188 = 0;
      local_184 = 0;
      FUN_00742380(&local_190);
      break;
    case 0xc:
      fVar10 = (float10)FUN_00741690();
      local_140 = (float)(fVar10 * (float10)*(float *)(param_2 + 0x130));
      local_13c = *(undefined4 *)(param_2 + 300);
      local_138 = *(undefined4 *)(param_2 + 0x144);
      local_134 = *(undefined4 *)(param_2 + 0x148);
      FUN_00742380(&local_140);
      break;
    case 0xd:
      local_180 = *(undefined4 *)(param_2 + 0x140);
      local_17c = *(undefined4 *)(param_2 + 0x13c);
      local_178 = *(undefined4 *)(param_2 + 0x248);
      local_174 = 0;
      FUN_00742380(&local_180);
      break;
    case 0xe:
      FUN_00742310(*(undefined4 *)(param_2 + 0x114));
      break;
    case 0xf:
      FUN_00742310(*(undefined4 *)(param_2 + 0x118));
      break;
    case 0x10:
      local_f0 = *(undefined4 *)(param_2 + 0x1b8);
      local_ec = *(undefined4 *)(param_2 + 0x1bc);
      local_e8 = 0;
      local_e4 = 0;
      FUN_00742380(&local_f0);
      break;
    case 0x17:
      FUN_00743980(param_1,param_2);
      break;
    case 0x24:
      sVar2 = *psVar3;
      uVar11 = FUN_00741f70();
      FUN_006e5630((int)sVar2,uVar11);
      FUN_007421d0(*(uint *)(param_2 + 0x40) >> 10 & 3);
      FUN_006e54e0((int)*psVar3,5,2);
      FUN_006e54e0((int)*psVar3,6,2);
      FUN_006e54e0((int)*psVar3,7,2);
      uVar11 = FUN_00742190(*(float *)(param_2 + 0x18c) + _DAT_00973908);
      FUN_006e54e0((int)*psVar3,8,uVar11);
      break;
    case 0x25:
      sVar2 = *psVar3;
      uVar11 = FUN_00741f70();
      FUN_006e5630((int)sVar2,uVar11);
      FUN_007421d0(*(uint *)(param_2 + 0x40) >> 10 & 3);
      fVar1 = *(float *)(param_2 + 400) + _DAT_00973908;
      goto LAB_00742daf;
    case 0x26:
      sVar2 = *psVar3;
      uVar11 = FUN_00741f70();
      FUN_006e5630((int)sVar2,uVar11);
      FUN_007421d0(*(uint *)(param_2 + 0x40) >> 10 & 3);
      fVar1 = *(float *)(param_2 + 0x194) + _DAT_00973908;
      goto LAB_00742daf;
    case 0x27:
      sVar2 = *psVar3;
      uVar11 = FUN_00741f70();
      FUN_006e5630((int)sVar2,uVar11);
      FUN_007421d0(*(uint *)(param_2 + 0x40) >> 10 & 3);
      fVar1 = *(float *)(param_2 + 0x198) + _DAT_00973908;
LAB_00742daf:
      uVar11 = FUN_00742190(fVar1);
      FUN_006e54e0((int)*psVar3,8,uVar11);
      break;
    case 0x28:
      if (*(int *)(param_2 + 0xfc) == 0) {
        uVar11 = 0;
      }
      else {
        iVar8 = FUN_005e5310(*(int *)(param_2 + 0xfc));
        uVar11 = *(undefined4 *)(iVar8 + 0x24);
      }
      FUN_006e5630((int)*psVar3,uVar11);
      FUN_006e54e0((int)*psVar3,1,1);
      FUN_006e54e0((int)*psVar3,2,1);
      uVar11 = FUN_00742190(*(float *)(param_2 + 0x19c) + _DAT_00973908);
      FUN_006e54e0((int)*psVar3,8,uVar11);
      break;
    case 0x29:
      if (*(int *)(param_2 + 0xe8) == 0) {
        uVar11 = 0;
      }
      else {
        iVar8 = FUN_005e5310(*(int *)(param_2 + 0xe8));
        uVar11 = *(undefined4 *)(iVar8 + 0x24);
      }
      FUN_006e5630((int)*psVar3,uVar11);
      FUN_006e54e0((int)*psVar3,1,1);
      FUN_006e54e0((int)*psVar3,2,1);
      fVar1 = *(float *)(param_2 + 0x1b0) + _DAT_00973908;
      goto LAB_007430a7;
    case 0x2a:
      if (*(int *)(param_2 + 0x100) == 0) {
        uVar11 = 0;
      }
      else {
        iVar8 = FUN_005e5310(*(int *)(param_2 + 0x100));
        uVar11 = *(undefined4 *)(iVar8 + 0x24);
      }
      FUN_006e5630((int)*psVar3,uVar11);
      FUN_006e54e0((int)*psVar3,1,1);
      FUN_006e54e0((int)*psVar3,2,1);
      FUN_006e54e0((int)*psVar3,5,2);
      FUN_006e54e0((int)*psVar3,6,2);
      FUN_006e54e0((int)*psVar3,7,2);
      uVar11 = FUN_00742190(*(float *)(param_2 + 0x1a0) + _DAT_00973908);
      FUN_006e54e0((int)*psVar3,8,uVar11);
      break;
    case 0x2b:
      if (*(int *)(param_2 + 0xec) == 0) {
        uVar11 = 0;
      }
      else {
        iVar8 = FUN_005e5310(*(int *)(param_2 + 0xec));
        uVar11 = *(undefined4 *)(iVar8 + 0x24);
      }
      FUN_006e5630((int)*psVar3,uVar11);
      FUN_006e54e0((int)*psVar3,1,1);
      FUN_006e54e0((int)*psVar3,2,1);
      uVar11 = FUN_00742190(*(float *)(param_2 + 0x1ac) + _DAT_00973908);
      FUN_006e54e0((int)*psVar3,8,uVar11);
      break;
    case 0x2d:
      if (*(int *)(param_2 + 0x10c) == 0) {
        uVar11 = 0;
      }
      else {
        iVar8 = FUN_005e5310(*(int *)(param_2 + 0x10c));
        uVar11 = *(undefined4 *)(iVar8 + 0x24);
      }
      FUN_006e5630((int)*psVar3,uVar11);
      FUN_006e54e0((int)*psVar3,1,1);
      FUN_006e54e0((int)*psVar3,2,1);
      FUN_006e54e0((int)*psVar3,5,1);
      FUN_006e54e0((int)*psVar3,6,1);
      FUN_006e54e0((int)*psVar3,7,0);
      break;
    case 0x2e:
      if (DAT_02974d1c == 1) {
        uVar4 = *(uint *)(param_2 + 0xb4);
        uVar11 = DAT_02854bd4;
        if ((uVar4 & 8) == 0) goto joined_r0x0074315c;
      }
      else {
        uVar4 = *(uint *)(param_2 + 0xb4);
        uVar11 = DAT_02854bd0;
joined_r0x0074315c:
        if ((uVar4 & 0x50000) == 0) {
          if (*(int *)(param_2 + 0x104) < 1) {
            uVar11 = 0;
          }
          else {
            iVar8 = FUN_005e5310(*(int *)(param_2 + 0x104));
            uVar11 = *(undefined4 *)(iVar8 + 0x24);
          }
        }
      }
      FUN_006e5630((int)*psVar3,uVar11);
      FUN_006e54e0((int)*psVar3,1,3);
      FUN_006e54e0((int)*psVar3,2,3);
      FUN_006e54e0((int)*psVar3,3,3);
      break;
    case 0x30:
      if (*(int *)(param_2 + 0x108) == 0) {
        uVar11 = 0;
      }
      else {
        iVar8 = FUN_005e5310(*(int *)(param_2 + 0x108));
        uVar11 = *(undefined4 *)(iVar8 + 0x24);
      }
      FUN_006e5630((int)*psVar3,uVar11);
      FUN_006e54e0((int)*psVar3,1,3);
      FUN_006e54e0((int)*psVar3,2,3);
      break;
    case 0x31:
      if (*(int *)(param_2 + 0x110) == 0) {
        uVar11 = 0;
      }
      else {
        iVar8 = FUN_005e5310(*(int *)(param_2 + 0x110));
        uVar11 = *(undefined4 *)(iVar8 + 0x24);
      }
      FUN_006e5630((int)*psVar3,uVar11);
      FUN_006e54e0((int)*psVar3,1,1);
      FUN_006e54e0((int)*psVar3,2,1);
      fVar1 = *(float *)(param_2 + 0x1a8) + _DAT_00973908;
LAB_007430a7:
      uVar11 = FUN_00742190(fVar1);
      FUN_006e54e0((int)*psVar3,8,uVar11);
      break;
    case 0x33:
      uVar11 = FUN_00742120();
      FUN_00742380(uVar11);
      break;
    case 0x34:
      uVar11 = FUN_00742120();
      FUN_00742380(uVar11);
      break;
    case 0x35:
      uVar11 = FUN_00742120();
      FUN_00742380(uVar11);
      break;
    case 0x36:
      uVar11 = FUN_00742120();
      FUN_00742380(uVar11);
      break;
    case 0x37:
      local_1b0 = *(undefined4 *)(param_2 + 0xd8);
      local_1ac = *(undefined4 *)(param_2 + 0xdc);
      local_1a8 = *(undefined4 *)(param_2 + 0xe0);
      local_1a4 = *(undefined4 *)(param_2 + 0xe4);
      FUN_00742380(&local_1b0);
      break;
    case 0x39:
      uVar11 = FUN_00742120();
      FUN_00742380(uVar11);
      break;
    case 0x3a:
      uVar11 = FUN_00742120();
      FUN_00742380(uVar11);
      break;
    case 0x3b:
      uVar11 = FUN_00742120();
      local_c4 = *(undefined4 *)(param_2 + 0x158);
      FUN_00742380(uVar11);
      break;
    case 0x3c:
      FUN_00742310((*(float *)(param_2 + 0x150) - 1.0) * 0.1);
      break;
    case 0x3d:
      uVar11 = FUN_005c37f0(DAT_0297dc00);
      FUN_005f8550(uVar11,(int)*psVar3);
      FUN_006e54e0((int)*psVar3,1,3);
      FUN_006e54e0((int)*psVar3,2,3);
      FUN_006e54e0((int)*psVar3,7,0);
      break;
    case 0x40:
      FUN_007426d0(param_2 + 0x1d0);
      break;
    case 0x41:
      FUN_007426d0(param_2 + 0x1d8);
      break;
    case 0x42:
      FUN_007426d0(param_2 + 0x1e0);
      break;
    case 0x43:
      FUN_007426d0(param_2 + 0x1e8);
      break;
    case 0x48:
      local_110 = 0x3d4ccccd;
      local_10c = *(float *)(param_2 + 0x60) * 0.32;
      local_108 = 0x3e4ccccd;
      local_104 = 0x3f4ccccd;
      FUN_00742700(&local_110);
      break;
    case 0x50:
      if (((*(uint *)(param_2 + 0x26c) & 0x8000) == 0) || (*(float *)(param_2 + 0x60) != 0.0)) {
        local_150 = *(undefined4 *)(param_2 + 0x60);
        local_14c = *(undefined4 *)(param_2 + 100);
        local_148 = *(undefined4 *)(param_2 + 0x68);
        local_144 = *(float *)(param_2 + 100) * *(float *)(param_2 + 0x68) * 0.2;
        FUN_00742380(&local_150);
      }
      else {
        local_170 = 0x3f800000;
        local_16c = *(undefined4 *)(param_2 + 100);
        local_168 = *(undefined4 *)(param_2 + 0x68);
        local_164 = *(float *)(param_2 + 100) * *(float *)(param_2 + 0x68) * 0.2;
        FUN_00742380(&local_170);
      }
      break;
    case 0x51:
      FUN_00742310(*(undefined4 *)(param_2 + 0x154));
      break;
    case 0x52:
      if (*(int *)(param_2 + 0x24c) == 0) {
        uVar11 = 0;
      }
      else {
        iVar8 = FUN_005e5310(*(int *)(param_2 + 0x24c));
        uVar11 = *(undefined4 *)(iVar8 + 0x24);
      }
      FUN_006e5630((int)*psVar3,uVar11);
      FUN_006e54e0((int)*psVar3,1,3);
      FUN_006e54e0((int)*psVar3,2,3);
      FUN_006e54e0((int)*psVar3,3,3);
      break;
    case 0x53:
      local_100 = *(undefined4 *)(param_2 + 0x260);
      local_fc = *(undefined4 *)(param_2 + 0x264);
      local_f8 = 0;
      local_f4 = 0;
      FUN_00742380(&local_100);
      break;
    case 0x54:
      puVar9 = local_40;
      local_1b8 = 4;
      do {
        puVar6 = (undefined4 *)FUN_00742120();
        *puVar9 = *puVar6;
        puVar9[1] = puVar6[1];
        puVar9[2] = puVar6[2];
        puVar9[3] = puVar6[3];
        puVar9 = puVar9 + 4;
        local_1b8 = local_1b8 + -1;
      } while (local_1b8 != 0);
      if ((*(uint *)(psVar3 + 2) & 0xf0000000) == 0x10000000) {
        FUN_006e5750((int)*psVar3,local_40);
      }
      else {
        FUN_006e52e0((int)*psVar3,local_40,4);
      }
      break;
    case 0x56:
      iVar8 = FUN_005ddc60(iVar8);
      if (-1 < iVar8) {
        uVar11 = FUN_005ddc60(DAT_0297dc38,(int)*psVar3);
        uVar11 = FUN_005e5310(uVar11);
        FUN_005f8f50(uVar11);
        FUN_006e54e0((int)*psVar3,1,1);
        FUN_006e54e0((int)*psVar3,2,1);
        FUN_006e54e0((int)*psVar3,3,1);
        FUN_006e54e0((int)*psVar3,7,0);
        FUN_006e54e0((int)*psVar3,8,0);
      }
      break;
    case 0x57:
      if (iVar8 != 0) {
        uVar11 = *(undefined4 *)(iVar8 + 0x24);
        iVar7 = FUN_006e6b90();
        fVar1 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff];
        iVar7 = FUN_006e6b90();
        local_194 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] / 30.0;
        local_1a0 = *(undefined4 *)(iVar8 + 0x2c);
        local_19c = uVar11;
        local_198 = fVar1 / 10.0;
        FUN_00742700(&local_1a0);
      }
      break;
    case 0x5b:
      local_160 = 1.0 / *(float *)(param_2 + 0x290);
      local_15c = *(undefined4 *)(param_2 + 0x288);
      local_158 = *(undefined4 *)(param_2 + 0x28c);
      local_154 = *(undefined4 *)(param_2 + 0x294);
      FUN_00742380(&local_160);
      break;
    case 0x5c:
      local_120 = *(float *)(param_2 + 0x274) * 0.1;
      local_11c = *(undefined4 *)(param_2 + 0x27c);
      local_118 = *(undefined4 *)(param_2 + 0x280);
      local_114 = *(undefined4 *)(param_2 + 0x278);
      FUN_00742380(&local_120);
      break;
    case 0x61:
      if (*(int *)(param_2 + 0x298) == 0) {
        uVar11 = 0;
      }
      else {
        iVar8 = FUN_005e5310(*(int *)(param_2 + 0x298));
        uVar11 = *(undefined4 *)(iVar8 + 0x24);
      }
      FUN_006e5630((int)*psVar3,uVar11);
      FUN_006e54e0((int)*psVar3,1,1);
      FUN_006e54e0((int)*psVar3,2,1);
      FUN_006e54e0((int)*psVar3,5,1);
      uVar11 = 1;
      goto LAB_007436ae;
    case 0x62:
      if (*(int *)(param_2 + 0x29c) == 0) {
        uVar11 = 0;
      }
      else {
        iVar8 = FUN_005e5310(*(int *)(param_2 + 0x29c));
        uVar11 = *(undefined4 *)(iVar8 + 0x24);
      }
      FUN_006e5630((int)*psVar3,uVar11);
      FUN_006e54e0((int)*psVar3,1,1);
      FUN_006e54e0((int)*psVar3,2,1);
      FUN_006e54e0((int)*psVar3,5,0);
      uVar11 = 0;
LAB_007436ae:
      FUN_006e54e0((int)*psVar3,6,uVar11);
      FUN_006e54e0((int)*psVar3,7,0);
    }
    if ((*(int *)(param_1 + 0x14) != 4) &&
       (iVar8 = (char)sVar5 * 0x5c, *(int *)(&DAT_0082b1e8 + iVar8) != 0)) {
      iVar8 = iVar8 + 0x82b1ec;
      switch((*(int *)(psVar3 + 2) << 4) >> 0x1c) {
      case 1:
        FUN_00742340(0,1,iVar8);
        break;
      case 2:
        FUN_007423b0(0,iVar8);
        break;
      case 3:
        FUN_00742010(0,1,iVar8);
      }
    }
    psVar3 = *(short **)(psVar3 + 4);
    iVar8 = DAT_0297dc38;
  } while( true );
}

