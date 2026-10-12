/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x59b6a0; label: FUN_0059b6a0
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

