/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x745f30; label: FUN_00745f30
 */

void FUN_00745f30(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = in_ECX + 1;
  *in_ECX = &PTR_LAB_007e9340;
  iVar1 = 399;
  do {
    FUN_00743c50(puVar2);
    puVar2 = puVar2 + 0x136;
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  in_ECX[0x1e462] = 0;
  in_ECX[0x1e461] = 0xffffffff;
  in_ECX[2] = in_ECX[2] + 1;
  return;
}

