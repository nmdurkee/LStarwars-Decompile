/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a42b0; label: FUN_004a42b0
 */

undefined4 FUN_004a42b0(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x790);
  if (((((iVar2 == 0) || (*(char *)(iVar2 + 0x7b5) != '\x1b')) ||
       ((char)*(uint *)(iVar2 + 0xe20) < '\0')) || ((*(uint *)(iVar2 + 0xe20) & 0x300) != 0)) ||
     ((*(float *)(param_1 + 0x68) == 0.0 && (*(float *)(param_1 + 0x70) == 0.0)))) {
    FUN_00499500(param_1,0);
  }
  else {
    sVar1 = FUN_005be2d0(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x70));
    *(short *)(param_1 + 0x5a) = sVar1 + -0x8000;
    if ((*(char *)(param_1 + 0x7b8) == '\x04') && (iVar2 = FUN_0056e160(0x13), iVar2 != 0)) {
      *(short *)(param_1 + 0x5a) = *(short *)(param_1 + 0x5a) + -0x8000;
      return 0;
    }
  }
  return 0;
}

