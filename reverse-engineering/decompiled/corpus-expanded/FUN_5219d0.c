/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x5219d0; label: FUN_005219d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005219d0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *unaff_EDI;
  
  iVar2 = FUN_004f1440(DAT_009238e4 + 0x3cbd0);
  if (iVar2 != 0) {
    FUN_004f1410(DAT_009238e4 + 0x3cbd0,iVar2);
    FUN_004f1310(DAT_009238e4 + 0x3cbd8,iVar2);
    *(undefined4 *)(iVar2 + 0x18) = *unaff_EDI;
    *(undefined4 *)(iVar2 + 0x1c) = unaff_EDI[1];
    uVar1 = unaff_EDI[2];
    *(undefined4 *)(iVar2 + 0x24) = param_1;
    *(undefined4 *)(iVar2 + 0x20) = uVar1;
  }
  return iVar2;
}

