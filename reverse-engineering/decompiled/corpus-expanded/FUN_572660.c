/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x572660; label: FUN_00572660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00572660(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  
  if (*(float *)(param_1 + 0x21c) != 2e+06) {
    iVar2 = FUN_0055f450();
    if ((*(uint *)(*(int *)(iVar2 + 0x128) + 100) & 0x40000) != 0) {
      return 0;
    }
    if (param_2 == 2) {
      fVar1 = (*(float *)(param_1 + 0x17c) -
              *(float *)(param_1 + 0xff0) * *(float *)(param_1 + 0xa8)) + 0.1;
      *(float *)(param_1 + 0x60) = fVar1;
      *(float *)(param_1 + 0x9c) = fVar1;
      *(float *)(param_1 + 0x84) = fVar1;
    }
    else if (param_2 == 0) goto LAB_005726f9;
    if (*(float *)(param_1 + 0xff0) * *(float *)(param_1 + 0xa8) + *(float *)(param_1 + 0x60) <=
        *(float *)(param_1 + 0x21c) + 0.1) {
LAB_005726f9:
      fVar1 = (*(float *)(param_1 + 0x21c) -
              *(float *)(param_1 + 0xff0) * *(float *)(param_1 + 0xa8)) + 0.1;
      *(float *)(param_1 + 0x60) = fVar1;
      *(float *)(param_1 + 0x9c) = fVar1;
      *(float *)(param_1 + 0x84) = fVar1;
      *(undefined4 *)(param_1 + 0x6c) = 0xbf800000;
      return 1;
    }
    *(undefined4 *)(param_1 + 0x6c) = 0xbf800000;
  }
  return 0;
}

