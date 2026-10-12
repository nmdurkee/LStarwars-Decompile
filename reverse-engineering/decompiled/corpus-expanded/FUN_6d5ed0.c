/* Ghidra pseudocode, not original source.
 * ev_dee7aab1ca5e5354a0f869482cb8068c6ad6aaead7d7bdba3544004762b43fb7
 * Entry: 0x6d5ed0; label: FUN_006d5ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006d5ed0(int param_1)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar1 = 0;
  uVar2 = 0;
  pcVar3 = (char *)(DAT_02975144 + 0x67f0);
  do {
    if (((uVar2 < 0x20) && (*pcVar3 != '\0')) &&
       (*(char *)(DAT_02975144 + 0x6358 + (param_1 * 0x20 + uVar2) * 4) != '\0')) {
      uVar1 = uVar1 | 1 << ((byte)uVar2 & 0x1f);
    }
    uVar2 = uVar2 + 1;
    pcVar3 = pcVar3 + 6;
  } while ((int)uVar2 < 0x20);
  return uVar1;
}

