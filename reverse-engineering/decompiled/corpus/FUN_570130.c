/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x570130; label: FUN_00570130
 */

int FUN_00570130(int param_1,uint param_2,float *param_3,float *param_4)

{
  byte bVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = **(int **)(param_1 + 0x50b8);
  if (iVar4 == 0) {
    return 0;
  }
  if (*(char *)(*(int *)PTR_PTR_008033b0 + 0xf + param_2 * 0x38) == '\0') {
    fVar3 = *(float *)(*(int *)PTR_PTR_008033b0 + param_2 * 0x38 + 0x30) * DAT_00950f60;
    iVar2 = (*(int **)(param_1 + 0x50b8))[2];
    iVar5 = 0;
    if (0 < iVar2) {
      do {
        if ((((((*(byte *)(iVar4 + 0x25) == param_2) &&
               (bVar1 = *(byte *)(iVar4 + 0x17), (bVar1 & 2) != 0)) && ((bVar1 & 4) != 0)) &&
             (((bVar1 & 8) == 0 && (*param_3 - fVar3 <= *(float *)(iVar4 + 8))))) &&
            ((*(float *)(iVar4 + 8) <= *param_4 + fVar3 &&
             ((param_3[2] - fVar3 <= *(float *)(iVar4 + 0x10) &&
              (*(float *)(iVar4 + 0x10) <= fVar3 + param_4[2])))))) &&
           ((param_3[1] - fVar3 <= *(float *)(iVar4 + 0xc) &&
            (*(float *)(iVar4 + 0xc) <= param_4[1] + fVar3)))) {
          return iVar4;
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x2c;
      } while (iVar5 < iVar2);
    }
  }
  return 0;
}

