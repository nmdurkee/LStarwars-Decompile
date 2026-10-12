/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c7290; label: FUN_006c7290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c7290(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  if (in_ECX + 1 != (undefined4 *)0x0) {
    in_ECX[1] = 0;
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_FUN_0076f97c;
  in_ECX[3] = 0x10;
  uVar1 = FUN_00633440(0x100,1);
  in_ECX[5] = uVar1;
  return;
}

