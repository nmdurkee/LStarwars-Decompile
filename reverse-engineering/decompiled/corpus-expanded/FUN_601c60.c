/* Ghidra pseudocode, not original source.
 * ev_fc1ff40c7a3094b1e589789cc6fd4e7c7ceccf6febfdd6935cf97a0e254c7b0e
 * Entry: 0x601c60; label: FUN_00601c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00601c60(undefined1 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 uint param_9,undefined4 param_10)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = (param_9 >> 0x18) * 2;
  if (0xff < uVar2) {
    uVar2 = 0xff;
  }
  uVar4 = (param_9 >> 0x10 & 0xff) * 2;
  if (0xff < uVar4) {
    uVar4 = 0xff;
  }
  uVar5 = (param_9 & 0xff00) * 2;
  if (0xff00 < uVar5) {
    uVar5 = 0xff00;
  }
  uVar3 = (param_9 & 0xff) * 2;
  if (0xff < uVar3) {
    uVar3 = 0xff;
  }
  if (DAT_028358a4 < 0x10) {
    (&DAT_00986494)[DAT_028358a4 * 0x44] = param_1;
    (&DAT_00986460)[DAT_028358a4 * 0x11] = *param_2;
    (&DAT_00986464)[DAT_028358a4 * 0x11] = param_2[1];
    (&DAT_00986468)[DAT_028358a4 * 0x11] = param_2[2];
    (&DAT_0098646c)[DAT_028358a4 * 0x11] = *param_3;
    (&DAT_00986470)[DAT_028358a4 * 0x11] = param_3[1];
    (&DAT_00986474)[DAT_028358a4 * 0x11] = param_3[2];
    (&DAT_00986478)[DAT_028358a4 * 0x11] = *param_4;
    (&DAT_0098647c)[DAT_028358a4 * 0x11] = param_4[1];
    (&DAT_00986480)[DAT_028358a4 * 0x11] = param_4[2];
    (&DAT_00986484)[DAT_028358a4 * 0x11] = param_5;
    (&DAT_00986488)[DAT_028358a4 * 0x11] = param_6;
    (&DAT_0098648c)[DAT_028358a4 * 0x11] = param_7;
    bVar1 = DAT_02854b44 & 1;
    (&DAT_00986490)[DAT_028358a4 * 0x11] = param_8;
    (&DAT_00986498)[DAT_028358a4 * 0x11] = uVar3 << 0x10 | uVar5 | uVar4 | uVar2 << 0x18;
    *(undefined4 *)(&DAT_0098649c + DAT_028358a4 * 0x44) = param_10;
    if ((bVar1 == 0) || ((&DAT_009864a0)[DAT_028358a4 * 0x11] == 0)) {
      DAT_0080e6c8 = DAT_0080e6c8 * 0x24cd + 1 & 0xffff;
      (&DAT_009864a0)[DAT_028358a4 * 0x11] = DAT_0080e6c8;
    }
    DAT_0080e6c8 = DAT_0080e6c8 * 0x3139 - 0x5186 & 0xffff;
    DAT_028358a4 = DAT_028358a4 + 1;
  }
  return;
}

