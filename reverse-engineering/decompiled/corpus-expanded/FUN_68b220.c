/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68b220; label: FUN_0068b220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068b220(int param_1,float *param_2)

{
  *(float *)((*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 + param_1) * 0x20
            + DAT_02962a18) = *param_2 - *(float *)(DAT_02921884 * 0x50 + DAT_02962a14 + 8);
  *(float *)((*(short *)(DAT_02921884 * 0x50 + DAT_02962a14 + 0x40) * DAT_02962a10 + param_1) * 0x20
             + 4 + DAT_02962a18) = param_2[1] - *(float *)(DAT_02921884 * 0x50 + 0xc + DAT_02962a14)
  ;
  *(float *)((*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 + param_1) * 0x20
             + 8 + DAT_02962a18) =
       param_2[2] - *(float *)(DAT_02921884 * 0x50 + 0x10 + DAT_02962a14);
  *(undefined4 *)
   ((*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 + param_1) * 0x20 + 0xc +
   DAT_02962a18) = 0x3f800000;
  *(undefined2 *)
   ((*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 + param_1) * 0x20 + 0x10 +
   DAT_02962a18) = (undefined2)DAT_029629ec;
  *(undefined2 *)
   ((*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 + param_1) * 0x20 + 0x12 +
   DAT_02962a18) = (undefined2)DAT_029629f0;
  FUN_00689f70();
  return;
}

