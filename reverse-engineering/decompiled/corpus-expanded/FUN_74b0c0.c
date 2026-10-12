/* Ghidra pseudocode, not original source.
 * ev_e04dcb01310c2b6a71419ceaaf6429f586bcd28525a19be66005014cd18274f1
 * Entry: 0x74b0c0; label: FUN_0074b0c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074b0c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  in_ECX[4] = param_3;
  in_ECX[5] = param_4;
  in_ECX[6] = param_5;
  in_ECX[7] = param_6;
  *in_ECX = 3;
  in_ECX[1] = 0;
  in_ECX[8] = param_7;
  in_ECX[9] = param_8;
  return;
}

