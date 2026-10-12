/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x5489b0; label: FUN_005489b0
 */

int FUN_005489b0(int param_1)

{
  short sVar1;
  int iVar2;
  
  if (param_1 != -1) {
    iVar2 = 0;
    sVar1 = *DAT_009248c0;
    while (sVar1 != -1) {
      if (sVar1 == param_1) {
        return (int)DAT_009248c0[iVar2 * 0xe + 1];
      }
      iVar2 = iVar2 + 1;
      sVar1 = DAT_009248c0[iVar2 * 0xe];
    }
  }
  return -1;
}

