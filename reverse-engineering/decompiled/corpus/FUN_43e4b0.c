/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43e4b0; label: FUN_0043e4b0
 */

int FUN_0043e4b0(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_0093d500) {
    puVar1 = (uint *)(DAT_0093d504 + 0x1f8);
    iVar2 = DAT_0093d500;
    do {
      if (((((puVar1[1] & 1) != 0) && ((*puVar1 & 0x400) != 0)) && ((char)puVar1[0x82] != -1)) &&
         (((*(byte *)(*(int *)(puVar1[-0x69] + 0x24) + 0x90) & 0x40) == 0 &&
          ((short)puVar1[0x39b] != DAT_007f1a50)))) {
        iVar3 = iVar3 + (uint)*(ushort *)(*(int *)(puVar1[-0x69] + 0x24) + 0xee);
      }
      puVar1 = puVar1 + 0x436;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return iVar3;
}

