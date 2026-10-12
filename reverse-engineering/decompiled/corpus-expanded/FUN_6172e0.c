/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x6172e0; label: FUN_006172e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006172e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_4;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  FUN_004f1f10(in_ECX + 3,param_2);
  in_ECX[0x23] = param_3;
  in_ECX[0x24] = param_5;
  in_ECX[0x25] = param_6;
  in_ECX[0x26] = 0;
  return;
}

