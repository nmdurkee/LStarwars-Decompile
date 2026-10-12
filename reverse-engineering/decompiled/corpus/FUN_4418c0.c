/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x4418c0; label: FUN_004418c0
 */

undefined4 FUN_004418c0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_c [12];
  
  if (DAT_0292fc68 != 0) {
    iVar1 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),local_c,param_2,1);
    if (iVar1 != 0) {
      uVar2 = FUN_005cffb0(local_c);
      uVar2 = FUN_0067c760(uVar2);
      return uVar2;
    }
  }
  return 0xffffffff;
}

