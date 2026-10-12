/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x496740; label: FUN_00496740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00496740(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (&DAT_0093d7f0)[iVar2];
    if (iVar1 == 0) {
      (&DAT_0087b6c4)[iVar2] = 0xffff;
      (&DAT_0087b6c8)[iVar2] = 0;
    }
    else {
      (&DAT_0087b6c4)[iVar2] = *(undefined2 *)(iVar1 + 0x1064);
      (&DAT_0087b6c8)[iVar2] = (byte)(*(uint *)(iVar1 + 0x1fc) >> 7) & 1;
    }
    (&DAT_0087b6ca)[iVar2] = 0;
    (&DAT_0087b6cc)[iVar2] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  return;
}

