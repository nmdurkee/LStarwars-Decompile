/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40f510; label: FUN_0040f510
 */

void FUN_0040f510(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *unaff_ESI;
  
  *param_1 = *unaff_ESI;
  param_1[1] = unaff_ESI[1];
  param_1[2] = unaff_ESI[2];
  param_1[3] = unaff_ESI[3];
  if (1 < param_2 + -1) {
    iVar1 = param_2 + -2;
    do {
      FUN_0040eff0();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  iVar1 = unaff_ESI[0x100];
  param_1 = param_1 + param_2 * 4 + -4;
  *param_1 = unaff_ESI[iVar1 * 4 + -4];
  param_1[1] = unaff_ESI[iVar1 * 4 + -3];
  param_1[2] = unaff_ESI[iVar1 * 4 + -2];
  param_1[3] = unaff_ESI[iVar1 * 4 + -1];
  return;
}

