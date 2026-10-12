/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a85d0; label: FUN_005a85d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

