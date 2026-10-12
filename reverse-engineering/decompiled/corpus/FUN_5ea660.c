/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5ea660; label: FUN_005ea660
 */

void FUN_005ea660(int *param_1)

{
  int iVar1;
  
  if ((((param_1 != (int *)0x0) && (param_1[2] != 0)) && (*param_1 != 0)) &&
     ((iVar1 = *(int *)(*param_1 + 0x110), iVar1 != 0 && ((*(byte *)(iVar1 + 0x76) & 1) != 0)))) {
    *(uint *)(param_1[2] + 0xb8) = *(uint *)(param_1[2] + 0xb8) | 0x400;
    FUN_005df480();
    return;
  }
  return;
}

