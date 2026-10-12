/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x429c00; label: FUN_00429c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00429c00(int param_1,int param_2,float *param_3,undefined4 *param_4)

{
  float fVar1;
  undefined4 uVar2;
  
  *param_3 = DAT_00802518;
  param_3[1] = DAT_0080251c;
  param_3[2] = DAT_00802520;
  *param_4 = DAT_0093b0cc;
  param_4[1] = DAT_0093b0d0;
  param_4[2] = DAT_0093b0d4;
  if (param_1 == DAT_007f1944) {
    fVar1 = 2.2;
LAB_00429e80:
    *param_3 = fVar1;
  }
  else {
    if (param_1 == DAT_007f193c) {
      fVar1 = 4.6;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f1934) {
      fVar1 = 3.8;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f18f4) {
      fVar1 = 5.1;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f1990) {
      fVar1 = 2.25;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f1a5c) {
      fVar1 = 2.3;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f1a60) {
      fVar1 = 2.3;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f1914) {
LAB_00429ce3:
      fVar1 = 7.0;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f18b4) {
      fVar1 = 3.0;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f1a1c) {
      fVar1 = 10.0;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f1960) {
      fVar1 = 6.5;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f1a24) {
      fVar1 = 4.0;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f19a4) {
      fVar1 = 10.0;
      goto LAB_00429e80;
    }
    if ((((param_1 == DAT_007f1970) || (param_1 == DAT_007f1a28)) || (param_1 == DAT_007f196c)) ||
       (param_1 == DAT_007f1964)) goto LAB_00429e7a;
    if (param_1 == DAT_007f1a2c) {
      fVar1 = 8.0;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f195c) {
      fVar1 = 8.0;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f1a64) {
LAB_00429e7a:
      fVar1 = 6.0;
      goto LAB_00429e80;
    }
    if (param_1 == DAT_007f1a98) {
LAB_00429dde:
      fVar1 = 5.0;
      goto LAB_00429e80;
    }
    if ((((param_1 == DAT_007f1b40) || (param_1 == DAT_007f1b44)) ||
        ((param_1 == DAT_007f1b2c || ((param_1 == DAT_007f1b30 || (param_1 == DAT_007f1a00)))))) ||
       (param_1 == DAT_007f1a04)) goto LAB_00429e7a;
    if ((param_1 == DAT_007f1a9c) || (param_1 == DAT_007f1aa0)) goto LAB_00429ce3;
    if ((param_1 == DAT_007f1b34) || (param_1 == DAT_007f1b38)) goto LAB_00429dde;
    if (param_1 == DAT_007f1b1c) {
      fVar1 = 8.0;
      goto LAB_00429e80;
    }
  }
  if ((param_2 == 5) || (param_2 == 6)) {
LAB_00429f46:
    uVar2 = 0xbcf5c28f;
  }
  else if ((param_1 == DAT_007f1994) || (param_1 == DAT_007f1998)) {
    uVar2 = 0xbc23ad19;
  }
  else {
    if (*(char *)(param_1 * 0x120 + 0x116 + DAT_0093b284) == '\x01') goto LAB_00429f46;
    if (param_1 == DAT_007f1a50) {
      uVar2 = 0xbbf5c28f;
    }
    else {
      if ((((param_1 == DAT_007f1a68) || (param_1 == DAT_007f199c)) || (param_1 == DAT_007f1a6c)) ||
         ((param_1 == DAT_007f1a70 || (param_1 == DAT_007f1a74)))) goto LAB_00429f46;
      if (param_1 == DAT_007f1878) {
        uVar2 = 0x3c75c28f;
      }
      else {
        if (param_1 != DAT_007f1a30) goto LAB_00429f4f;
        uVar2 = 0xbcb851eb;
      }
    }
  }
  param_4[2] = uVar2;
LAB_00429f4f:
  if (*param_3 != 1.0) {
    param_3[2] = *param_3;
    param_3[1] = *param_3;
  }
  return;
}

