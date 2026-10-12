/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x558670; label: FUN_00558670
 */

void FUN_00558670(int param_1,int *param_2)

{
  short *psVar1;
  int iVar2;
  
  if (param_2 != (int *)0x0) {
    iVar2 = 0;
    if ((short)param_2[2] != 0) {
      psVar1 = (short *)(*param_2 + 0x86);
      do {
        if ((((*(byte *)(psVar1 + 7) & 2) != 0) &&
            (((*psVar1 < 0 || (*(char *)((int)*psVar1 + *(int *)(param_1 + 0x2a94)) != '\0')) &&
             ((*(byte *)(psVar1 + 0xb) & 0x80) == 0)))) && ((*(byte *)(psVar1 + -0xf) & 0x40) != 0))
        {
          FUN_005a16b0(*(undefined4 *)(psVar1 + -0x29),2,*(undefined4 *)(psVar1 + -0x19),0);
        }
        iVar2 = iVar2 + 1;
        psVar1 = psVar1 + 0x50;
      } while (iVar2 < (int)(uint)*(ushort *)(param_2 + 2));
    }
  }
  return;
}

