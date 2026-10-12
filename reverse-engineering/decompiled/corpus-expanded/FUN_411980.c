/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x411980; label: FUN_00411980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00411980(void)

{
  float fVar1;
  int in_EAX;
  undefined4 *puVar2;
  int iVar3;
  int extraout_EDX;
  int iVar4;
  float10 fVar5;
  
  *(undefined4 *)(in_EAX + 0x636f0) = 0xc30d0000;
  *(undefined4 *)(in_EAX + 0x636f4) = 0xc2f20000;
  iVar4 = 6;
  *(undefined4 *)(in_EAX + 0x636f8) = 0xc4814000;
  *(undefined4 *)(in_EAX + 0x636fc) = 0;
  *(undefined4 *)(in_EAX + 0x636e0) = 0xc4b61ccd;
  *(undefined4 *)(in_EAX + 0x636e4) = 0x43a34000;
  *(undefined4 *)(in_EAX + 0x636e8) = 0xc3c50000;
  *(undefined4 *)(in_EAX + 0x636ec) = 0;
  *(float *)(in_EAX + 0x63700) = *(float *)(in_EAX + 0x636f0) - *(float *)(in_EAX + 0x636e0);
  *(float *)(in_EAX + 0x63704) = *(float *)(in_EAX + 0x636f4) - *(float *)(in_EAX + 0x636e4);
  *(float *)(in_EAX + 0x63708) = *(float *)(in_EAX + 0x636f8) - *(float *)(in_EAX + 0x636e8);
  *(float *)(in_EAX + 0x63700) = *(float *)(in_EAX + 0x63700) * 1.1;
  *(float *)(in_EAX + 0x63704) = *(float *)(in_EAX + 0x63704) * 1.1;
  *(float *)(in_EAX + 0x63708) = *(float *)(in_EAX + 0x63708) * 1.1;
  *(float *)(in_EAX + 0x636f0) = *(float *)(in_EAX + 0x63700) + *(float *)(in_EAX + 0x636e0);
  *(float *)(in_EAX + 0x636f4) = *(float *)(in_EAX + 0x636e4) + *(float *)(in_EAX + 0x63704);
  *(float *)(in_EAX + 0x636f8) = *(float *)(in_EAX + 0x636e8) + *(float *)(in_EAX + 0x63708);
  fVar5 = (float10)FUN_005c0240(*(float *)(in_EAX + 0x63708) * *(float *)(in_EAX + 0x63708) +
                                *(float *)(in_EAX + 0x63700) * *(float *)(in_EAX + 0x63700) +
                                *(float *)(in_EAX + 0x63704) * *(float *)(in_EAX + 0x63704));
  iVar3 = 0x78;
  *(float *)(in_EAX + 0x63710) = (float)fVar5;
  *(float *)(in_EAX + 0x63714) = 1.0 / (float)fVar5;
  while (((DAT_0093d7f0 == 0 || (*(float *)(DAT_0093d7f0 + 0x69c) <= *(float *)(iVar3 + 0x7f127c)))
         && ((DAT_0093d7f4 == 0 ||
             (*(float *)(DAT_0093d7f4 + 0x69c) <= *(float *)(iVar3 + 0x7f127c)))))) {
    iVar3 = iVar3 + -0x14;
    iVar4 = iVar4 + -1;
    if (iVar3 == -0x14) {
LAB_00411b6c:
      *(undefined4 *)(in_EAX + 0x63720) = 0;
      *(undefined4 *)(in_EAX + 0x6371c) = 0;
      *(undefined4 *)(in_EAX + 0x63724) = 0;
LAB_00411b90:
      do {
        FUN_00410240();
      } while (extraout_EDX != 1);
      FUN_00410170();
      FUN_0040ffa0();
      puVar2 = (undefined4 *)(in_EAX + 0x565a0);
      iVar3 = 0x60;
      do {
        puVar2[0x10] = 0;
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2 = puVar2 + 0x4c;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_004100b0();
      fVar5 = (float10)FUN_005b9dd0();
      _DAT_00855e78 = (float)(fVar5 * (float10)10.0 + (float10)3.0);
      return;
    }
  }
  fVar1 = *(float *)(iVar4 * 0x14 + 0x7f1280);
  *(float *)(in_EAX + 0x6371c) = fVar1;
  fVar1 = (fVar1 * 94.97742) / 59.449684;
  *(float *)(in_EAX + 0x63720) = fVar1;
  *(float *)(in_EAX + 0x63724) = ((fVar1 - _DAT_00925018) * 94.97742) / 59.449684;
  if (iVar4 != -1) goto LAB_00411b90;
  goto LAB_00411b6c;
}

