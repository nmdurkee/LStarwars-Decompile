/* Ghidra pseudocode, not original source.
 * ev_45200ba16e8ef520c819c849d12b8874968ca721432c6a61fa3b24bce95adf30
 * Entry: 0x696ae0; label: FUN_00696ae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00696ae0(FILE *param_1,long param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (param_1 == (FILE *)0x0) {
    return -1;
  }
  iVar1 = _fseek(param_1,param_2,param_4);
  return iVar1;
}

