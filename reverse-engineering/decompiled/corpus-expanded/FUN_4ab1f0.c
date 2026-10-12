/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4ab1f0; label: FUN_004ab1f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ab1f0(int param_1,float param_2,float param_3,int param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x280) != -1) {
    iVar3 = (int)*(char *)(param_1 + 0x671);
    *(undefined4 *)(param_1 + 0xc48) = 0;
    if ((iVar3 != -1) && (*(int *)(PTR_DAT_00802c54 + 0x2988) != 0)) {
      if ((param_4 != 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0)) {
        return;
      }
      iVar2 = DAT_0093d7f4;
      if (((((param_1 == DAT_0093d7f0) || (iVar2 = DAT_0093d7f0, param_1 == DAT_0093d7f4)) &&
           (iVar2 != 0)) &&
          (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0 || ((*(byte *)(iVar2 + 0x1fc) & 0x80) != 0))))
         && ((*(char *)(iVar2 + 0x671) == iVar3 &&
             ((param_4 == 0 || ((*(byte *)(iVar2 + 0x1fc) & 0x80) != 0)))))) {
        fVar1 = *(float *)(param_1 + 0x6a0) - *(float *)(iVar2 + 0x6a0);
        if (*(char *)(iVar3 * 0x13c + 0x33 + **(int **)(PTR_DAT_00802c54 + 0x2988)) != '\0') {
          if (0.5 <= fVar1) {
            fVar1 = fVar1 - 1.0;
          }
          else if (fVar1 <= -0.5) {
            fVar1 = fVar1 + 1.0;
          }
        }
        if ((fVar1 < 0.0) &&
           (*(float *)(param_1 + 0xc48) = -fVar1 / param_2, param_3 < -fVar1 / param_2)) {
          *(float *)(param_1 + 0xc48) = param_3;
          return;
        }
      }
      return;
    }
  }
  return;
}

