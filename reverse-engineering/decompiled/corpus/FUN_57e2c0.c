/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x57e2c0; label: FUN_0057e2c0
 */

void FUN_0057e2c0(void)

{
  undefined4 uVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  float10 extraout_ST0;
  
  if (((DAT_00951be8 != 0) && (psVar3 = *(short **)(DAT_00951be8 + 0x184), psVar3 != (short *)0x0))
     && (iVar4 = 0, iVar2 = DAT_00951be8, *(short *)(DAT_00951be8 + 0x188) != 0)) {
    do {
      if ((*(float *)(psVar3 + 4) < *(float *)(iVar2 + 0x58) !=
           (*(float *)(psVar3 + 4) == *(float *)(iVar2 + 0x58))) &&
         (*(float *)(iVar2 + 0x58) <= *(float *)(psVar3 + 6))) {
        uVar1 = FUN_006e6b90();
        FUN_0050d910(*(undefined4 *)(DAT_00926c20 + *psVar3 * 4),*(undefined4 *)(psVar3 + 8),
                     *(undefined4 *)(psVar3 + 10),(float)extraout_ST0,*(undefined4 *)(psVar3 + 0xc),
                     *(undefined4 *)(psVar3 + 0xe),(float)extraout_ST0,(char)psVar3[3],
                     (char)psVar3[1],*(undefined1 *)((int)psVar3 + 3),(char)psVar3[2],
                     *(undefined4 *)(psVar3 + 0x10),1,0,0,uVar1);
        iVar2 = DAT_00951be8;
      }
      iVar4 = iVar4 + 1;
      psVar3 = psVar3 + 0x14;
    } while (iVar4 < (int)(uint)*(ushort *)(iVar2 + 0x188));
  }
  return;
}

