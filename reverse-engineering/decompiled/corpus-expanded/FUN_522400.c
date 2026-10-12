/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x522400; label: FUN_00522400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00522400(undefined4 param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  
  if (*(int *)(DAT_009238e4 + 0x41208) != 0) {
    pcVar2 = (char *)(param_2 + 0x4c);
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (pcVar2 != (char *)(param_2 + 0x4d)) {
      FUN_004f1f40(DAT_009238e4 + 0x411e8,(char *)(param_2 + 0x4c),0x10);
    }
  }
  return;
}

