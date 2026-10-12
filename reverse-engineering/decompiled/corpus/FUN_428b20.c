/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x428b20; label: FUN_00428b20
 */

void FUN_00428b20(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *unaff_ESI;
  
  iVar2 = FUN_004f4fd0();
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[4] = 10;
  unaff_ESI[3] = 10;
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 0;
  unaff_ESI[5] = 10;
  unaff_ESI[6] = 1;
  if ((iVar2 == 0) || (iVar2 == 3)) {
    unaff_ESI[0xb] = 0;
  }
  else {
    unaff_ESI[0xb] = 1;
  }
  unaff_ESI[0xc] = 10;
  uVar1 = FUN_006dd380(6);
  unaff_ESI[3] = uVar1;
  uVar1 = FUN_006dd380(5);
  unaff_ESI[4] = uVar1;
  return;
}

