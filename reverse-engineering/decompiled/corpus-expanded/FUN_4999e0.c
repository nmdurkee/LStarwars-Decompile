/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x4999e0; label: FUN_004999e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004999e0(int param_1,float param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_1 + 0x7b5);
  if (((cVar1 == '*') || (cVar1 == '6')) || (cVar1 == ':')) {
    param_2 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c);
    goto LAB_00499af7;
  }
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
    if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b1d4) &&
       (iVar2 = FUN_0054a240(param_1,*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),
                             *(undefined4 *)(PTR_DAT_00802c54 + 0x11c)), iVar2 != 0)) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
      param_2 = (param_2 - *(float *)(iVar2 + 0x10)) /
                (*(float *)(iVar2 + 0x1c) - *(float *)(iVar2 + 0x10));
      if (param_2 < 0.0) {
        param_2 = 0.0;
      }
      param_2 = (param_2 * 0.5 + 0.5) * *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c)
      ;
      goto LAB_00499af7;
    }
    if ((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) &&
        ((DAT_0087b8bc == 0 || (*(char *)(param_1 + 0xe3c) != '\0')))) &&
       ((*(uint *)(param_1 + 0xef4) & 0x2000000) == 0)) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
      if (param_2 < *(float *)(iVar2 + 0x10)) {
        param_2 = *(float *)(iVar2 + 0x10);
      }
      goto LAB_00499af7;
    }
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  param_2 = ((param_2 - *(float *)(iVar2 + 0x10)) /
            (*(float *)(iVar2 + 0x1c) - *(float *)(iVar2 + 0x10))) * *(float *)(iVar2 + 0x1c);
LAB_00499af7:
  if (0.0 <= param_2) {
    return (float10)(param_2 / *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c));
  }
  return (float10)(0.0 / *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c));
}

