/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f2ee0; label: FUN_004f2ee0
 */

void FUN_004f2ee0(undefined2 *param_1,byte *param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = 0;
  *param_1 = 0;
  if (param_2 != (byte *)0x0) {
    bVar2 = *param_2;
    while (bVar2 != 0) {
      param_1[iVar3] = (ushort)bVar2;
      iVar1 = iVar3 + 1;
      iVar3 = iVar3 + 1;
      bVar2 = param_2[iVar1];
    }
    param_1[iVar3] = 0;
  }
  return;
}

