/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x678580; label: FUN_00678580
 */

void FUN_00678580(float *param_1)

{
  float fVar1;
  int iVar2;
  
  FUN_006783a0();
  iVar2 = DAT_0292186c;
  switch(*(undefined1 *)(DAT_0292186c + 0x88)) {
  case 1:
  case 2:
  case 3:
  case 4:
    fVar1 = *(float *)(DAT_0292186c + 0x98) - *(float *)(DAT_0292186c + 0xa0);
    *(float *)(DAT_0292186c + 0x98) = fVar1;
    if (fVar1 < 0.0) {
      *(undefined4 *)(iVar2 + 0x98) = 0;
    }
    *param_1 = *(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x98);
    param_1[1] = *(float *)(iVar2 + 0x2c) * *(float *)(iVar2 + 0x98);
    param_1[2] = *(float *)(iVar2 + 0x30) * *(float *)(iVar2 + 0x98);
    return;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
  }
  return;
}

