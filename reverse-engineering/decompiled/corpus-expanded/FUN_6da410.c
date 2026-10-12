/* Ghidra pseudocode, not original source.
 * ev_65739642fe41f5b8b860334b2741f542947d362cd0074980e50397e4ea9361e6
 * Entry: 0x6da410; label: FUN_006da410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006da410(int param_1,int param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  uVar1 = FUN_004f48e0(param_1);
  if (-1 < param_2) {
    uVar1 = FUN_006d87f0(uVar1,param_2,param_3,0,0,1,1,&DAT_00755d78);
    return uVar1;
  }
  *param_3 = 0;
  return 0;
}

