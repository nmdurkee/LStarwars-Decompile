/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x558480; label: FUN_00558480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00558480(int param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 != 0) {
    if (DAT_0093b1e0 < 0x10) {
      (&DAT_0093b1a0)[DAT_0093b1e0] = param_1;
      DAT_0093b1e0 = DAT_0093b1e0 + 1;
      return;
    }
    local_c = DAT_0080250c;
    local_8 = DAT_00802510;
    local_4 = DAT_00802514;
    FUN_00560fa0("MAXGIZOBSTACLETRIGGERS needs increasing, ask a programmer!",&local_c,0x3ecccccd,0,
                 0x3ecccccd,200,200,200,0x2080,0);
  }
  return;
}

