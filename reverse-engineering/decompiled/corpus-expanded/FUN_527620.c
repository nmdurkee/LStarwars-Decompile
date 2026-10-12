/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x527620; label: FUN_00527620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00527620(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c [2];
  undefined4 local_4;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0x3f800000;
  if ((*(byte *)(unaff_ESI + 0x48) & 0x80) == 0) {
    iVar2 = FUN_005cfac0(DAT_009238e4 + 0x3c);
    iVar1 = DAT_009238e4;
    if (iVar2 != 0) {
      *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(DAT_009238e4 + 0x3c);
      *(undefined4 *)(unaff_ESI + 0x24) = *(undefined4 *)(iVar1 + 0x40);
      *(undefined4 *)(unaff_ESI + 0x28) = *(undefined4 *)(iVar1 + 0x44);
      uVar3 = FUN_005d0330(DAT_009238e4 + 0x3c);
      FUN_005b33c0(unaff_ESI + 0x2c,unaff_ESI + 8,uVar3);
      FUN_005b3200(local_c,&local_18,uVar3);
      uVar3 = FUN_005be2d0(local_c[0],local_4);
      *(undefined4 *)(unaff_ESI + 0x38) = uVar3;
      uVar3 = FUN_005be5b0(*(undefined4 *)(unaff_ESI + 0x3c),uVar3);
      *(undefined4 *)(unaff_ESI + 0x38) = uVar3;
      return;
    }
  }
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  return;
}

