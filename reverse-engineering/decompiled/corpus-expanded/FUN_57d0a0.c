/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57d0a0; label: FUN_0057d0a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057d0a0(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  
  if ((*(int *)(param_1 + 0x2ab0) != 0) && (0 < DAT_00951c78)) {
    FUN_00595660(*(undefined4 *)(param_1 + 0x2ab4),0x3f800000);
    if (DAT_00951be8 == 0) {
      iVar4 = *(int *)(param_1 + 0x128);
      bVar1 = *(byte *)(iVar4 + 0xc9);
      DAT_00951bf0 = *(undefined1 *)(iVar4 + 0xa1);
      bVar2 = *(byte *)(iVar4 + 0xcd);
      bVar3 = *(byte *)(iVar4 + 0xca);
    }
    else {
      bVar1 = *(byte *)(DAT_00951be8 + 0xf0);
      DAT_00951bf0 = *(undefined1 *)(DAT_00951be8 + 0xef);
      bVar2 = *(byte *)(DAT_00951be8 + 0xf2);
      bVar3 = *(byte *)(DAT_00951be8 + 0xf1);
    }
    _DAT_00951c6c = (float)bVar3;
    _DAT_00951c50 = (float)bVar1;
    _DAT_00951c04 = (float)bVar2;
    _DAT_00951c00 = _DAT_00951c04 * _DAT_00951c04;
    FUN_00508f10(DAT_0093b328);
    if ((DAT_00951c68 != 0) && (*(int *)(param_1 + 0x13c) != 0)) {
      FUN_00595660(*(undefined4 *)(param_1 + 0x2ab4),0x3f800000);
      FUN_00601df0(*(undefined4 *)(param_1 + 0x13c));
      if ((*(int *)(param_1 + 0x2ac8) != 0) &&
         ((DAT_00951be8 != 0 && ((*(uint *)(DAT_00951be8 + 0x50) & 0x8000) != 0)))) {
        FUN_00559d40(*(int *)(param_1 + 0x2ac8),param_1,_DAT_00925018);
      }
    }
  }
  return;
}

