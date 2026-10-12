/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x638020; label: FUN_00638020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00638020(int param_1,float *param_2)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = -1;
  if (param_1 != 0) {
    pfVar2 = (float *)(param_1 + 0x4628);
    iVar4 = 2;
    do {
      if (((pfVar2[-4] != 0.0) &&
          ((param_2[2] - pfVar2[1]) * (param_2[2] - pfVar2[1]) +
           (*param_2 - pfVar2[-1]) * (*param_2 - pfVar2[-1]) +
           (param_2[1] - *pfVar2) * (param_2[1] - *pfVar2) < pfVar2[-2] * pfVar2[-2])) &&
         ((iVar3 == -1 || (pfVar2[-2] < *(float *)(iVar3 * 0x4c + 0x4620 + param_1))))) {
        iVar3 = iVar4 + -2;
      }
      if (((pfVar2[0xf] != 0.0) &&
          ((param_2[2] - pfVar2[0x14]) * (param_2[2] - pfVar2[0x14]) +
           (*param_2 - pfVar2[0x12]) * (*param_2 - pfVar2[0x12]) +
           (param_2[1] - pfVar2[0x13]) * (param_2[1] - pfVar2[0x13]) < pfVar2[0x11] * pfVar2[0x11]))
         && ((iVar3 == -1 || (pfVar2[0x11] < *(float *)(iVar3 * 0x4c + 0x4620 + param_1))))) {
        iVar3 = iVar4 + -1;
      }
      if (((pfVar2[0x22] != 0.0) &&
          ((param_2[2] - pfVar2[0x27]) * (param_2[2] - pfVar2[0x27]) +
           (*param_2 - pfVar2[0x25]) * (*param_2 - pfVar2[0x25]) +
           (param_2[1] - pfVar2[0x26]) * (param_2[1] - pfVar2[0x26]) < pfVar2[0x24] * pfVar2[0x24]))
         && ((iVar3 == -1 || (pfVar2[0x24] < *(float *)(iVar3 * 0x4c + 0x4620 + param_1))))) {
        iVar3 = iVar4;
      }
      if (((pfVar2[0x35] != 0.0) &&
          ((param_2[2] - pfVar2[0x3a]) * (param_2[2] - pfVar2[0x3a]) +
           (*param_2 - pfVar2[0x38]) * (*param_2 - pfVar2[0x38]) +
           (param_2[1] - pfVar2[0x39]) * (param_2[1] - pfVar2[0x39]) < pfVar2[0x37] * pfVar2[0x37]))
         && ((iVar3 == -1 || (pfVar2[0x37] < *(float *)(iVar3 * 0x4c + 0x4620 + param_1))))) {
        iVar3 = iVar4 + 1;
      }
      iVar1 = iVar4 + 2;
      pfVar2 = pfVar2 + 0x4c;
      iVar4 = iVar4 + 4;
    } while (iVar1 < 0x20);
    if (iVar3 != -1) {
      return iVar3 * 0x4c + 0x4604 + param_1;
    }
  }
  return 0;
}

