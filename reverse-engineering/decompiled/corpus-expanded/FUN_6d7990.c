/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d7990; label: FUN_006d7990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d7990(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  undefined2 *puVar7;
  uint uVar8;
  int in_ECX;
  int iVar9;
  int iVar10;
  float10 fVar11;
  
  if (((DAT_029755a8 & 1) == 0) && (*(char *)(in_ECX + 0x4e11) == '\0')) {
    if ((DAT_029765b4 == 0) || (iVar10 = DAT_029765b8, DAT_029765b8 == 0)) {
      iVar10 = 0;
    }
    *(undefined1 *)(in_ECX + 0x4e11) = 1;
    puVar7 = (undefined2 *)FUN_006d57d0();
    *(undefined2 *)(in_ECX + 0x6302) = *(undefined2 *)(in_ECX + 0x62fc);
    *(undefined2 *)(in_ECX + 0x6304) = *(undefined2 *)(in_ECX + 0x62fe);
    *(undefined2 *)(in_ECX + 0x6306) = *(undefined2 *)(in_ECX + 0x6300);
    if (puVar7 != (undefined2 *)0x0) {
      uVar1 = *puVar7;
      *(undefined2 *)(in_ECX + 0x62fc) = uVar1;
      uVar2 = puVar7[2];
      *(undefined2 *)(in_ECX + 0x62fe) = uVar2;
      uVar3 = puVar7[4];
      *(undefined2 *)(in_ECX + 0x6300) = uVar3;
      fVar4 = (float)*(byte *)(in_ECX + 0x5d29) + (float)*(byte *)(in_ECX + 0x5d29);
      fVar4 = fVar4 * fVar4;
      if (*(char *)(in_ECX + 0x671a) != '\0') {
        *(undefined4 *)(in_ECX + 0x6308) = 0;
        *(undefined1 *)(in_ECX + 0x671a) = 0;
        *(undefined4 *)(in_ECX + 0x630c) = 0;
        *(undefined2 *)(in_ECX + 0x6302) = uVar1;
        *(undefined4 *)(in_ECX + 0x6310) = 0;
        *(undefined2 *)(in_ECX + 0x6304) = uVar2;
        *(undefined2 *)(in_ECX + 0x6306) = uVar3;
        *(undefined4 *)(in_ECX + 0x632c) = 0x3f000000;
        *(undefined4 *)(in_ECX + 0x6330) = 0x3f000000;
      }
      fVar5 = (float)((int)*(short *)(in_ECX + 0x62fc) - (int)*(short *)(in_ECX + 0x6302));
      if (32767.0 < fVar5) {
        fVar5 = fVar5 - 65536.0;
      }
      if (fVar5 < -32768.0) {
        fVar5 = fVar5 + 65536.0;
      }
      *(float *)(in_ECX + 0x6314) = fVar4 * fVar5;
      fVar5 = (float)((int)*(short *)(in_ECX + 0x62fe) - (int)*(short *)(in_ECX + 0x6304));
      if (32767.0 < fVar5) {
        fVar5 = fVar5 - 65536.0;
      }
      if (fVar5 < -32768.0) {
        fVar5 = fVar5 + 65536.0;
      }
      *(float *)(in_ECX + 0x6318) = fVar5 * fVar4;
      fVar4 = (float)((int)*(short *)(in_ECX + 0x6300) - (int)*(short *)(in_ECX + 0x6306));
      if (32767.0 < fVar4) {
        fVar4 = fVar4 - 65536.0;
      }
      if (fVar4 < -32768.0) {
        fVar4 = fVar4 + 65536.0;
      }
      *(float *)(in_ECX + 0x631c) = fVar4;
      *(float *)(in_ECX + 0x6308) =
           *(float *)(in_ECX + 0x6308) + *(float *)(in_ECX + 0x6314) * 0.00390625;
      *(float *)(in_ECX + 0x630c) =
           *(float *)(in_ECX + 0x6318) * 0.00390625 + *(float *)(in_ECX + 0x630c);
      *(float *)(in_ECX + 0x6310) = fVar4 + *(float *)(in_ECX + 0x6310);
      fVar11 = (float10)FUN_006df290();
      fVar4 = *(float *)(in_ECX + 0x632c) +
              *(float *)(in_ECX + 0x6314) * (float)((float10)1 / fVar11) * 7.6293945e-06;
      *(float *)(in_ECX + 0x632c) = fVar4;
      fVar5 = *(float *)(in_ECX + 0x6330) + *(float *)(in_ECX + 0x6318) * 7.6293945e-06;
      *(float *)(in_ECX + 0x6330) = fVar5;
      if (0.0 <= fVar4) {
        if (1.0 < fVar4) {
          *(undefined4 *)(in_ECX + 0x632c) = 0x3f800000;
        }
      }
      else {
        *(undefined4 *)(in_ECX + 0x632c) = 0;
      }
      if (0.0 <= fVar5) {
        if (1.0 < fVar5) {
          *(undefined4 *)(in_ECX + 0x6330) = 0x3f800000;
        }
      }
      else {
        *(undefined4 *)(in_ECX + 0x6330) = 0;
      }
      uVar6 = DAT_02975170;
      uVar8 = 0;
      iVar9 = 0;
      DAT_02975170 = 0;
      if (0 < iVar10) {
        do {
          if (*(char *)(in_ECX + 0x6334 + iVar9) != '\0') {
            uVar8 = uVar8 | 1 << ((byte)iVar9 & 0x1f);
          }
          iVar9 = iVar9 + 1;
          DAT_02975170 = uVar8;
        } while (iVar9 < iVar10);
      }
      DAT_0297519c = (DAT_02975170 ^ uVar6) & DAT_02975170;
      *(undefined4 *)(in_ECX + 0x6334) = 0;
      *(undefined4 *)(in_ECX + 0x6338) = 0;
      FUN_004ef660((undefined4 *)(in_ECX + 0x6334),puVar7 + 6,iVar10);
      return 1;
    }
    *(undefined4 *)(in_ECX + 0x6334) = 0;
    *(undefined4 *)(in_ECX + 0x6338) = 0;
    *(undefined4 *)(in_ECX + 0x633c) = 0;
    *(undefined4 *)(in_ECX + 0x6340) = 0;
    *(undefined4 *)(in_ECX + 0x631c) = 0;
    *(undefined4 *)(in_ECX + 0x6318) = 0;
    *(undefined4 *)(in_ECX + 0x6314) = 0;
    *(undefined4 *)(in_ECX + 0x6310) = 0;
    *(undefined4 *)(in_ECX + 0x630c) = 0;
    *(undefined2 *)(in_ECX + 0x6302) = *(undefined2 *)(in_ECX + 0x62fc);
    *(undefined4 *)(in_ECX + 0x6308) = 0;
    *(undefined2 *)(in_ECX + 0x6304) = *(undefined2 *)(in_ECX + 0x62fe);
    *(undefined2 *)(in_ECX + 0x6306) = *(undefined2 *)(in_ECX + 0x6300);
  }
  return 0;
}

