/* Ghidra analysis pseudocode, not original source.
 * ev_07efd457ec9a37501bdb802bda98d4fdf679445de954c80baf7ce8f2bb24f771
 * Entry: 0x6d4880; label: FUN_006d4880
 */

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

