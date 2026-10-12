/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67fb90; label: FUN_0067fb90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_0067fb90(float *param_1,float *param_2,float param_3,float param_4,float *param_5)

{
  float fVar1;
  int iVar2;
  
  if ((DAT_0292fc68 == 0) || (DAT_0292fdc8 == -1)) {
    return 0;
  }
  iVar2 = FUN_006de8d0(0x948);
  *(undefined4 *)(iVar2 + 0x5c) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x60) = 0x3f800000;
  *(undefined4 *)(iVar2 + 100) = 0x3f800000;
  DAT_0292186c = iVar2;
  *(undefined4 *)(iVar2 + 0x68) = 0x3f800000;
  *(float *)(iVar2 + 0x50) = param_3;
  fVar1 = 0.0;
  if (param_3 != 0.0) {
    fVar1 = 1.0 / param_3;
  }
  *(float *)(iVar2 + 0x58) = fVar1;
  *(float *)(iVar2 + 0x54) = param_3 * param_3;
  fVar1 = param_3 + 0.5;
  *(float *)(iVar2 + 0x1c) = *param_2 * fVar1 + *param_1;
  *(float *)(iVar2 + 0x20) = param_2[1] * fVar1 + param_1[1];
  *(float *)(iVar2 + 0x24) = fVar1 * param_2[2] + param_1[2];
  param_3 = param_3 + 0.8;
  *(float *)(iVar2 + 0x28) = -*param_2 * param_3;
  *(float *)(iVar2 + 0x2c) = -param_2[1] * param_3;
  fVar1 = param_2[2];
  *(undefined2 *)(iVar2 + 0x36) = 0xffff;
  *(undefined4 *)(iVar2 + 0x40) = 0;
  *(float *)(iVar2 + 0x30) = -fVar1 * param_3;
  FUN_0066f8f0();
  FUN_00675610(DAT_02947d88,DAT_0292fdc8);
  iVar2 = DAT_0292186c;
  switch(*(undefined1 *)(DAT_0292186c + 0x88)) {
  case 0:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    *param_5 = *(float *)(DAT_0292186c + 0x1c);
    param_5[1] = *(float *)(iVar2 + 0x20);
    fVar1 = *(float *)(iVar2 + 0x24);
    break;
  case 1:
  case 2:
  case 3:
  case 4:
    param_4 = *(float *)(DAT_0292186c + 0x98) - param_4;
    *(float *)(DAT_0292186c + 0x98) = param_4;
    if (param_4 < 0.0) {
      *(undefined4 *)(iVar2 + 0x98) = 0;
    }
    *param_5 = *(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x98) + *(float *)(iVar2 + 0x1c);
    param_5[1] = *(float *)(iVar2 + 0x2c) * *(float *)(iVar2 + 0x98) + *(float *)(iVar2 + 0x20);
    fVar1 = *(float *)(iVar2 + 0x30) * *(float *)(iVar2 + 0x98) + *(float *)(iVar2 + 0x24);
    break;
  default:
    goto switchD_0067fc86_caseD_5;
  }
  param_5[2] = fVar1;
switchD_0067fc86_caseD_5:
  FUN_006de960();
  return *(undefined1 *)(DAT_0292186c + 0x88);
}

