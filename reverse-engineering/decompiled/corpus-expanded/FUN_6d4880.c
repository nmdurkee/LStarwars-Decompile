/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d4880; label: FUN_006d4880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

