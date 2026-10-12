/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59b6a0; label: FUN_0059b6a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0059b6a0(int param_1,uint param_2,uint param_3)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(byte *)(param_1 + 0x18) != 0) {
    psVar1 = (short *)(param_1 + 4);
    do {
      if ((*(ushort *)(*psVar1 * 0x9c + 0x7a + DAT_00951354) & param_2) == param_3) {
        return (uint)*(byte *)(*psVar1 * 0x9c + DAT_00951354 + 0x7c);
      }
      iVar2 = iVar2 + 1;
      psVar1 = psVar1 + 1;
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x18));
  }
  return 0xffffffff;
}

