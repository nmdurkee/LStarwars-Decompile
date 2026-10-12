/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69b220; label: FUN_0069b220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069b220(FILE *param_1,long param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (param_1 == (FILE *)0x0) {
    return -1;
  }
  iVar1 = _fseek(param_1,param_2,param_4);
  return iVar1;
}

