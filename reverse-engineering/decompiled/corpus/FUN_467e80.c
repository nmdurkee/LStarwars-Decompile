/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x467e80; label: FUN_00467e80
 */

undefined4 FUN_00467e80(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int unaff_EDI;
  
  uVar1 = *(uint *)(unaff_EDI + 0xa0);
  if ((((uVar1 & 2) == 0) || ((uVar1 & 1) == 0)) || ((uVar1 & 0x10000) != 0)) {
    return 0;
  }
  uVar2 = *(uint *)(unaff_EDI + 0x74);
  if ((uVar2 & 0x100) == 0) {
    if ((uVar2 & 0x200) == 0) {
      return 0;
    }
    if (*(short *)(unaff_EDI + 0x88) != -1) {
      if ((uVar2 & 0x20) == 0) {
        FUN_0056a8c0(param_1,(int)*(short *)(unaff_EDI + 0x88),unaff_EDI + 0x1c);
      }
      else if (*(int *)(unaff_EDI + 0x28) != 0) {
        for (puVar3 = *(undefined4 **)(*(int *)(unaff_EDI + 0x28) + 0x18);
            puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
          iVar4 = FUN_005cf9e0(puVar3 + 1);
          if (iVar4 != 0) {
            FUN_0056a8c0(param_1,(int)*(short *)(unaff_EDI + 0x88),iVar4);
          }
        }
      }
    }
    FUN_005a11f0(*(undefined4 *)(unaff_EDI + 0x28));
    FUN_004671d0();
    FUN_005a15e0(*(undefined4 *)(unaff_EDI + 0x28),0);
    *(uint *)(unaff_EDI + 0xa0) = *(uint *)(unaff_EDI + 0xa0) | 0x10000;
    if ((param_2 != -1) && ((*(byte *)((&DAT_0093d7f0)[param_2] + 0x1fc) & 0x80) != 0)) {
      FUN_0054a8a0(**(undefined4 **)((&DAT_0093d7f0)[param_2] + 0xca4),0x3dcccccd,0);
      return 1;
    }
  }
  else {
    *(uint *)(unaff_EDI + 0xa0) = uVar1 | 0x8000;
    if ((param_2 != -1) && ((*(byte *)((&DAT_0093d7f0)[param_2] + 0x1fc) & 0x80) != 0)) {
      FUN_0054a8a0(**(undefined4 **)((&DAT_0093d7f0)[param_2] + 0xca4),0x3dcccccd,0);
    }
  }
  return 1;
}

