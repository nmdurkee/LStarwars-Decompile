/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5afbb0; label: FUN_005afbb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005afbb0(int *param_1,undefined4 param_2,float *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_8;
  int local_4;
  
  local_8 = 1e+09;
  local_4 = 0;
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    iVar3 = 0;
    if (0 < param_1[1]) {
      do {
        if ((param_4 == 0) || ((*(byte *)(iVar2 + 0x23) & 4) == 0)) {
          fVar4 = (float10)FUN_005b3c50(param_2,iVar2 + 0x10,0);
          if ((float)fVar4 < local_8) {
            local_8 = (float)fVar4;
            local_4 = iVar2;
          }
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x34;
        iVar1 = local_4;
      } while (iVar3 < param_1[1]);
    }
  }
  if (param_3 != (float *)0x0) {
    *param_3 = local_8;
  }
  return iVar1;
}

