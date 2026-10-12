/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x520a00; label: FUN_00520a00
 */

undefined4 FUN_00520a00(int *param_1,float *param_2)

{
  int iVar1;
  int in_ECX;
  int in_EDX;
  int *unaff_EDI;
  
  *unaff_EDI = (uint)*(byte *)(in_ECX + 0x10) * 0x5c + *(int *)(*(int *)(in_EDX + 0x158) + 0x7c);
  iVar1 = (uint)*(byte *)(in_ECX + 0x11) * 0x5c + *(int *)(*(int *)(in_EDX + 0x158) + 0x7c);
  *param_1 = iVar1;
  if ((*(float *)(iVar1 + 4) - *(float *)(*unaff_EDI + 4)) * *param_2 +
      (*(float *)(iVar1 + 0xc) - *(float *)(*unaff_EDI + 0xc)) * param_2[2] < 0.0) {
    *param_1 = (uint)*(byte *)(in_ECX + 0x10) * 0x5c + *(int *)(*(int *)(in_EDX + 0x158) + 0x7c);
    *unaff_EDI = (uint)*(byte *)(in_ECX + 0x11) * 0x5c + *(int *)(*(int *)(in_EDX + 0x158) + 0x7c);
    return 1;
  }
  return 0;
}

