/* Ghidra pseudocode, not original source.
 * ev_dee7aab1ca5e5354a0f869482cb8068c6ad6aaead7d7bdba3544004762b43fb7
 * Entry: 0x6d5e40; label: FUN_006d5e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d5e40(uint *param_1,uint *param_2,int param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint local_4;
  
  uVar2 = 0;
  local_4 = 0;
  uVar3 = 0;
  pbVar1 = (byte *)(DAT_02975144 + 0x67f1);
  do {
    if (uVar2 < 0x20) {
      if ((pbVar1[-1] != 0) &&
         (*(char *)(DAT_02975144 + 0x6358 + (param_3 * 0x20 + uVar2) * 4) != '\0')) {
        if (-1 < (char)pbVar1[1]) {
          local_4 = local_4 | 1 << (pbVar1[1] & 0x1f);
        }
        if (-1 < (char)*pbVar1) {
          uVar3 = uVar3 | 1 << (*pbVar1 & 0x1f);
        }
      }
    }
    uVar2 = uVar2 + 1;
    pbVar1 = pbVar1 + 6;
  } while ((int)uVar2 < 0x20);
  *param_1 = local_4;
  *param_2 = uVar3;
  return;
}

