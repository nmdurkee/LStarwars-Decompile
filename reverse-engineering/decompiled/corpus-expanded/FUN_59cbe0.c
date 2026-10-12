/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59cbe0; label: FUN_0059cbe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059cbe0(undefined1 *param_1,int param_2)

{
  int iVar1;
  int unaff_ESI;
  float10 fVar2;
  float local_8;
  undefined1 local_4;
  
  iVar1 = FUN_004f7fb0();
  if (iVar1 != 0) {
    fVar2 = (float10)FUN_004f28e0(*(undefined4 *)(unaff_ESI + 0x510));
    local_8 = (float)fVar2;
    if (local_8 <= 1.0) {
      if (local_8 < 0.0) {
        local_8 = 0.0;
      }
    }
    else {
      local_8 = 1.0;
    }
    if (param_2 < 0x100) {
      if (param_2 < 0) {
        param_2 = 0;
      }
    }
    else {
      param_2 = 0xff;
    }
    local_4 = (undefined1)(int)ROUND((float)param_2 * local_8);
    *param_1 = local_4;
  }
  return;
}

