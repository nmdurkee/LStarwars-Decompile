/* Ghidra pseudocode, not original source.
 * ev_fc1ff40c7a3094b1e589789cc6fd4e7c7ceccf6febfdd6935cf97a0e254c7b0e
 * Entry: 0x6018c0; label: FUN_006018c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006018c0(undefined1 param_1,float param_2,undefined4 param_3,undefined4 param_4,
                 float *param_5,float *param_6,undefined4 param_7,float param_8,undefined4 param_9)

{
  byte bVar1;
  
  if (DAT_00986efc < 0x40) {
    (&DAT_02835add)[DAT_00986efc * 0x38] = 0;
    (&DAT_02835adc)[DAT_00986efc * 0x38] = param_1;
    (&DAT_02835ac8)[DAT_00986efc * 0xe] = param_2;
    bVar1 = DAT_02854b44 & 1;
    (&DAT_02835ad0)[DAT_00986efc * 0xe] = param_4;
    (&DAT_02835acc)[DAT_00986efc * 0xe] = param_3;
    (&DAT_02835ad4)[DAT_00986efc * 0xe] = param_8 / param_2;
    (&DAT_02835ad8)[DAT_00986efc * 0xe] = param_9;
    (&DAT_02835ab0)[DAT_00986efc * 0xe] = *param_5;
    (&DAT_02835ab4)[DAT_00986efc * 0xe] = param_5[1];
    (&DAT_02835ab8)[DAT_00986efc * 0xe] = param_5[2];
    (&DAT_02835abc)[DAT_00986efc * 0xe] = *param_5 + *param_6;
    (&DAT_02835ac0)[DAT_00986efc * 0xe] = param_5[1] + param_6[1];
    (&DAT_02835ac4)[DAT_00986efc * 0xe] = param_5[2] + param_6[2];
    (&DAT_02835ae0)[DAT_00986efc * 0xe] = param_7;
    if ((bVar1 == 0) || ((&DAT_02835ae4)[DAT_028358a4 * 0xe] == 0)) {
      DAT_0080e6c8 = DAT_0080e6c8 * 0x24cd + 1 & 0xffff;
      (&DAT_02835ae4)[DAT_00986efc * 0xe] = DAT_0080e6c8;
    }
    DAT_0080e6c8 = DAT_0080e6c8 * 0x3139 - 0x5186 & 0xffff;
    DAT_00986efc = DAT_00986efc + 1;
  }
  return;
}

