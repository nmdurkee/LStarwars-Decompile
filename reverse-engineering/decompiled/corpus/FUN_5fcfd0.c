/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fcfd0; label: FUN_005fcfd0
 */

uint * FUN_005fcfd0(void)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  char *pcVar4;
  int iVar5;
  float *pfVar6;
  
  if (DAT_009738a4 != (byte *)0x0) {
    *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
    puVar3 = DAT_009736e0;
    puVar2 = (uint *)*DAT_009736e0;
    *puVar2 = (uint)*DAT_009738a4;
    *puVar3 = *puVar3 + 4;
    *(uint *)*puVar3 = (uint)DAT_009738a4[2];
    *puVar3 = *puVar3 + 4;
    pfVar6 = (float *)*puVar3;
    *puVar3 = (uint)(pfVar6 + ((int)(*DAT_009738a4 + 3) >> 2) * 4);
    pcVar4 = *(char **)(DAT_009738a4 + 4);
    iVar5 = 0;
    if (*DAT_009738a4 != 0) {
      do {
        cVar1 = *pcVar4;
        iVar5 = iVar5 + 1;
        pcVar4 = pcVar4 + 1;
        *pfVar6 = (float)(int)cVar1;
        pfVar6 = pfVar6 + 1;
      } while (iVar5 < (int)(uint)*DAT_009738a4);
    }
    return puVar2;
  }
  return (uint *)0x0;
}

