/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f2280; label: FUN_004f2280
 */

int FUN_004f2280(short *param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 != (short *)0x0) {
    do {
      *param_1 = *param_2;
      sVar1 = *param_2;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 1;
    } while (sVar1 != 0);
    return iVar2;
  }
  *param_1 = 0;
  return iVar2;
}

