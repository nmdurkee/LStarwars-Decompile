/* Ghidra pseudocode, not original source.
 * ev_ce5edc1561b77c28ba497ac7e0a731ad3290827c35b207bcfcd23dc4a7952c7a
 * Entry: 0x57adc0; label: FUN_0057adc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057adc0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f9e70(param_1);
  if (iVar1 < 0xff) {
    if (iVar1 < 0) {
      *(undefined1 *)(DAT_00951c4c + 0xef) = 0;
      return;
    }
  }
  else {
    iVar1 = 0xfe;
  }
  *(char *)(DAT_00951c4c + 0xef) = (char)iVar1;
  return;
}

