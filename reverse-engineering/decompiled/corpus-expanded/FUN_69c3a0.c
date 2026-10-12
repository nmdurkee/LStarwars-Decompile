/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69c3a0; label: FUN_0069c3a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069c3a0(FILE *param_1,long param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (param_1 == (FILE *)0x0) {
    return -1;
  }
  iVar1 = _fseek(param_1,param_2,param_4);
  return iVar1;
}

