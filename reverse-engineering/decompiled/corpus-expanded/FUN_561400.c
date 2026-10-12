/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x561400; label: FUN_00561400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00561400(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  float *pfVar9;
  float10 extraout_ST0;
  float10 fVar10;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar11;
  float local_18;
  float local_c;
  float local_8;
  float local_4;
  
  pfVar9 = (float *)&DAT_00947c90;
  iVar8 = 0x80;
  do {
    fVar11 = (float10)0;
    if (((*(char *)(pfVar9 + 10) != '\0') &&
        (((*(char *)((int)pfVar9 + 0x2b) == '\0' || (((uint)pfVar9[2] & 0x40000) != 0)) &&
         ((float10)*pfVar9 <= fVar11)))) &&
       ((pfVar9[-5] < pfVar9[-4] || (*(char *)((int)pfVar9 + 0x2a) != '\0')))) {
      fVar2 = pfVar9[2];
      if (((uint)fVar2 & 0x100) == 0) {
        if ((((uint)fVar2 & 0x200) == 0) && (((uint)fVar2 & 0x400) == 0)) {
          if (((uint)fVar2 & 0x800) == 0) {
            fVar10 = (float10)(pfVar9[-5] / pfVar9[-4]);
          }
          else {
            iVar5 = FUN_006e6b90();
            fVar10 = extraout_ST1_00 - (float10)(float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff];
            fVar11 = extraout_ST0_01;
          }
        }
        else {
          iVar5 = FUN_006e6b90();
          fVar10 = (float10)(float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff];
          fVar11 = extraout_ST0_00;
        }
      }
      else {
        iVar5 = FUN_006e6b90();
        fVar10 = extraout_ST0 - (float10)(float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff];
        fVar11 = extraout_ST1;
      }
      fVar1 = (float)fVar10;
      if ((SUB41(fVar2,0) & 5) == 5) {
        local_18 = pfVar9[-6];
      }
      else {
        local_18 = pfVar9[-7];
      }
      local_4 = pfVar9[-10];
      fVar3 = pfVar9[-0xc];
      fVar4 = pfVar9[-0xb];
      local_c = fVar3;
      local_8 = fVar4;
      if ((fVar11 != (float10)pfVar9[1]) && (*(char *)((int)pfVar9 + 0x2b) == '\0')) {
        local_8 = -pfVar9[1];
        local_c = local_8;
        if ((local_8 <= fVar3) && (local_c = fVar3, pfVar9[1] < fVar3)) {
          local_c = pfVar9[1];
        }
        if ((local_8 <= fVar4) && (local_8 = fVar4, pfVar9[1] < fVar4)) {
          local_8 = pfVar9[1];
        }
      }
      if (((uint)fVar2 & 8) != 0) {
        if ((code *)pfVar9[0xe] != (code *)0x0) {
          (*(code *)pfVar9[0xe])(pfVar9 + -0x34);
        }
        local_c = local_c + fVar1 * (pfVar9[-0x12] - local_c);
        local_8 = local_8 + fVar1 * (pfVar9[-0x11] - local_8);
        local_4 = local_4 + fVar1 * (pfVar9[-0x10] - local_4);
      }
      if (((uint)pfVar9[2] & 0x20) != 0) {
        local_18 = local_18 + (pfVar9[-8] - local_18) * fVar1;
      }
      local_c = pfVar9[-3] + local_c;
      local_4 = pfVar9[-2] + local_4;
      if ((code *)pfVar9[0xf] == (code *)0x0) {
        pfVar7 = pfVar9 + 6;
        iVar5 = FUN_005cfac0(pfVar7);
        if (iVar5 == 0) {
          pfVar7 = (float *)pfVar9[-0x34];
          if ((pfVar7 != (float *)0x0) || (pfVar7 = pfVar9 + -0x33, pfVar7 != (float *)0x0)) {
            FUN_0050c780(pfVar7,local_c,local_8,local_4,local_18,local_18,local_18,
                         *(undefined1 *)(pfVar9 + 0xb),*(undefined1 *)(pfVar9 + 9),
                         *(undefined1 *)((int)pfVar9 + 0x25),*(undefined1 *)((int)pfVar9 + 0x26),
                         *(undefined1 *)((int)pfVar9 + 0x27));
          }
        }
        else {
          if (((uint)pfVar9[2] & 0x20000) == 0) {
            if (((uint)pfVar9[2] & 0x10000) == 0) {
              fVar2 = 1.0;
            }
            else {
              fVar2 = (float)*(byte *)((int)pfVar9 + 0x27) * 0.0078125;
            }
            FUN_00552c10(local_c,local_8,local_4,local_18,local_18,local_18,
                         *(undefined2 *)(pfVar9 + 4),*(undefined2 *)((int)pfVar9 + 0x12),
                         *(undefined2 *)(pfVar9 + 5),pfVar7,2,fVar2);
          }
          else {
            FUN_00552d10(local_c,local_8,local_4,local_18,local_18,local_18,
                         *(undefined2 *)(pfVar9 + 4),*(undefined2 *)((int)pfVar9 + 0x12),
                         *(undefined2 *)(pfVar9 + 5),pfVar7,2);
          }
          if (((DAT_009505c4 != (code *)0x0) &&
              (iVar5 = (*DAT_009505c4)(pfVar9 + -0x34), iVar5 != 0)) &&
             (iVar6 = FUN_005cfac0(iVar5), iVar6 != 0)) {
            if (((uint)pfVar9[2] & 0x20000) == 0) {
              if (((uint)pfVar9[2] & 0x10000) == 0) {
                fVar2 = 1.0;
              }
              else {
                fVar2 = (float)*(byte *)((int)pfVar9 + 0x27) * 0.0078125;
              }
              FUN_00552c10(local_c,local_8,local_4,local_18,local_18,local_18,
                           *(undefined2 *)(pfVar9 + 4),*(undefined2 *)((int)pfVar9 + 0x12),
                           *(undefined2 *)(pfVar9 + 5),iVar5,2,fVar2);
            }
            else {
              FUN_00552d10(local_c,local_8,local_4,local_18,local_18,local_18,
                           *(undefined2 *)(pfVar9 + 4),*(undefined2 *)((int)pfVar9 + 0x12),
                           *(undefined2 *)(pfVar9 + 5),iVar5,2);
            }
          }
        }
      }
      else {
        (*(code *)pfVar9[0xf])(pfVar9 + -0x34,&local_c,local_18);
      }
    }
    pfVar9 = pfVar9 + 0x45;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  return;
}

