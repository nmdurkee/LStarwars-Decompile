/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f6420; label: FUN_005f6420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f6420(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    if (*(int *)(param_1 + 4) < 0x414e4935) {
      uVar1 = FUN_005f3140(param_2,&param_1);
    }
    else {
      uVar1 = FUN_004f4f40(param_1);
    }
    return uVar1;
  }
  return 0;
}

