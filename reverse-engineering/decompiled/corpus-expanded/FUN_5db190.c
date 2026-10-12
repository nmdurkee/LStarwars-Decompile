/* Ghidra pseudocode, not original source.
 * ev_64ab134b4afd9c8d0a163dd8f67d256d98012891aab565beeb69ac94b847fa54
 * Entry: 0x5db190; label: FUN_005db190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005db190(float param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  
  fVar2 = ((float)DAT_0080e694 / (param_3 - param_1)) * (float)DAT_0080e694;
  fVar1 = ((float)DAT_0080e698 / (param_4 - param_2)) * (float)DAT_0080e698;
  FUN_005dac70(-param_1 * (fVar2 / (param_3 - param_1)) * 0.5,
               -param_2 * (fVar1 / (param_4 - param_2)) * 0.5);
  FUN_005dae80(fVar2,fVar1);
  return;
}

