/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5db0; label: FUN_004f5db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

size_t FUN_004f5db0(void *param_1,size_t param_2)

{
  size_t sVar1;
  
  sVar1 = DAT_00916fd0;
  if ((int)DAT_00916fd0 <= (int)param_2) {
    param_2 = DAT_00916fd0;
  }
  _memcpy(param_1,DAT_0297dc50,param_2);
  DAT_0297dc50 = (void *)((int)DAT_0297dc50 + param_2);
  DAT_029838d4 = DAT_029838d4 + param_2;
  DAT_00916fd0 = sVar1 - param_2;
  return param_2;
}

