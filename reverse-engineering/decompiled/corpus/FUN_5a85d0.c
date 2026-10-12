/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a85d0; label: FUN_005a85d0
 */

void FUN_005a85d0(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((DAT_0095df24 != 0) && (iVar4 = 0, 0 < DAT_0095df28)) {
    iVar3 = 0;
    iVar2 = DAT_0095df24;
    do {
      uVar1 = FUN_005806f0(*(undefined4 *)(iVar3 + 4 + iVar2),param_1);
      iVar2 = DAT_0095df24;
      *(undefined1 *)(iVar3 + 9 + DAT_0095df24) = uVar1;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar4 < DAT_0095df28);
  }
  return;
}

