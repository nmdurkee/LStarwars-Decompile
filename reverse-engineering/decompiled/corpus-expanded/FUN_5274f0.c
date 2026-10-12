/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x5274f0; label: FUN_005274f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005274f0(void)

{
  int iVar1;
  undefined4 *unaff_EDI;
  
  iVar1 = FUN_004f1440(DAT_009238e4 + 0x4380c);
  if (iVar1 != 0) {
    FUN_004f1410(DAT_009238e4 + 0x4380c,iVar1);
    FUN_004f1310(DAT_009238e4 + 0x43814,iVar1);
    *(undefined4 *)(iVar1 + 8) = *unaff_EDI;
    *(undefined4 *)(iVar1 + 0xc) = unaff_EDI[1];
    *(undefined4 *)(iVar1 + 0x10) = unaff_EDI[2];
    if (*(int *)(DAT_009238e4 + 0x4381c) != 0) {
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x14);
      *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x18);
      *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x1c);
      *(undefined1 *)(iVar1 + 0x49) = *(undefined1 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x49);
      *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x40);
      *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x44);
      return iVar1;
    }
    *(undefined4 *)(iVar1 + 0x14) = 0x3e800000;
    *(float *)(iVar1 + 0x18) = -_DAT_00801c58;
    *(float *)(iVar1 + 0x1c) = _DAT_00801c58;
  }
  return iVar1;
}

