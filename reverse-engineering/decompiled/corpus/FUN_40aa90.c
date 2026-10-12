/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40aa90; label: FUN_0040aa90
 */

void FUN_0040aa90(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *unaff_ESI;
  
  unaff_ESI[2] = 0;
  unaff_ESI[1] = 0;
  *unaff_ESI = 0;
  iVar1 = 0;
  piVar2 = &DAT_0093d7f0;
  do {
    if ((*piVar2 != 0) && (((*(byte *)(*piVar2 + 0x1fc) & 0x80) != 0 || (DAT_00925398 != 0)))) {
      FUN_0040a570(param_1);
      FUN_005b37d0();
      iVar1 = iVar1 + 1;
    }
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x93d7f8);
  if (0 < iVar1) {
    FUN_005b3830();
  }
  return;
}

