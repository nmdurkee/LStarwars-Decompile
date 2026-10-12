/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e2f80; label: FUN_004e2f80
 */

void FUN_004e2f80(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  short *psVar4;
  
  uVar3 = (uint)*(byte *)(*(int *)(param_1 + 300) + 0x7d);
  iVar1 = 0;
  if (uVar3 != 0) {
    psVar4 = (short *)(*(int *)(param_1 + 300) + 0x60);
    do {
      if (*psVar4 == *(short *)(DAT_0087b150 + 0x62)) {
        DAT_008895a4 = iVar1;
      }
      iVar1 = iVar1 + 1;
      psVar4 = psVar4 + 1;
    } while (iVar1 < (int)uVar3);
  }
  iVar1 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_008895b0,&DAT_0075ddc0,1);
  if (iVar1 != 0) {
    DAT_00889584 = FUN_005d0420(&DAT_008895b0);
    uVar2 = FUN_005cffb0(&DAT_008895b0);
    DAT_008894cc = FUN_0067c760(uVar2);
  }
  DAT_0087a96c = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f90d0,"panel1");
  DAT_008894c8 = FUN_00578750(0xc);
  return;
}

