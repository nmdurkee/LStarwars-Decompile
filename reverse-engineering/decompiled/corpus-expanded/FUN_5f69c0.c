/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f69c0; label: FUN_005f69c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005f69c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                    undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  float10 fVar1;
  
  if ((param_1 == 0) && (param_1 = DAT_009738b8, DAT_009738b8 == 0)) {
    return (float10)0;
  }
  fVar1 = (float10)FUN_005f6470(*(int *)(param_1 + 0x40) + 4,param_1,param_2,param_3,param_4,param_5
                                ,param_6,param_7,param_8,param_9,param_10,param_11);
  return fVar1;
}

