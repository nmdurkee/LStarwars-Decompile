/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59b700; label: FUN_0059b700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0059b700(int param_1,uint *param_2)

{
  uint uVar1;
  short *psVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (DAT_0095136c == 0) {
    return false;
  }
  uVar1 = (uint)*(byte *)(param_1 + 0x19);
  if (uVar1 != 0) {
    psVar2 = (short *)(param_1 + 4);
    do {
      if (*(char *)(DAT_0095136c + 1 + *psVar2 * 0xc) != '\0') {
        uVar3 = uVar3 + 1;
      }
      psVar2 = psVar2 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar3;
  }
  return uVar3 == *(byte *)(param_1 + 0x19);
}

