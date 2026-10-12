/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x494e20; label: FUN_00494e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494e20(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  int *piVar7;
  bool bVar8;
  float10 fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int *local_4;
  
  iVar1 = DAT_00826494;
  if (DAT_00826494 == 3) {
    iVar1 = DAT_02976bf4;
  }
  DAT_008668d7 = iVar1 != 0;
  if (DAT_00921d28 != 0) {
    DAT_00921d28 = 0;
    DAT_00951b80 = DAT_00951b90;
    DAT_0093d81c = 2;
    FUN_00547b20(&DAT_008668cc);
    if (DAT_008668d2 == '\0') {
      fVar9 = (float10)0;
    }
    else {
      fVar9 = (float10)FUN_00547a70(&DAT_0087656c);
    }
    FUN_00547a30((float)fVar9);
    FUN_005767d0();
    _DAT_0087b6d4 = 0;
    DAT_00876d9c = DAT_00876d9c | 7;
    if (0x14 < DAT_008668d8) {
      DAT_008668d8 = 10;
    }
    FUN_004f5120((float)DAT_008668d8 / 10.0);
    return;
  }
  iVar1 = FUN_00494bb0();
  if (iVar1 != 0) {
    return;
  }
  if (30.0 <= *(float *)(param_1 + 4)) {
    DAT_0087b5a0 = 2;
    return;
  }
  if (_DAT_0092505c < 4.0) {
    return;
  }
  puVar5 = &DAT_0093d516;
  local_4 = &DAT_0297e048;
  piVar7 = &DAT_009253b0;
  uVar2 = DAT_00802290;
  uVar3 = DAT_00802294;
  uVar4 = DAT_00802298;
  uVar6 = DAT_0080229c;
  do {
    if ((piVar7[1] & DAT_00802274) != 0) {
      FUN_004f42d0(*(undefined4 *)*piVar7,1);
      uVar2 = DAT_00802290;
      uVar3 = DAT_00802294;
      uVar4 = DAT_00802298;
      uVar6 = DAT_0080229c;
    }
    if (((char)piVar7[9] == '\0') || ((*(byte *)(*piVar7 + 0x80) & 4) == 0)) {
      *puVar5 = 0;
    }
    else if ((((piVar7[1] &
               (DAT_0080228c | DAT_00802288 | DAT_00802284 | DAT_00802280 | DAT_0080227c |
                DAT_00802278 | uVar6 | uVar4 | uVar3 | uVar2 | DAT_00802274)) != 0) ||
             ((piVar7[3] & (uVar6 | uVar4 | uVar3 | uVar2)) != 0)) && (*local_4 != 0)) {
      *puVar5 = 1;
    }
    local_4 = local_4 + 3;
    piVar7 = piVar7 + 0x18;
    puVar5 = puVar5 + 0x10;
  } while ((int)piVar7 < 0x925470);
  bVar8 = DAT_0087b740 != 0;
  if (bVar8) {
    DAT_0087b740 = 0;
  }
  DAT_0087b744 = (uint)bVar8;
  if (*(int *)(param_1 + 100) == 0) goto switchD_00495053_default;
  if (bVar8) goto LAB_004950bb;
  DAT_00800940 = FUN_00547990(0x30);
  switch(*(undefined4 *)(param_1 + 0x34)) {
  case 0:
    FUN_00509830(0x3fe,0xffffffff,0xffffffff);
    DAT_0087b740 = 1;
    goto switchD_00495053_default;
  case 1:
    uVar11 = 0xffffffff;
    uVar10 = 0x3f4;
    break;
  case 2:
    uVar11 = 0xffffffff;
    uVar10 = 4;
    break;
  case 3:
    uVar11 = 0;
    uVar10 = 0x15;
    break;
  case 4:
    uVar11 = 0;
    uVar10 = 0x401;
    break;
  case 5:
    uVar11 = 0;
    uVar10 = 0x402;
    break;
  case 6:
    uVar11 = 0xffffffff;
    uVar10 = 0x405;
    break;
  default:
    goto switchD_00495053_default;
  }
  FUN_00509830(uVar10,uVar11,0xffffffff);
switchD_00495053_default:
  if (DAT_0087b744 != 0) {
LAB_004950bb:
    DAT_0087b744 = 0;
    FUN_0042abf0();
    _DAT_0087b73c = 0;
    DAT_00951b80 = DAT_00951b8c;
    DAT_0093d81c = 2;
    DAT_0087b738 = 1;
  }
  return;
}

