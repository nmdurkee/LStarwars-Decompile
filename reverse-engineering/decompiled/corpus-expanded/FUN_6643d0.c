/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x6643d0; label: FUN_006643d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006643d0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_029231a8;
  if (DAT_029231a8 != 0) {
    iVar2 = DAT_029231a8 * 0x58;
    if ((*(byte *)(param_2 + 0x11) & 1) == 0) {
      (&DAT_02924ba2)[iVar2] = (&DAT_02924ba2)[iVar2] & ~*(byte *)(param_2 + 0xc);
    }
    else {
      (&DAT_02924ba2)[iVar2] = (&DAT_02924ba2)[iVar2] | *(byte *)(param_2 + 0xc);
    }
    iVar1 = (&DAT_02924b60)[iVar1 * 0x16];
    if ((iVar1 != -1) && (iVar1 != 99999)) {
      *(undefined1 *)(iVar1 * 0x330 + 0x1da + DAT_029620a4) = (&DAT_02924ba2)[iVar2];
    }
  }
  return;
}

