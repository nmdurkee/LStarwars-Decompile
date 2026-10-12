/* Ghidra pseudocode; not original source. ev_0755810926ff77a89e2dcd186a76c69177137871e250c85cd6e95818c3300974 */

void FUN_006d4880(short *param_1,short *param_2)

{
  short sVar1;
  
  FUN_005c0240(ABS((float)(int)*param_1) * ABS((float)(int)*param_1) +
               ABS((float)(int)*param_2) * ABS((float)(int)*param_2));
  sVar1 = FUN_006e6b90();
  *param_1 = sVar1;
  sVar1 = FUN_006e6b90();
  *param_2 = sVar1;
  return;
}

