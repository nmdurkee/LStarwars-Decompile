/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x5298c0; label: FUN_005298c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005298c0(undefined4 param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  
  if (param_2 != 0) {
    DAT_00921f34 = *(undefined4 *)(param_2 + 0xc);
  }
  iVar1 = *(int *)(DAT_009238e4 + 0x371b0);
  if ((iVar1 != 0) && (*(int *)(DAT_009238e4 + 0x371ac) == iVar1)) {
    *(undefined2 *)(iVar1 + 0x58) = (undefined2)DAT_00921f34;
    if (DAT_009238c8 == (code *)0x0) {
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x9c) = 0x3f800000;
    }
    else {
      fVar2 = (float10)(*DAT_009238c8)(DAT_00921f34);
      *(float *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x9c) = (float)fVar2;
    }
    if (DAT_009238cc == (code *)0x0) {
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa0) = 0x3f800000;
    }
    else {
      fVar2 = (float10)(*DAT_009238cc)(DAT_00921f34);
      *(float *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa0) = (float)fVar2;
    }
    if (DAT_009238d0 == (code *)0x0) {
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa4) = 0x3f800000;
    }
    else {
      fVar2 = (float10)(*DAT_009238d0)(DAT_00921f34);
      *(float *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa4) = (float)fVar2;
    }
    if (DAT_009238d4 != (code *)0x0) {
      fVar2 = (float10)(*DAT_009238d4)(DAT_00921f34);
      *(float *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa8) = (float)fVar2;
      return;
    }
    *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa8) = 0x3f800000;
  }
  return;
}

