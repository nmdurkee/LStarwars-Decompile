/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x561b20; label: FUN_00561b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00561b20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7)

{
  undefined4 local_4;
  
  if (param_7 == 0) {
    local_4 = 0xbf;
    param_7 = 0;
  }
  else {
    param_7 = 0xff;
    local_4 = 0xff;
  }
  FUN_00561a00(param_1,param_2,param_3,param_4,param_5,param_6,0xff,local_4,param_7);
  return;
}

