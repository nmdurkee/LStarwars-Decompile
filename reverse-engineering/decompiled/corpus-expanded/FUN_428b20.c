/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x428b20; label: FUN_00428b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

