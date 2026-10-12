/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x548fb0; label: FUN_00548fb0
 */

void FUN_00548fb0(undefined4 *param_1,undefined4 param_2)

{
  float10 fVar1;
  
  param_1[1] = param_2;
  *param_1 = param_2;
  fVar1 = (float10)FUN_005b7d30(param_2,0x3f800000);
  param_1[2] = (float)fVar1;
  param_1[3] = 0;
  return;
}

