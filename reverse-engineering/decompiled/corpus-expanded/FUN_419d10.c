/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x419d10; label: FUN_00419d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00419d10(int param_1)

{
  int iVar1;
  int unaff_ESI;
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  if ((((*(char *)(unaff_ESI + 0x7b5) == ']') &&
       (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xf7e) != '\0')) &&
      (iVar1 = (int)*(char *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x108), iVar1 != -1)) &&
     (*(int *)(*(int *)(unaff_ESI + 0x50) + 0x14 + iVar1 * 4) != 0)) {
    FUN_005b4500(local_80,iVar1 * 0x40 + 0x834 + unaff_ESI);
    FUN_00552bc0(0,0xf7,local_80);
    if (param_1 != 0) {
      iVar1 = FUN_00550490(local_80,*(undefined1 *)(unaff_ESI + 0x107b),
                           *(undefined4 *)(unaff_ESI + 0x1014),
                           *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),local_40);
      if (iVar1 != 0) {
        FUN_005d4690(0);
        FUN_00552bc0(0,0xf7,local_40);
        FUN_005d46b0();
      }
    }
  }
  return;
}

